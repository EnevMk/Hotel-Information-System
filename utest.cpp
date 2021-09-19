#define CATCH_CONFIG_MAIN

#include "CheckIn.hpp"
#include "catch_amalgamated.hpp"
#include "UI.hpp"
#include "Hotel.hpp"
#include "Room.hpp"
#include "HotelStay.hpp"
#include "foos.h"
#include "BookingPeriod.hpp"


TEST_CASE("transfer hotelstay from room to room") {

    
    Room r1(3, 101);
    bookingPeriod bp;
    std::cin >> bp;

    HotelStay h(101, 3, bp, "Paco");
    r1.reserve(h);

    Room r2(3, 102);
    r1.moveHotelstayToRoom(&h, &r2);

    CHECK(r2.getStaysVector()[0] == h);

}