#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <fstream>
#include <iostream>

#include "BookingPeriod.hpp"
#include "foos.h"

class Command {

protected:
    std::string label;

public:
    virtual bool execute() = 0;
};

#endif