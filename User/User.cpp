#include "User.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;

User::User(string address, string phone, set<string>& EmailSet, string email, string password, Flight f, set<int>& IDSet, vector<User>& UserList, queue<Activity> s)
{
	setAddress(address);
	setPhone(phone);
	setEmail(EmailSet, email);
	setID(IDSet, UserList);
	setPassword(password); // it contains the function check password;
	setFlight(f);
	setSchedule(s);

	cout << endl << "Sign up successfull!";
}

// get functions
string User::getAddress()
{
	return Address;
}
string User::getPhone()
{
	return Phone;
}
string User::getEmail()
{
	return Email;
}
int User::getID()
{
	return ID;
}
string User::getPassword()
{
	return Password;
}

Flight User::getFlight()
{
	return F;
}

queue<Activity> User::getQueue()
{
	return S;
}

//set functions
void User::setAddress(string a)
{
	Address = a;
}
void User::setPhone(string p)
{
	Phone = p;
}
void User::setEmail(set<string>& EmailSet, string e)
{
	for (char& c : e)
	{
		c = tolower(c);
	}
	pair<set<string>::iterator, bool> result;
	result = EmailSet.insert(e);
	if (result.second == true)
		Email = e;
	else
	{
		string em = "";
		cout << "This email is already used in an other account, please enter another email" << endl << "Enter Email: ";
		cin >> em;
		setEmail(EmailSet, em);
	}
}
//redo
void User::setID(set<int>& ALL, vector<User>& UserList)//remove vector<int> and put static int first
{
	/*
	srand(time(0));
	vector<int> v = {};
	for (int i = 0; i < 10; i++)
	{
		int randNum = rand() % 10; // random number between 0  and 9
		v.push_back(randNum);
	}
	pair<set<vector<int>>::iterator, bool> result;
	result = ALL.insert(v);
	if (result.second == true)
		ID = v;
	else
		setID(ALL);
	*/

	//size of vector userslist for ID
	//functon check ID ize and add 0 accordingly
	//string library check
	int id = UserList.size() + 1;
	pair<set<int>::iterator, bool> result = ALL.insert(id);
	if (result.second == true)
		ID = id;
	else
		setID(ALL, UserList);

}
vector<bool> User::IsPasswordValid(string p)
{
	bool Uppercase = false;
	bool lowercase = false;
	bool numbers = false;
	bool symbols = false;

	vector<bool> check = { Uppercase, lowercase, numbers , symbols };

	if (p.size() < 8)
		return vector<bool> { false };
	for (int i = 0; i < p.size(); i++)
	{
		if (isupper(p[i]) == true)//convert to integer using ascii
			check[0] = true;
		else if (p[i] >= 'a' && p[i] <= 'z')
			check[1] = true;
		else if (p[i] >= '0' && p[i] <= '9')
			check[2] = true;
		else
		{
			//if(isspace(p[i]) == false && ispunct(p[i]) == false)
			if (p[i] != ' ')
				check[3] = true;
		}
	}
	return check;
}
void User::setPassword(string p)// it contains the function check password;
{
	int x = 0;
	/*cout << endl << "Enter a Password that follow these rules: " << endl
		<< "1- The password must be at least 8 characters long" << endl
		<< "2- The password must contain Uppercase and loweracse letters as well as numbers and symbols" << endl;*/
	do
	{
		vector<bool> check = IsPasswordValid(p);
		if (check.size() == 1)
			cout << "Password is too short, it need to be at elast 8 characters long" << endl;
		else if (check[0] && check[1] && check[2] && check[3])
		{
			Password = p;
			x = 1;
			return;
		}
		else
		{
			cout << "The password is not valid as it does not contain: ";
			string output = "";
			if (check[0] == false)
				output += "Uppercase Letters, ";
			if (check[1] == false)
				output += "Lowercase Letters, ";
			if (check[2] == false)
				output += "Numbers, ";
			if (check[3] == false)
				output += "Symbols, ";
			cout << output.substr(0, output.length() - 2);
		}

		cout << endl << "Enter a Password: ";
		cin >> p;
	} while (x != 1);

}
void User::setFlight(Flight f)
{
	F = f;
	F.setNumPassengers();
}

void User::setSchedule(queue<Activity>& act)
{
	S = act;
}

void User::PrintAccountDetails() // bedde zid option forgot password: I call the function setPassword eza baddo yghayera
{
	int w = 20;
	cout << "Account Details : " << endl
		<< setw(w) << left << "Address: " << setw(w) << getAddress() << endl
		<< setw(w) << left << "Phone: " << setw(w) << getPhone() << endl
		<< setw(w) << left << "Email: " << setw(w) << getEmail() << endl
		<< setw(w) << left << "ID: " << setw(w) << getID() << endl
		<< setw(w) << left << "Password: " << setw(w) << getPassword() << endl;
	F.PrintFlightDetails();
}

