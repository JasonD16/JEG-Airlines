#pragma once
#define Country_h
#ifndef Country

#include <string>
#include <vector>

using namespace std;

class Country
{
private:

	//Attributes
	string CountryName;
	string CountryAge;
	string CountryCapital;
	string CountryLanguage;
	vector<string> HistoricalMonuments;
	string BestDish;
	string DesinationTime;
	//add delay time  and add a get function for it

public:

	//Constructor
	Country(string = "Lebanon", string = "10 000 years", string = "Beirut", string = "Arabic", vector<string> = { " Baalbek", "Byblos", "Tyre" }, string = "Kebbeh", string = "23");

	//Set function 
	void SetCountryName(string);
	void SetCountryAge(string);
	void SetCountryCapital(string);
	void SetCountryLanguage(string);
	void SetHistoricalMonuments(vector<string>);
	void SetBestDish(string);
	void SetDesinationTime(string);


	//Get functions
	string GetCountryName();
	string GetCountryAge();
	string GetCountryCapital();
	string GetCountryLanguage();
	vector<string> GetHistoricalMonuments();
	string GetBestDish();
	string GetDesinationTime();


	//Print function
	void PrintCountryDetails();
};
#endif
