#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "foos.h"
#include "Hotel.hpp"
#include "HotelStay.hpp"
#include "Command.hpp"
#include "CheckIn.hpp"

class UI {
    
    std::vector<Command*> commands;
    std::ofstream database;
    Hotel hotel;
    
public:
    
    
    UI();
    void CommandListener();
    void Checkin();
    void Report();
    std::vector<const Room*> Availability();
    friend std::istream& operator>>(std::istream &is, UI &obj);
    
};

#endif