#ifndef ROOM_HPP
#define ROOM_HPP

#include <vector>
#include <iomanip>      // std::put_time
#include <ctime>
#include <iostream>

#include "BookingPeriod.hpp"
#include "HotelStay.hpp"

class Room {

private:
    unsigned int number;
    unsigned int bedCount;
    std::vector<bookingPeriod> bookedDates;
    std::vector<HotelStay> stays;

public:

    Room();
    bool isFree(const bookingPeriod &p) const;
    Room(size_t beds, size_t roomNum);

    size_t getRoomNumber() const;
    size_t getBedCount() const;
    const std::vector<HotelStay>& getStaysVector() const;
    
    void reserve(/* bookingPeriod bp */ HotelStay hs);
    friend std::ostream& operator<<(std::ostream &os, const Room &obj);
    friend std::istream& operator>>(std::istream &is, Room &obj);
};

#endif