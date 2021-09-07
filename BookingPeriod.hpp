#ifndef BOOKINGPERIOD_HPP
#define BOOKINGPERIOD_HPP

#include <iomanip>      // std::put_time
#include <ctime>
#include <iostream>
#include <vector>

#include "foos.h"

class bookingPeriod {

private:
    std::tm checkIn{0};
    std::tm checkOut{0};

public:
    bookingPeriod();
    bookingPeriod(const std::tm &checkin, const std::tm &checkout);
    bookingPeriod(const std::string &arrival, const std::string &dep);
    bookingPeriod(size_t year1, size_t month1, size_t day1,
                    size_t year2, size_t month2, size_t day2);

    int getDaysOfIntersectionWith(const bookingPeriod &bp);
    time_t getCheckinEpoch() const;
    time_t getCheckoutEpoch() const;
                    

    std::tm getCheckinDate() const;
    std::tm getCheckoutDate() const;
    bool overlap(const bookingPeriod &other) const;
    size_t getPeriodDuration() const;
    
    friend std::ostream& operator<<(std::ostream &os, const bookingPeriod &obj);
    friend std::istream& operator>>(std::istream &is, bookingPeriod &obj);
};

#endif