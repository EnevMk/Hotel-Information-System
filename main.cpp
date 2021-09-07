#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <fstream>

#include "Room.hpp"
#include "UI.hpp"
#include "Hotel.hpp"


/* int stringToInt(const std::string &str) {
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
} */

int main() {

    //Room *rm = new Room(2, 105);
    /* Room *r2 = new Room(3, 106); */
    /* bookingPeriod bp(2021, 9, 1,2021,9, 5);
    rm->reserve(HotelStay(105, 2, bp, "test")); */
    
    UI ses;
    
    std::ifstream file;
    file.open("failche.fmi");
    file >> ses;

    file.close();

    /* std::ofstream ff;
    ff.open("Hotel.fmi");
    ff << ses.hotel;

    ff.close(); */

    ses.CommandListener();

    
    /* ses.hotel.addRoom(rm);
    ses.hotel.addRoom(r2); */
    //ses.CommandListener();
    

    /* std::string c = "simp 3";

    std::vector<std::string> v = splitCommandArgs(c);

    for (std::string s : v) {
        std::cout << s << ' ';
    } */

    /* bookingPeriod bbb(2021, 8, 15, 2021, 8, 22);
    std::cout << std::put_time(&bbb.checkIn, "%Y-%m-%d"); */
    return 0;
}