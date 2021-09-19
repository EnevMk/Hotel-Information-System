#include "CheckIn.hpp"


size_t CheckIn::getRoomNum() const {
    return this->roomNum;
}
bookingPeriod CheckIn::getBookingPeriod() const {
    return this->bookp;
}
const std::string& CheckIn::getNote() const {
    return this->note;
}
size_t CheckIn::getGuestsCount() const {
    return this->guestsCount;
}

void CheckIn::setGuestsCount(const size_t n) {
    this->guestsCount = n;
}

std::istream& operator>>(std::istream &is, CheckIn &obj) {
    is >> obj.roomNum;
    is >> obj.bookp;

    is.ignore(1, '\n');
    is.clear();

    std::string remainingArgs;
    std::getline(is, remainingArgs);
    std::vector<std::string> args = splitCommandArgs(remainingArgs);

    bool countOfGuestsEntered = 0;
    int argsSize = args.size();
    
    if (args[argsSize - 1].size() == 1 && isdigit(args[argsSize - 1][0]))  {

        countOfGuestsEntered = 1;
        obj.guestsCount = stringToInt(args[argsSize - 1]);
    }
    else {
        obj.guestsCount = 0;
    }

    for (int i = 0; i < argsSize - countOfGuestsEntered; ++i) {
        obj.note += ' ' + args[i];
    }

    return is;

}