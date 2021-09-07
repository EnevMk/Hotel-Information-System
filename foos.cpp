#include "foos.h"

int stringToInt(const std::string &str) {
    int len = str.size();
    int num = 0;

    for (int i = 0; i < len; ++i) {
        if (i == 0 && str[i] == '0') continue;
        num *= 10;
        num += str[i] - '0';
    }

    return num;
}

std::vector<int> DatesDeserialization(const std::string &period) {

    int startIndex = 0, substrLen = 0, offset = 0;

    std::vector<int> nums;

    for (int i = 0; i <= period.size(); ++i) {
        
        if (period[i] == '-' || period[i] == '\0' || period[i] == '/') {
            
            nums.push_back( stringToInt(period.substr(startIndex + offset, substrLen)));
            
            offset += substrLen  + 1;
            substrLen = 0;
        }
        else {
            substrLen++;
        }

    }

    return nums;
}

std::vector<std::string> splitCommandArgs(const std::string &cmd) {
    int startIndex = 0, substrLen = 0, offset = 0;

    std::vector<std::string> args;

    for (int i = 0; i <= cmd.size(); ++i) {
        
        if (cmd[i] == ' ' || cmd[i] == '\0') {
            //std::cout << 'o';
            args.push_back(cmd.substr(startIndex + offset, substrLen));
            offset += substrLen  + 1;
            substrLen = 0;
        }
        else {
            substrLen++;
        }

    }

    return args;
}

void removeSpacesAtBegin(std::string &str) {
    int i = 0;
    while (str[i] == ' ') {
        i++;
    }
    str.erase(0, i);
}