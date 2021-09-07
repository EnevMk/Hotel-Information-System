#ifndef CHECKIN_HPP
#define CHECKIN_HPP

#include "Command.hpp"

class CheckIn : public Command {

private:
    size_t roomNum;
    bookingPeriod bookp;
    std::string note;
    size_t guestsCount;

public:

    size_t getRoomNum() const;
    bookingPeriod getBookingPeriod() const;
    const std::string& getNote() const;
    size_t getGuestsCount() const;

    void setGuestsCount(const size_t n);

    bool execute() {

        return true;
    }
    
    bool execute(size_t room_, size_t year1, size_t month1, size_t day1, size_t year2, size_t month2, size_t day2,
                 const std::string &note_)
        {
            return true;
        }

    friend std::istream& operator>>(std::istream &is, CheckIn &obj);
};

#endif