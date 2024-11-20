#include <iostream>
#include <iomanip>
#include <string>
#include "Flight.h"
#include "Windows.h"

using namespace std;

//Constructor
Flight::Flight() {

	setFlightID(0);
	setDepartureAirport("");
	setArrivalAirport("");
	setStop_overAirport("");
	setDateDeparture("");
	setDateArrival("");
	setHourOfDeparture(0);
	setArrivalTime(0);

}

Flight::Flight(int flightID, string departureAirport, string arrivalAirport, string stop_overAirport, string DateDeparture, string DateArrival, int Departuretime, int ArrivalTime, forward_list<Country>& trajectory) {

	setFlightID(flightID);
	setDepartureAirport(departureAirport);
	setArrivalAirport(arrivalAirport);
	setStop_overAirport(stop_overAirport);
	setDateDeparture(DateDeparture);
	setDateArrival(DateArrival);
	setHourOfDeparture(Departuretime);
	setArrivalTime(ArrivalTime);
	setTrajectory(trajectory);

}

//Get Functions
int Flight::getflightID() {

	return flightID;

}
int Flight::getNumPassengers()
{
	return NumPassengers;
}
string Flight::getDepartureAirport() {

	return departureAirport;
}
string Flight::getArrivalAirport() {


	return arrivalAirport;
}
string Flight::getStop_overAirport() {


	return stop_overAirport;
}
string Flight::getDateDeparture() {

	return DateDeparture;
}
string Flight::getArrivalDeparture() {

	return DateArrival;
}
int Flight::getHourOfDeparture() {

	return Departuretime;
}
int Flight::getArrivalTime() {

	return ArrivalTime;
}

//Set Functions

void Flight::setFlightID(int fi) {

	flightID = fi;

}
void Flight::setNumPassengers()
{
	NumPassengers++;
}
void Flight::setDepartureAirport(string da) {

	departureAirport = da;

}
void Flight::setArrivalAirport(string aa) {

	arrivalAirport = aa;

}
void Flight::setStop_overAirport(string soa) {

	stop_overAirport = soa;

}
void Flight::setDateDeparture(string dd) {

	DateDeparture = dd;

}
void Flight::setDateArrival(string Da) {

	DateArrival = Da;
}
void Flight::setHourOfDeparture(int hod) {
	Departuretime = hod;
}
void Flight::setArrivalTime(int at) {

	ArrivalTime = at;
}
void Flight::setTrajectory(forward_list<Country>& t) {

	trajectory = t;
}

// print function that calls all the get functions
void Flight::PrintFlightDetails() {

	int widthFlight = 20;

	cout << setw(widthFlight) << left << "Flight ID: " << setw(widthFlight) << getflightID() << endl
		<< setw(widthFlight) << left << "Departure Airport: " << setw(widthFlight) << getDepartureAirport() << endl
		<< setw(widthFlight) << left << "Arrival Airport: " << setw(widthFlight) << getArrivalAirport() << endl
		<< setw(widthFlight) << left << "Stop over Airport: " << setw(widthFlight) << getStop_overAirport() << endl
		<< setw(widthFlight) << left << "Departure Date: " << setw(widthFlight) << getDateDeparture() << endl
		<< setw(widthFlight) << left << "Arrival Date: " << setw(widthFlight) << getArrivalDeparture() << endl
		<< setw(widthFlight) << left << "Departure Time: " << setw(widthFlight) << getHourOfDeparture() << endl
		<< setw(widthFlight) << left << "Arrival Time: " << setw(widthFlight) << getArrivalTime() << endl << endl;

}

void Flight::PrintTrajectory() {

	for (Country Country : trajectory) {

		Country.PrintCountryDetails();
		Sleep(8000);
	}

}