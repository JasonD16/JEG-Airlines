#include "Country.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Constructor
Country::Country(string cn, string ca, string cc, string cl, vector<string> hm, string bd, string dt) {

	SetCountryName(cn);
	SetCountryAge(ca);
	SetCountryCapital(cc);
	SetCountryLanguage(cl);
	SetHistoricalMonuments(hm);
	SetBestDish(bd);
	SetDesinationTime(dt);
}


//Set functions

void Country::SetCountryName(string cn) {
	CountryName = cn;
}

void Country::SetCountryAge(string ca) {
	CountryAge = ca;
}

void Country::SetCountryCapital(string cc) {
	CountryCapital = cc;
}

void Country::SetCountryLanguage(string cl) {
	CountryLanguage = cl;
}

void Country::SetHistoricalMonuments(vector<string> hm) {

	HistoricalMonuments = hm;
}

void Country::SetBestDish(string bd) {
	BestDish = bd;
}

void Country::SetDesinationTime(string dt) {
	DesinationTime = dt;
}


//Get functions

string Country::GetCountryName() {
	return CountryName;
}

string Country::GetCountryAge() {
	return CountryAge;
}

string Country::GetCountryCapital() {
	return CountryCapital;
}

string Country::GetCountryLanguage() {
	return CountryLanguage;
}

vector<string> Country::GetHistoricalMonuments() {
	return HistoricalMonuments;
}

string Country::GetBestDish() {
	return BestDish;
}

string Country::GetDesinationTime() {
	return DesinationTime;
}


//Print Country Details - Time Complexity: O(n)
void Country::PrintCountryDetails() {
	int width1 = 20;
	cout << setw(width1) << left << "Country name: " << setw(width1) << CountryName << endl
		<< setw(width1) << left << "Country age: " << setw(width1) << CountryAge << endl
		<< setw(width1) << left << "Country Capital: " << setw(width1) << CountryCapital << endl
		<< setw(width1) << left << "Country Language: " << setw(width1) << CountryLanguage << endl
		<< setw(width1) << left << "Country Historical Monuments: ";
	for (int x = 0; x < HistoricalMonuments.size(); x++) {
		cout << setw(width1) << left << "#" << x + 1 << " " << HistoricalMonuments[x];
		cout << endl;
		cout << "                              ";
	}

	cout << setw(width1) << left << "Country best dish: " << setw(width1) << BestDish
		<< setw(width1) << left << "Country destination time: " << setw(width1) << DesinationTime << endl;
}