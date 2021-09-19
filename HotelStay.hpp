#ifndef HOTELSTAY_HPP
#define HOTELSTAY_HPP

#include <iostream>
#include <string>

#include "BookingPeriod.hpp"
#include "CheckIn.hpp"

class HotelStay {

private:
    size_t roomNumber;
    size_t peopleCount;
    bookingPeriod bp;
    std::string note;
    
public:

    HotelStay();
    HotelStay(size_t roomNumber_, size_t peopleCount_, bookingPeriod bp_, const std::string &note_) 
    : roomNumber(roomNumber_), peopleCount(peopleCount_), bp(bp_), note(note_) {}

    HotelStay& operator=(const CheckIn &obj);

    bookingPeriod getBookingPeriod() const;
    size_t getRoomNumber() const;
    size_t getGuestsCount() const;
    std::string getNote() const;

    void setRoomNum(size_t n);
    
    HotelStay& operator=(const HotelStay &obj);

    bool operator==(const HotelStay &obj) const;

    friend std::istream& operator>>(std::istream &is, HotelStay &obj);
    void loadStayFromStream(size_t roomNumber_, bookingPeriod bp_, const std::string &note_, HotelStay &obj);
    void loadStayFromStream(size_t roomNumber_, bookingPeriod bp_, const std::string &note_, size_t peoplecount_);
    friend std::ostream& operator<<(std::ostream &os, const HotelStay &obj);
    friend std::istream& operator>>(std::istream &is, HotelStay &obj);
};

#endif