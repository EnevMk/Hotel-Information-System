#include "BookingPeriod.hpp"


bookingPeriod::bookingPeriod() : checkIn{0}, checkOut{0} {};

bookingPeriod::bookingPeriod(const std::tm &checkin, const std::tm &checkout) {
    this->checkIn = checkin;
    this->checkOut = checkout;
}

bookingPeriod::bookingPeriod(size_t year1, size_t month1, size_t day1, 
                                 size_t year2, size_t month2, size_t day2) 
                                 
{
    checkIn.tm_mday = day1;
    checkIn.tm_mon = month1 - 1;
    checkIn.tm_year = year1 - 1900;
    checkIn.tm_hour = 13;
    checkIn.tm_min = 0;

    checkOut.tm_mday = day2;
    checkOut.tm_mon = month2 - 1;
    checkOut.tm_year = year2 - 1900;
    checkOut.tm_hour = 11;
    checkOut.tm_min = 0;


}

std::tm bookingPeriod::getCheckinDate() const {
    return checkIn;
}

std::tm bookingPeriod::getCheckoutDate() const {
    return checkOut;
}

time_t bookingPeriod::getCheckinEpoch() const {
    std::tm t = this->checkIn;
    return mktime(&t);
}

time_t bookingPeriod::getCheckoutEpoch() const {
    std::tm t = this->checkOut;
    return mktime(&t);
}

bool bookingPeriod::overlap(const bookingPeriod &other) const {

    std::tm thisCheckin = this->getCheckinDate(), thisCheckout = this->getCheckoutDate();

    std::tm otherCheckin = other.getCheckinDate(), otherCheckout = other.getCheckoutDate();

    time_t thisEpochCheckin = mktime(&thisCheckin);
    time_t thisEpochCheckout = mktime(&thisCheckout);
    time_t otherEpochCheckin = mktime(&otherCheckin);
    time_t otherEpochCheckout = mktime(&otherCheckout);

    //std::cout << thisEpochCheckin << '\n' << otherEpochCheckin << '\n' << otherEpochCheckout << '\n';

    if (thisEpochCheckin >= otherEpochCheckin && thisEpochCheckin < otherEpochCheckout) {
        return true;
    }
    
    else if (thisEpochCheckout > otherEpochCheckin && thisEpochCheckout <= otherEpochCheckout) {
        return true;
    }

    else if (thisEpochCheckin <= otherEpochCheckin && thisEpochCheckout >= otherEpochCheckout) {
        return true;
    }

    return false;
}

size_t bookingPeriod::getPeriodDuration() const {
    int days = checkOut.tm_mday - checkIn.tm_mday;
    if (days < 0) {
        if (checkIn.tm_mon == 0 || checkIn.tm_mon == 2 || checkIn.tm_mon == 4 || checkIn.tm_mon == 6 || checkIn.tm_mon == 8 || checkIn.tm_mon == 10) {
            days += 32;
        }
        else if (checkIn.tm_mon == 3 || checkIn.tm_mon == 5 || checkIn.tm_mon == 7 || checkIn.tm_mon == 9 || checkIn.tm_mon == 11) {
            days += 31;
        }
        else if (checkIn.tm_mon == 1) {
            if ((checkIn.tm_year % 4 == 0 && checkIn.tm_year % 100 != 0) || checkIn.tm_year % 400 == 0) {
                days += 30;
            }
            else {
                days += 29;
            }
        }
    }

    return days;
}

int bookingPeriod::getDaysOfIntersectionWith(const bookingPeriod &bp) {
    int days = 0;

    if (this->overlap(bp)) {
        std::tm firstOverlapDay, lastOverlapDay;

        if (this->getCheckinEpoch() >= bp.getCheckinEpoch()) firstOverlapDay = this->checkIn;
        else {
            firstOverlapDay = bp.checkIn;
        }

        if (this->getCheckoutEpoch() <= bp.getCheckoutEpoch()) lastOverlapDay = this->checkOut;
        else {
            lastOverlapDay = bp.checkOut;
        }
        bookingPeriod overlap(firstOverlapDay, lastOverlapDay);
        days = overlap.getPeriodDuration();
    }
    return days;
}

std::ostream& operator<<(std::ostream &os, const bookingPeriod &obj) {
    os << std::put_time(&obj.checkIn,"%Y-%m-%d") << '/' << std::put_time(&obj.checkOut,"%Y-%m-%d");

    return os;
}

std::istream& operator>>(std::istream &is, bookingPeriod &obj) {

    std::string period;
    is >> period;

    std::vector<int> nums = DatesDeserialization(period);

    obj.checkIn.tm_year = nums[0] - 1900;
    obj.checkIn.tm_mon = nums[1] - 1;
    obj.checkIn.tm_mday = nums[2];

    obj.checkOut.tm_year = nums[3] - 1900;
    obj.checkOut.tm_mon = nums[4] - 1;
    obj.checkOut.tm_mday = nums[5];

    obj.checkIn.tm_hour = 13;
    obj.checkIn.tm_sec = 0;

    obj.checkOut.tm_hour = 11;
    obj.checkOut.tm_sec = 0;

    return is;
}