all: main.exe

utest: Hotel.o Room.o UI.o utest.o BookingPeriod.o HotelStay.o foos.o CheckIn.o catch_amalgamated.o

	g++ -o utest Hotel.o Room.o UI.o utest.o BookingPeriod.o HotelStay.o foos.o CheckIn.o catch_amalgamated.o

main.exe: Hotel.o Room.o UI.o main.o BookingPeriod.o HotelStay.o foos.o CheckIn.o

	g++ -o main Hotel.o Room.o UI.o main.o BookingPeriod.o HotelStay.o foos.o CheckIn.o

catch_amalgamated.o: catch_amalgamated.cpp

	g++ -c catch_amalgamated.cpp

utest.o: utest.cpp

	g++ -c utest.cpp

CheckIn.o: CheckIn.cpp

	g++ -c CheckIn.cpp

foos.o: foos.cpp

	g++ -c foos.cpp

Hotel.o: Hotel.cpp
	
	g++ -c Hotel.cpp

Room.o: Room.cpp

	g++ -c Room.cpp

UI.o: UI.cpp	

	g++ -c UI.cpp

main.o: main.cpp

	g++ -c main.cpp

BookingPeriod.o: BookingPeriod.cpp

	g++ -c BookingPeriod.cpp

HotelStay.o: HotelStay.cpp

	g++ -c HotelStay.cpp

clean:
	del /f *.o main.exe