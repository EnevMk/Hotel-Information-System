#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "foos.h"
#include "Hotel.hpp"
#include "HotelStay.hpp"
#include "CheckIn.hpp"
#include "Room.hpp"
#include "BookingPeriod.hpp"
#include "Tuple.hpp"

class UI {
    
    
    std::ofstream database;
    
    
public:
    Hotel hotel;
    
    UI();
    void CommandListener();
    void Checkin();
    void Report();
    std::vector<const Room*> Availability();
    friend std::istream& operator>>(std::istream &is, UI &obj);
    const Room* findBeds(size_t beds, bookingPeriod bp);
    void UrgentBedFinder(size_t beds, bookingPeriod bp, std::vector<Tuple<HotelStay, size_t>> &roomSwaps, const HotelStay &obj);
    std::vector<Tuple<HotelStay, size_t>> urgentFind(size_t beds, bookingPeriod bp);
    //void moveHotelstayToRoom(Room *current, const HotelStay *ptr, Room *newr);
};

#endif