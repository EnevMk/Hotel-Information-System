#include <iomanip>      // std::put_time
#include <ctime>        // std::time_t, struct std::tm, std::localtime
#include <chrono>

#include "UI.hpp"

//#include "CheckIn.hpp"
//#include "Hotel.hpp"
//#include "foos.cpp"


UI::UI() {
    //CommandListener();
}

std::istream& operator>>(std::istream &is, UI &obj) {
    is >> obj.hotel;
    return is;
}

void UI::CommandListener() {

    std::string cmd;

    while(cmd != "exit") {

        std::cin >> cmd;

        if (cmd == "checkin") {
            Checkin();
        }
        
        else if (cmd == "availability") {
            std::vector<const Room*> freeRooms = Availability();
            std::cout<< "free rooms:\n";
            for (const Room *r : freeRooms) {
                std::cout << "Room " << r->getRoomNumber() << " with " << r->getBedCount() << " beds.\n";
            }
        }

        else if (cmd == "report") {
            Report();
        }

        else if (cmd == "find") {
            size_t beds;
            bookingPeriod bp;

            std::cin >> beds >> bp;
            const Room* ptr = findBeds(beds, bp);

            if (ptr != nullptr) std::cout << "Room " << ptr->getRoomNumber() << " with " << ptr->getBedCount() << " is available.\n";
            else {
                std::cout << "No suitable Room found\n\n";
            }
        }

        else if (cmd == "find!") {

            size_t beds;
            bookingPeriod bp;

            std::cin >> beds >> bp;

            std::vector<Tuple<HotelStay, size_t>> rp = urgentFind(beds, bp);
            //std::cout << rp.size();
            /* for (Tuple<HotelStay, size_t> t : rp) {

                std::cout << "\nGuests from room " << t.getData1().getRoomNumber() << " with booking period "
                          << t.getData1().getBookingPeriod() << " may be moved to room" << t.getData2() << '\n';
            } */

            for (int i = 0 ; i < rp.size(); ++i) {

                std::cout << "\nGuests from room " << rp[i].getData1().getRoomNumber() /* t.getData1().getNote() */ << " with booking period "
                          << rp[i].getData1().getBookingPeriod() << " may be moved to room" << rp[i].getData2() << '\n';
            }
        }
    }
}



void UI::UrgentBedFinder(size_t beds, bookingPeriod bp, std::vector<Tuple<HotelStay, size_t>> &roomSwaps, const HotelStay &obj) {
    //std::cout << roomSwaps.size() << '\n';
    if (roomSwaps.size() > 3) throw "Accomodation not possible";

    const Room *suitableRoom = nullptr;
    std::vector<HotelStay> hss;

    for (Room *r : this->hotel.getVectorOfRooms()) {
        
        int bedCount = r->getBedCount();
        if (bedCount >= beds) {

            size_t numberOfBookings = r->getCountOfOverlappingPeriods(bp);
            if (numberOfBookings > 2) continue;

            if (suitableRoom == nullptr || bedCount < suitableRoom->getBedCount()) {

                bool freeBeds = true;
                std::vector<HotelStay> tempHss = r->getOverlappingStays(bp);

                for (int i = 0; i < numberOfBookings; ++i) {
                    
                    if (tempHss[i].getGuestsCount() == bedCount) freeBeds = false;
                }

                if (freeBeds) {
                    hss = tempHss;
                    suitableRoom = r;
                    //std::cout << "namerena\n";
                }
            }
        }
    }
    //obj.setRoomNum(suitableRoom->getRoomNumber());
    roomSwaps.push_back(Tuple<HotelStay, size_t>(obj, suitableRoom->getRoomNumber()));

    
    for (int i = 0; i < hss.size(); ++i) {
        //std::cout << hss[i].getRoomNumber() << '\n';
        UrgentBedFinder(hss[i].getGuestsCount(), hss[i].getBookingPeriod(), roomSwaps, hss[i]);
    }   

    /* if (hss.size() == 0) {
        //std::cout << "goto";
    } */

}

std::vector<Tuple<HotelStay, size_t>> UI::urgentFind(size_t beds, bookingPeriod bp) {

    //CATCH !!!

    HotelStay urgent(0, beds, bp, "urgent accomodation");
    std::vector<Tuple<HotelStay, size_t>> replacements;

    try {
        UrgentBedFinder(beds, bp, replacements, urgent);
    }
    catch (const char *s) {
        std::cout << s << '\n';
    }
    
    
    return replacements;

}

const Room* UI::findBeds(size_t beds, bookingPeriod bp) {

    const Room* suitableRoom = nullptr;
    
    for (Room *r : this->hotel.getVectorOfRooms()) {
        
        
        if (r->getBedCount() >= beds && r->isFree(bp)) {

            if (suitableRoom == nullptr || r->getBedCount() < suitableRoom->getBedCount()) {
                suitableRoom = r;
            }
        }
    }

    return suitableRoom;
}

void UI::Report() {
    bookingPeriod period;
    std::cin >> period;
    std::vector<const Room*> rs;

    for (Room *r : this->hotel.getVectorOfRooms()) {

        for (HotelStay hs : r->getStaysVector()) {

            if (hs.getBookingPeriod().overlap(period)) {
                rs.push_back(r);
                break;
            }
        }
    }
    
    for (const Room *r : rs) {
        size_t days = 0;
        for (HotelStay hs : r->getStaysVector()) {
            days += period.getDaysOfIntersectionWith(hs.getBookingPeriod());
        }

        std::tm in = period.getCheckinDate(), out = period.getCheckoutDate();

        std::cout << "In the period " << std::put_time(&in,"%Y-%m-%d") << '/' 
                  << std::put_time(&out,"%Y-%m-%d");
        std::cout << "\nRoom " << r->getRoomNumber() << " was used for " << days << " days.\n";

    }
}

std::vector<const Room*> UI::Availability() {
    std::string dateStr;
    std::getline(std::cin, dateStr);
    removeSpacesAtBegin(dateStr);
    std::vector<int> splitDatesToInt = DatesDeserialization(dateStr);


    std::tm date{0};
    
    if (dateStr.empty()) {
        
        std::time_t tt = std::chrono::system_clock::to_time_t (std::chrono::system_clock::now());
        date = *std::localtime(&tt);
    }
    else {
        date.tm_year = splitDatesToInt[0] - 1900;
        date.tm_mon = splitDatesToInt[1] - 1;
        date.tm_mday = splitDatesToInt[2];
    }

    std::vector<const Room*> freeRooms;

    std::tm date2 = date;
    date2.tm_mday += 1;
    date2.tm_hour = 11;
    date2.tm_min = 0;

    for (Room* r : this->hotel.getVectorOfRooms()) {
        
        if (r->isFree(bookingPeriod(date, date2))) {
            freeRooms.push_back(r);
        }
    }

    return freeRooms;
}

void UI::Checkin() {
    CheckIn command;
    std::cin >> command;

    if (!command.getGuestsCount()) {
        command.setGuestsCount(hotel.getBedsByRoomNum(command.getRoomNum()));
    }

    HotelStay hs;
    hs = command;

    bool freeRoom;
    size_t roomNum = command.getRoomNum();
    bookingPeriod bp = command.getBookingPeriod();

    try {
        freeRoom = hotel.getRoomByNum(roomNum).isFree(bp);
    }
    catch (char const* s) {
        std::cout << "Error message: " << s << '\n';
        return;
    }

    if(freeRoom) {
        hotel.reserveRoom(roomNum, hs);
    }
    else {
        std::cout << "The room is not available at that period\n";
        return;
    }

    database.open("Hotel.fmi");
    database << hotel;
    database.close();
}