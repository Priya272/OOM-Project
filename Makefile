all: Customer.h Customer.cpp Room.h Room.cpp LuxuriousRoom.h LuxuriousRoom.cpp Hotel.h Hotel.cpp HotelManagementExample.cpp
	g++ -o HotelManagement Customer.cpp Room.cpp LuxuriousRoom.cpp Hotel.cpp HotelManagementExample.cpp	

