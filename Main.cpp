#include <iostream>
#include <iomanip>
#include <forward_list>
#include <algorithm>

#include "User.h"
#include "Flight.h"
#include "Country.h"
#include "Activity.h"
#include "Functions.h"

using namespace std;

int main()
{
	//begin data fragment
	vector<User> UsersList = {}; 
	set<int> IDlist = {};
	set<string> EmailList = {};
	vector<Flight> AllFlights;
	Country Lebanon;
	queue<Activity> Schedul = {};
	int flying = 0;

	//First flight from Beirut to NYC
	Country Turkey("Turkey", "8,000 years", "Ankara", "Turkish", { "Hagia Sophia", "Topkapi Palace", "Blue Mosque" }, "D�ner Kebab", "12:00");
	Country Greece("Greece", "5,000 years", "Athens", "Greek", { "Acropolis of Athens", "Parthenon", "Ancient Olympia" }, "Moussaka", "13:00");
	Country	Italy("Italy", "3,000 years", "Rome", "Italian", { "Colosseum", "Roman Forum", "Leaning Tower of Pisa" }, "Pizza", "15:00");
	Country France("France", "1,000 years", "Paris", "French", { "Eiffel Tower", "Louvre Museum", "Notre-Dame Cathedral" }, "Croissant", "17:00");
	Country UnitedKingdom("United Kingdom", "1,000 years", "London", "English", { "Big Ben", "Buckingham Palace", "Tower of London" }, "Fish and Chips", "19:00");
	Country Iceland("Iceland", "20 million years", "Reykjav�k", "Icelandic", { "Thingvellir National Park", "Blue Lagoon", "J�kuls�rl�n Glacier Lagoon" }, "Skyr", "21:00");
	Country Greenland("Greenland", "4 billion years", "Nuuk", "Greenlandic and Danish", { "Ilulissat Icefjord", "Qaqortoq", "Nuuk Cathedral" }, "Dried Fish", "23:00");
	Country Canada("Canada", "4.5 billion years", "Ottawa", "English and French", { "Niagara Falls", "CN Tower", "Rocky Mountains" }, "Poutine", "1:00");
	Country UnitedStates("United States", "250 years", "Washington, D.C.", "English", { "Statue of Liberty", "Golden Gate Bridge", "Grand Canyon" }, "Burger", "4:00");

	forward_list<Country> Trajectory = { Lebanon, Turkey, Greece, Italy, France, UnitedKingdom, Iceland, Greenland, Canada, UnitedStates };

	Flight Flight1(1, "Beirut Rafic Hariri International Airport (BEY)", "John F. Kennedy International Airport (JFK)", "", "29/11/2024", "30/11/2024", 10, 4, Trajectory, 29, 250);

	//Second flight
	Country Turkey2("Turkey", "8,000 years", "Ankara", "Turkish", { "Hagia Sophia", "Topkapi Palace", "Blue Mosque" }, "D�ner Kebab", "1:00");
	Country Russia("Russia", "1,000 years", "Moscow", "Russian", { "Red Square", "St. Basil's Cathedral, Kremlin" }, "Borsch", "5:00");
	Country Mongolia("Mongolia", "2,000 years", "Ulaanbaatar", "Mongolian", { "Gorkhi-Terelj National Park", "Khustain Nuruu National Park" }, "Buuz", "8:00");
	Country China("China", "5,000 years", "Beijing", "Mandarin Chinese", { "Great Wall of China", "Forbidden City, Temple of Heaven" }, "Peking Duck", "11:00");
	Country Japan("Japan", "3,000 years", "Tokyo", "Japanese", { "Tokyo Skytree", "Meiji Shrine, Imperial Palace" }, "Sushi", "19:00");

	forward_list<Country> Trajectory2 = { Lebanon, Turkey2, Mongolia, China, Japan };

	Flight Flight2(2, "Beirut Rafic Hariri International Airport (BEY)", "Haneda Airport(HND)", "", "03/12/2024", "04/12/2024", 23, 19, Trajectory2, 3, 250);

	//Third Flight
	Country Turkey3("Turkey", "8,000 years", "Ankara", "Turkish", { "Hagia Sophia", "Topkapi Palace", "Blue Mosque" }, "D�ner Kebab", "3:00");
	Country SaudiArabia("Saudi Arabia", "3,000 years", "Riyadh", "Arabic", { "Masjid al-Haram, Masjid al-Nabawi, Al-Ula Old Town" }, "Kabsa", "7:00");
	Country UnitedArabEmirate("United Arab Emirates", "200 years", "Abu Dhabi", "Arabic", { "Burj Khalifa, Sheikh Zayed Grand Mosque, Louvre Abu Dhabi" }, "Machboos", "10:00");
	Country India("India", "5,000 years", "New Delhi", "Hindi", { "Taj Mahal, Red Fort, Hawa Mahal" }, "Butter Chicken", "13:00");
	Country Indonesia("Indonesia", "70,000 years", "Jakarta", "Indonesian", { "Borobudur Temple, Bali, Komodo National Park" }, "Nasi Goreng", "19:00");
	Country Australia("Australia", "45,000 years", "Canberra", "English", { "Sydney Opera House, Great Barrier Reef, Uluru (Ayers Rock)" }, "Meat Pie", "10:00");

	forward_list<Country> Trajectory3 = { Lebanon, Turkey3, SaudiArabia, UnitedArabEmirate, India, Indonesia, Australia };

	Flight Flight3(3, "Beirut Rafic Hariri International Airport (BEY)", "Sydney Kingsford Smith International Airport (SYD)", "", "23/12/2024", "24/12/2024", 1, 10, Trajectory3, 23, 250);

	//Add to the vector containing all flights
	AllFlights = { Flight1, Flight2, Flight3 };
	//End data fragment
	LoadingFunc();
	int choice = 0;
	printIntro();

	
	do
	{
		cout << "1- LOG IN (if you already have an account)" << endl
			<< "2- SIGN UP (if you don't)" << endl
			<< "3- Forgot Password" << endl
			<< "4- Exit the app" << endl << endl
			<< "Enter : ";
		cin >> choice;

		switch (choice)
		{
		case 1: // log in
		{
			int LogInComplete = 0;
			while (LogInComplete == 0)
			{
				system("cls");
				string username = "";
				string password = "";

				if (UsersList.size() == 0)
				{
					cout << "No Account has been created yet!" << endl
						<< "You might be our first user!!!!!!" << endl
						<< "Please sign up and then try signing in" << endl;
					break;
				}

				cout << "Enter your email/username: "; //User Input
				cin.ignore();
				getline(cin, username);
				for (char& c : username)
				{
					c = tolower(c);
				}

				cout << endl << "Enter password: "; // User Input

				getline(cin, password);
				//Time complexity:O(n)
				for (int i = 0; i < UsersList.size(); i++)
				{
					if (username == UsersList[i].getEmail() && UsersList[i].getPassword() == password)
					{
						User CurrentUser = UsersList[i];
						LogInComplete = 1;
						cout << endl << "Login Successful" << endl;
						WaitandClear();
					
						int choice2 = 0;
						cout << "Welcome to our Airport Application!!!" << endl
							<< "What would you like to do?" << endl
							<< "1-Book a Flight" << endl
							<< "2-Cancel a booking" << endl
							<< "3-Scheduler" << endl
							<< "4-Print Account Details" << endl
							<< "5-Google Air MAPS" << endl
							<< "6-Sign Out" << endl << endl
							<< "Enter: ";
						cin >> choice2;

						do
						{
							int FlightChoice = 0;

							switch (choice2)
							{
							case 1: //Book flights
							{
								FlightChoice = 0;
								cout << endl << "Here are our latest flight destinations: " << endl << endl;

								//Time complexity:O(n)
								for (int i = 0; i < AllFlights.size(); i++)
								{
									cout << i + 1 << "-";
									AllFlights[i].PrintFlightDetails();
									cout << endl;
								}
								do
								{
									cout << "To book a flight please Enter the number near the desired flight" << endl
										<< "To go back enter " << AllFlights.size() + 2 << endl; 
									cin >> FlightChoice;
								} while (FlightChoice < 1 || FlightChoice > AllFlights.size() + 2);

								if (FlightChoice == AllFlights.size() + 2) //Go back
								{
									WaitandClear();
									break;
								}
								if (AllFlights[FlightChoice - 1].getNumSeats() == 0)
								{
									cout << "This flight is fully book!" << endl << "Choose another Flight" << endl;
									WaitandClear();
									break;
								}
								AllFlights[FlightChoice - 1].setNumSeatsmm();
								UsersList[i].setFlight(AllFlights[FlightChoice - 1]);
								CurrentUser = UsersList[i];

								cout << "You have successfully booked the following flight: " << endl << endl;
								cout << FlightChoice << "-";
								AllFlights[FlightChoice - 1].PrintFlightDetails();
								WaitandClear();
								cout << endl;

								break;
							}
							case 2: //CANCEL A BOOKING
							{
								if (UsersList[i].getFlight().getflightID() != 0)
								{
									int cancel = 0;
									cout << endl << "Which of your flights would you like to cancel?" << endl << endl;
									Flight f = UsersList[i].getFlight(); // this should be an array
									f.PrintFlightDetails();
									cout << "Enter the FLIGHT ID of the flight you want to cancel: ";
									cin >> cancel;
									AllFlights[cancel - 1].setNumSeatspp();
									Flight x;
									CurrentUser.setFlight(x);
									UsersList[i].setFlight(x);

									WaitandClear();
								}
								else
								{
									cout << "You did not book any flights";
								}
								WaitandClear();

								break;
							}
							case 3: // SCHEDULER
							{
								
								cout << endl << "Welcome to our scheduler!" << endl
									<< "Here you can schedule your activities or tasks you need or would like to accomplish throughout the day of your flight" << endl << endl;

								if (UsersList[i].getFlight().getflightID() == 0)
								{
									cout << endl << "You have not booked any flight therefore you cannot schedule!" << endl;
									WaitandClear();
									break;
								}

								int act = 0;

								cout << "1-Make a Schedule for departure day" << endl
									<< "2-Process Activities" << endl << endl
									<< "Enter: ";
								cin >> act;
								switch (act)
								{
									
									case 1:
									{
										if (Schedul.empty() == false) //Empty schedule every time user wants to make A new one
											Schedul = {};
										flying = 0;
										WaitandClear();
										int AddAct = 0;

										cout << "You can add multiple tasks. Each task will take 1 hour." << endl;
										cout << "However, no activity can start if the starting time is 1 hour before your flight's departure time." << endl;
										cout << "Your flight departure time is: " << UsersList[i].getFlight().getDateDeparture() << "	At: " << UsersList[i].getFlight().getHourOfDeparture() << ":00" << endl;
										cout << "You must be at the airport at least 1 hour before your flight." << endl;
										cout << endl;

										cout << "Do you want to add an activity/task?" << endl << "If yes enter 1" << endl
											<< "If not enter any number" << endl << endl
											<< "Enter : ";
										cin >> AddAct;

										int previousEndTime = -1; // Initialize to -1 to indicate no previous activity
										int flag = 0; // flag value for day
										int day = 0;

										while (AddAct == 1)
										{
											string ActName = "";
											int s = 0;
											int e = 0;

											cout << "Enter Activity Name: ";
											cin.ignore();
											getline(cin, ActName);

											if (flag == 0)
											{
												cout << "Enter the day of the task: ";
												cin >> day;
												flag = 1;
											}
											else
											{
												cout << endl << "Day: " << day;
											}
											if (previousEndTime == -1)
											{

												if (day < UsersList[i].getFlight().getDepartureDay())
												{
													cout << endl << "Enter Start Time (24-hour format, in hours): ";
													cin >> s;

												}
												else if (day == UsersList[i].getFlight().getDepartureDay())
												{
													do
													{
														cout << "Enter Start Time (24-hour format, in hours): ";
														cin >> s;
													} while (s > UsersList[i].getFlight().getHourOfDeparture() - 1 || s < 0);

												}
											}
											else 
											{
												s = previousEndTime; // Automatically set start time to the previous activity's end time
												cout << endl << "Start Time for this activity is automatically set to: " << s << endl;
											}

											// Check if starting time is 1 hour before flight departure
											if (s >= UsersList[i].getFlight().getHourOfDeparture() - 1 && UsersList[i].getFlight().getDepartureDay() == day)
											{
												cout << endl << "No more activities can be added as the starting time is 1 hour before your flight's departure." << endl;
												break;
											}

											e = s + 1; // Each task takes 1 hour
											cout << "End Time for this activity is automatically set to: " << e << endl;

											previousEndTime = e; // Update the end time for the next activity
											if (e == 24)
											{
												day++;
												previousEndTime = 0;
											}

											Activity NewActivity(ActName, s, e);
											// Time complexity: O(1)
											Schedul.push(NewActivity);
											CurrentUser.setSchedule(Schedul);
											UsersList[i].setSchedule(Schedul);

											cout << endl << "Do you want to add another activity/task?" << endl << "If yes enter 1" << endl
												<< "If not enter any number" << endl << endl
												<< "Enter : ";
											cin >> AddAct;
										}
										
										WaitandClear();
										break;
									}
									case 2:
									{
										system("cls");
										queue<Activity> CurrentQueue = UsersList[i].getQueue();
										if (CurrentQueue.empty() == true)
										{
											cout << "You did not add any activities therefore there is no schedule avaialble" << endl;
											WaitandClear();
										}
										else
										{
											
											//Time complexity:O(n)
											while (CurrentQueue.empty() == false)
											{
												Activity CurrentActivity = CurrentQueue.front();
												CurrentActivity.PrintActivity(CurrentActivity);
												CurrentQueue.pop();
												WaitandClear();
											}
											queue<Activity> x = {};
											CurrentUser.setSchedule(x);
											UsersList[i].setSchedule(x); //or UsersList[i].setSchedule(CurrentQueue) 
											flying = 1;
										}
										break;
									}

								}
								break;
							}
							case 4://Print account details
							{
								CurrentUser.PrintAccountDetails(); // maybe add WaitandClear
								Sleep(8000);
								system("cls");
								break;
							}
							case 5: //Google Air MAPS
							{
								system("cls");
								if (CurrentUser.getQueue().empty() == false)
								{
									cout << "You have not boarded the plane, yet you cannot use this function yet" << endl
										<< "When you finish your schedule you will be able to use this function" << endl;
								}
								else if(flying == 1)
								{
									Flight f = CurrentUser.getFlight();
									f.PrintTrajectory();
								}
								WaitandClear();
								break;
							}
							case 6://SIGN OUT
							{
								cout << "Sign out successful" << endl;
								break;
							}
							default:
							{
								cout << "Please select one of the available options!" << endl;
								break;
							}
							}
							if (choice2 == 6)//go back 
								break;

							cout << "Welcome to our Airport Application!!!" << endl
								<< "What would you like to do?" << endl
								<< "1-Book a Flight" << endl
								<< "2-Cancel a booking" << endl
								<< "3-Scheduler" << endl
								<< "4-Print Account Details" << endl
								<< "5-Google Air MAPS" << endl
								<< "6-Sign Out" << endl << endl
								<< "Enter: ";
							cin >> choice2;
						} while (choice2 > 0 && choice2 < 7);

						break;
					}
					else if (username == UsersList[i].getEmail() && password != UsersList[i].getPassword())
					{
						cout << "Wrong Password" << endl << "Try Again" << endl;
						WaitandClear();
						break;
					}
					else if (i == UsersList.size() - 1)
					{
						cout << "Wrong Username Or Password" << endl << "Try Again" << endl;
						WaitandClear();
					}
				}

			}
			break;
		}
		case 2: // sign up
		{
			//data fragments
			string Email = "";	// username is the email
			string Address = "";
			string Phone = "";
			vector<int> ID; // Don't ask the user for ID it is auto-generated by the APP
			string Password = "";
			Flight F;
			Activity A1;
			queue<Activity> S;

			//end data fragments


			cout << endl << "Enter Email: ";
			cin.ignore();
			getline(cin, Email);


			cout << endl << "Enter Address: ";

			getline(cin, Address);

			cout << endl << "Enter Phone: ";

			getline(cin, Phone);

			cout << endl << "Enter a Password that follow these rules: " << endl
				<< "1- The password must be at least 8 characters long" << endl
				<< "2- The password must contain Uppercase and loweracse letters as well as numbers and symbols" << endl;

			cout << endl << "Enter Password: ";
			getline(cin, Password); // Need to review for space in password user input
			//User(string address, string phone, set<string>&EmailSet, string email, string password, Flight f, set<vector<int>>&IDSet);


			User User1(Address, Phone, EmailList, Email, Password, F, IDlist, UsersList, S);
			UsersList.push_back(User1);
			break;
		}
		case 3: // forgot password / change password
		{
			if (UsersList.size() == 0)
			{
				system("cls");
				cout << endl << "No Account has been created yet!" << endl
					<< "You might be our first user!!!!!!" << endl
					<< "Please sign up and then try signing in" << endl;
				break;
			}
			cout << "You have forgotten your account's password" << endl;
			cout << "In order to verify your identity we need you to enter your username as well as your phone number" << endl
				<< "You will be able to change your passwrod afterwards" << endl << endl;

			string username = "";
			cout << "Enter your email/username: "; //User Input
			cin.ignore();
			getline(cin, username);

			//Time complexity:O(n)
			for (char& c : username)
			{
				c = tolower(c);
			}

			string PhoneNum = "";

			cout << "Enter Phone Number: ";
			getline(cin, PhoneNum);

			//Time complexity:O(n)
			for (int i = 0; i < UsersList.size(); i++)
			{
				if (username == UsersList[i].getEmail() && UsersList[i].getPhone() == PhoneNum)
				{
					string pass = "";
					cout << "We have verified your Identity" << endl
						<< "Please reset your password and login again" << endl << endl
						<< "Enter new password: ";

					getline(cin, pass);
					UsersList[i].setPassword(pass); 
					cout << "Password Reset Successfull!" << endl;
					break;
				}
			}
			break;
		}
		case 4: // exit the app
		{

			cout << "Thank you for choosing our application!" << endl
				<< "Have a safe flight" << endl;
			break;

		}
		default:
		{
			cout << endl << "Please enter one of the options that are available" << endl;
			choice = -1;
			break;
		}
		}
		WaitandClear();
		if (choice == 4)
			break;
		printIntro();
		/*if (LogInComplete == 1)
			break;*/
	

	} while ((choice > 0 && choice < 5) || choice == -1);

	return 0;
}