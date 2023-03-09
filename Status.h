#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <iostream>

using namespace std;



class Status
{

private:
	string status;
	string date;

public:

	Status(string newStatus)
	{
		status = newStatus;
		setDate();
	}
	void setDate()
	{
		time_t now = time(0);
		date = ctime(&now);
	}
	void setStatus(string newStatus)
	{
		status = newStatus;
	}
	void printStatus()
	{

		cout << "the time is " << date
			<< " the status is " << status;
	}


};