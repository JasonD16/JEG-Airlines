#ifndef Flight_h
#define Flight_h

#include<string>
#include<forward_list>
#include"Country.h"
using namespace std;

class Flight // think of adding 1st class; economy; business etc...
{
private:
	int flightID;
	int NumSeats = 0;
	string departureAirport;
	string arrivalAirport;
	string stop_overAirport;
	string DateDeparture;
	int DepartureDay;
	string DateArrival;
	int Departuretime; //hour
	int ArrivalTime; //hour
	//single linked list
	forward_list<Country> trajectory;

public:
	//constructor
	Flight();
	Flight(int flightID, string departureAirport, string arrivalAirport, string stop_overAirport,
		string DateDeparture, string DateArrival, int Departuretime, int ArrivalTime, forward_list<Country>& trajectory, int day, int seats);

	//Get Functions
	int getflightID();
	int getNumSeats();
	string getDepartureAirport();
	int getDepartureDay();
	string getArrivalAirport();
	string getStop_overAirport();
	string getDateDeparture();
	string getArrivalDeparture();
	int getHourOfDeparture();
	int getArrivalTime();

	//Set Function
	void setFlightID(int);
	void setNumSeats(int);
	void setNumSeatspp();
	void setNumSeatsmm();
	void setDepartureAirport(string);
	void setDepartureDay(int);
	void setArrivalAirport(string);
	void setStop_overAirport(string);
	void setDateDeparture(string);
	void setDateArrival(string);
	void setHourOfDeparture(int); // military time
	void setArrivalTime(int);
	void setTrajectory(forward_list<Country>& trajectory);

	// print function that calls all the get functions
	void PrintFlightDetails(); //this print function does not print the trajectory
	void PrintTrajectory(); //this function iterates through each node in the list and prints the country object details by calling the print country function



};

#endif