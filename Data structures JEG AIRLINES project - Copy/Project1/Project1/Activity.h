#ifndef Activity_h
#define Activity_h

#include <string>
#include <queue>

using namespace std;

struct Activity
{
	string ActivityName;
	int StartTime;
	int EndTime;
	//time structure
	Activity();
	Activity(string, int, int);
	void PrintActivity(Activity& act);

};

class Schedule
{
private:
	queue<Activity> Scheduler;

public:
	Schedule();
	void AddActivity(Activity&);
	void PrintQueue(queue<Activity>& act);
};
#endif
