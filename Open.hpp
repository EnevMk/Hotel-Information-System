#ifndef OPEN_HPP
#define OPEN_HPP

#include <fstream>
#include "Command.hpp"

class Open : public Command {

private:
    std::string argument;

public:
    Open(const std::string &arg) : argument(arg) {}

    bool execute() {
        
    }

    bool execute(const std::string &arg) {

        std::ofstream file;
        file.open(arg);

        if (!file) {
            std::cout << "Couldn't open file" << '\n';
        }
        else {
            std::cout << "File successfully opened" << '\n';
        }
        
    }


};

#endif