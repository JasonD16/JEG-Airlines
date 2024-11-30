#include "Activity.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//Activity
Activity::Activity()
{
	ActivityName = "";
	StartTime = 0;
	EndTime = 0;
}

Activity::Activity(string n, int s, int e)
{
	ActivityName = n;
	StartTime = s;
	EndTime = e;
}

void Activity::PrintActivity(Activity& activity)
{
	int width = 15;
	cout << "Activity Name:" << setw(width) << left << activity.ActivityName << setw(width) << endl
		<< "Start time: " << setw(width) << left << activity.StartTime <<setw(width) << endl
		<< "End time: " << setw(width) << left << activity.EndTime << setw(width) << endl << endl;
}
// Schedule
Schedule::Schedule()
{
	queue<Activity> s;
}
void Schedule::AddActivity(Activity& activity)
{
	//Add an activity to the schedule.
	Scheduler.push(activity);
	cout << "Activity \"" << activity.ActivityName << "\" is added to the scheduler." << endl;
}

void Schedule::PrintQueue(queue<Activity>& act)
{
	queue<Activity> act1 = act;
	//Time Complexity: O(n)
	while (act1.empty() == false)
	{
		Activity a = act1.front();
		a.PrintActivity(act1.front());
		act1.pop();
	}
}


