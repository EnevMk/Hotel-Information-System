#include "Room.hpp"

Room::Room() {}

Room::Room(size_t beds, size_t roomNum) : bedCount(beds), number(roomNum) {}

void Room::reserve(/* bookingPeriod bp */ HotelStay hs) {
    this->stays.push_back(hs);
}

size_t Room::getRoomNumber() const {

    return number;
}
size_t Room::getBedCount() const {
    return this->bedCount;
}
const std::vector<HotelStay>& Room::getStaysVector() const {
    return this->stays;
}

std::vector<HotelStay>& Room::getStaysVector() {
    return this->stays;
}

void Room::moveHotelstayToRoom(const HotelStay *ptr, Room *r) {
    bool roomFound = false;
    int index = -1;
    std::vector<HotelStay>::iterator it = this->getStaysVector().begin();
    
    for (HotelStay h : this->getStaysVector()) {
        index++;
        if (h == *ptr) {
            roomFound = true;
            this->getStaysVector().erase(it + index);
        }
    }

    if (!roomFound) throw "Room not found";

    r->reserve(*ptr);
}

size_t Room::getCountOfOverlappingPeriods(const bookingPeriod &bp) const {
    size_t count = 0;
    for (HotelStay h : this->stays) {
        
        if (h.getBookingPeriod().overlap(bp)) count++;
    }
    return count;
}

std::vector<HotelStay> Room::getOverlappingStays(const bookingPeriod &bp) const {

    std::vector<HotelStay> hss;

    for (const HotelStay &h : this->stays) {
        
        if (h.getBookingPeriod().overlap(bp)) {
            hss.push_back(h);
            
        }
    }

    return hss;
}

bool Room::isFree(const bookingPeriod &p) const {
    //std::cout << bookedDates.size();
    for (HotelStay hs : this->stays) {
        
        if (p.overlap(hs.getBookingPeriod())) 
        {
            return false;
        }
    }

    return true;
}

std::ostream& operator<< (std::ostream &os, const Room &obj) {
    os << obj.number << ' ' << obj.bedCount << ' ' << obj.stays.size() << ' ';

    for (HotelStay hs : obj.stays) {
        os << hs << ' ';
    }
    os << '\n';
    return os;
}

std::istream& operator>>(std::istream &is, Room &obj) {

    is >> obj.number >> obj.bedCount;

    int staysCount;
    is >> staysCount;
    obj.stays.resize(staysCount);

    for (HotelStay &hs : obj.stays) {
        hs.setRoomNum(obj.number);
    }

    char cc;
    //is >> cc;
    //std::cout << cc << '\n';

    for (int i = 0; i < staysCount; ++i) {
        is >> cc;
        is >> obj.stays[i];
        is >> cc;
    }
    
    
    //is >> cc;

    return is;
}