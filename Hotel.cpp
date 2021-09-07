#include "Hotel.hpp"

const std::vector<Room*>& Hotel::getVectorOfRooms() const {
    return this->rooms;
}

const Room& Hotel::getRoomByNum(size_t num) const {

    for (int i = 0; i < rooms.size(); ++i) {
        if (rooms[i]->getRoomNumber() == num) return *rooms[i];
    }

    throw "Room not found";
}

bool Hotel::reserveRoom(size_t roomNum, /* bookingPeriod bp, */ HotelStay hs) {

    for (int i = 0; i < rooms.size(); ++i) {

        if (rooms[i]->getRoomNumber() == roomNum) 
        {
            rooms[i]->reserve(hs);
            return true;
        }
    }
    return false;
}

bool Hotel::addRoom(Room *obj) {
    rooms.push_back(obj);
    return true;
}

/* const Room* Hotel::getRoomByNum(size_t roomNum) const {

    for (Room r : this->rooms) {

        if (r.getRoomNumber() == roomNum) return &r;
    }

    return nullptr;
} */

size_t Hotel::getBedsByRoomNum(size_t num_) const {

    for (Room *r : this->rooms) {

        if (r->getRoomNumber() == num_) return r->getBedCount();
    }
    return 0;
}

std::ostream& operator<<(std::ostream &os, const Hotel &obj) {

    os << obj.rooms.size() << '\n';

    for (Room *r : obj.rooms) {
        os << *r;
    }

    return os;
}

std::istream& operator>>(std::istream& is, Hotel &obj) {
    int roomsCount;
    is >> roomsCount;

    obj.rooms.resize(roomsCount);



    for (int i = 0; i < roomsCount; ++i) {

        obj.rooms[i] = new Room;
        is >> *(obj.rooms[i]);
        is.ignore(1024, '\n');
    }

    return is;
}

Hotel::~Hotel() {
    for (Room *r : this->rooms) {
        delete r;
    }
}