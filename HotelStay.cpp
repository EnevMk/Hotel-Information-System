#include "HotelStay.hpp"

/* std::istream& operator>>(std::istream &is, HotelStay &obj) {

} */

HotelStay::HotelStay() {}

HotelStay& HotelStay::operator=(const CheckIn &obj) {
    this->bp = obj.getBookingPeriod();
    this->note = obj.getNote();
    this->peopleCount = obj.getGuestsCount();
    this->roomNumber = obj.getRoomNum();

    return *this;
}

HotelStay& HotelStay::operator=(const HotelStay &obj) {
    if (this != &obj) {
        this->bp = obj.bp;
        this->note = obj.note;
        this->peopleCount = obj.peopleCount;
        this->roomNumber = obj.roomNumber;
    }
    return *this;
}

bookingPeriod HotelStay::getBookingPeriod() const {
    return this->bp;
}

size_t HotelStay::getRoomNumber() const {
    return this->roomNumber;
}
size_t HotelStay::getGuestsCount() const {
    return this->peopleCount;
}

void HotelStay::setRoomNum(size_t n) {
    this->roomNumber = n;
}

std::string HotelStay::getNote() const {
    return this->note;
}

void HotelStay::loadStayFromStream(size_t roomNumber_, bookingPeriod bp_, const std::string &note_, size_t peoplecount_) {
    this->roomNumber = roomNumber_;
    this->bp = bp_;
    this->note = note_;
    this->peopleCount = peoplecount_;
}

bool HotelStay::operator==(const HotelStay &obj) const {
    return (this->bp == obj.bp && this->note == obj.note && this->peopleCount == obj.peopleCount && this->roomNumber == obj.roomNumber);
}

std::ostream& operator<<(std::ostream &os, const HotelStay &obj) {
    os << '|' << obj.bp << " [" << obj.note << ' ' << obj.peopleCount << ']' << '|';
    return os;
}

std::istream& operator>>(std::istream &is, HotelStay &obj) {
    //bp , peoplecutn, note
    is >> obj.bp;
    char cc;
    is >> cc;
    //std::cout << obj.bp << '\n';
    
    is >> obj.note;
    is >> obj.peopleCount;
    is >> cc;


    return is;
}