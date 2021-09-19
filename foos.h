#ifndef FOOS_HPP
#define FOOS_HPP

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
//#include "HotelStay.hpp"

int stringToInt(const std::string &str);
std::vector<int> DatesDeserialization(const std::string &period);
std::vector<std::string> splitCommandArgs(const std::string &cmd);
void removeSpacesAtBegin(std::string &str);
bool isDigit(const std::string &str);
bool areEqual(const std::tm &obj, const std::tm &other);

#endif