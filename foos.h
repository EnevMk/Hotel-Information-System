#ifndef FOOS_HPP
#define FOOS_HPP

#include <vector>
#include <string>
#include <iostream>

int stringToInt(const std::string &str);
std::vector<int> DatesDeserialization(const std::string &period);
std::vector<std::string> splitCommandArgs(std::string &cmd);
void removeSpacesAtBegin(std::string &str);
bool isDigit(const std::string &str);

#endif