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