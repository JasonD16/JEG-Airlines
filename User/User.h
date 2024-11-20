#ifndef User_h
#define User_h

#include<string>
#include <vector>
#include <set>
#include <queue>

#include "Flight.h" //Composition: A user has a flight
#include "Activity.h"// Composition: A user has a queue of Activities

using namespace std;
// here we a have composition where a user has a flight
class User
{
private:
	string Email; // username is the email
	string Address;
	string Phone;
	int ID;
	string Password;
	Flight F;//many flights put in vector for ex
	queue<Activity> S;

public:
	User(string address, string phone, set<string>& EmailSet, string email, string password, Flight f, set<int>& IDSet, vector<User>& UserList, queue<Activity> S);
	//get functions
	string getAddress();
	string getPhone();
	string getEmail();
	int getID();
	string getPassword();
	Flight getFlight();
	queue<Activity> getQueue();
	// set functions	
	void setAddress(string address);
	void setPhone(string phone);
	void setEmail(set<string>& EmailSet, string email);
	void setID(set<int>& SetID, vector<User>& UserList);
	void setPassword(string password); // it contains the function check password;
	void setFlight(Flight f);
	void setSchedule(queue<Activity>& act);
	//print 
	void PrintAccountDetails(); // this function calls the print function of the flight
	//utility functions
	vector<bool> IsPasswordValid(string);
};
#endif
