#ifndef Functions_h
#define Functions_h

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void printIntro()
{
	cout << "Welcome aboard!" << endl
		<< "Thank You for Choosing JEG AIRLINES as your number 1 Airline!" << endl
		<< "In JEG AIRLINES mobile application you can book a flight to your desired destination ANYWHERE in the world!!!" << endl
		<< "Please choose one of the following:\n" << endl;
}

void printIntro2()
{

}

void LoadingFunc()
{

	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < 14; i++) {
		string name = "JEG AIRLINE...";
		int x = i % 14;


		switch (name[x]) {
		case 'J':
			SetConsoleTextAttribute(hc, 0x04);
			cout << name[x];
			break;

		case 'E':
			if (x == 1) {
				SetConsoleTextAttribute(hc, 0x02);
				cout << name[x];
			}
			else {
				SetConsoleTextAttribute(hc, 0x07);
				cout << name[x];
			}
			break;

		case 'G':
			SetConsoleTextAttribute(hc, 0x01);
			cout << name[x];
			break;

		default:
			SetConsoleTextAttribute(hc, 0x07);
			cout << name[x];
			break;
		}

		Sleep(350);
		if (x == 13)
			system("cls");
	}

	SetConsoleTextAttribute(hc, 0x07);
}

void WaitandClear() {
	Sleep(4250);
	system("cls");
}

#endif

