all: main.exe

main.exe: Hotel.o Room.o UI.o main.o BookingPeriod.o HotelStay.o foos.o Checkin.o

	g++ -o main Hotel.o Room.o UI.o main.o BookingPeriod.o HotelStay.o foos.o Checkin.o

Checkin.o: Checkin.cpp

	g++ -c Checkin.cpp

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