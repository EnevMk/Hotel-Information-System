#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <vector>
#include <exception>

#include "Room.hpp"

class Hotel {
private:
    std::vector<Room*> rooms;

public:
    const std::vector<Room*>& getVectorOfRooms() const;
    const Room& getRoomByNum(size_t num) const;
    bool reserveRoom(size_t roomNum, /* bookingPeriod bp,  */HotelStay hs);
    bool addRoom(Room *obj);
    //const Room* getRoomByNum(size_t roomNum) const;
    size_t getBedsByRoomNum(size_t num_) const;
    friend std::ostream& operator<<(std::ostream& os, const Hotel &obj);
    friend std::istream& operator>>(std::istream& is, Hotel &obj);
    ~Hotel();
};

#endif