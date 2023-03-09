#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "FansPage.h"
#include "Status.h"
#include <vector>
#include <map>
#include "Exeption1.h"


using namespace std;


class FansPage;

class Friend {

	//char name[25] = "no name";
	string name;

	vector <Status* > vectorOfStatus;
	int numOfStatus = 0;
	int statusLogicalSize = 1;

	map<const string, Friend* > mapOfFriends;
	int numOfFriends = 0;

	map<const string, FansPage* > mapOfFansPage;
	int numOfFanPage = 0;
	vector<string>needTodeDelete;//the names we need to delete. this is for diitractor


	friend class Control;
	friend class FansPage;
public:

	//constractor
	Friend(string name1)
	{
		name = name1;
	}


	//discractor
	~Friend() = default;


	//add functions
	void addFriend(const string& name, Friend* friend1)noexcept(false)
	{
		if (mapOfFriends.find(name) != mapOfFriends.end())
		{
			eror3 ex( name, this->name);
			throw ex;
		}
		numOfFriends++;
		mapOfFriends.insert({ name, friend1 });
	}
	void addStatus(const string&);

	void addFansPage(const string& name, FansPage* fansPage)noexcept(false)
	{

		if (mapOfFansPage.find(name) != mapOfFansPage.end())
		{
			eror3 ex( this->name, name);
			throw ex;
		}
		numOfFanPage++;
		mapOfFansPage.insert({ name, fansPage });

	}

	//remove functions
	void removeFriend(const string& name)
	{
		if (mapOfFriends.find(name) == mapOfFriends.end())
		{
			eror2 ex(name, this->name);
			throw ex;
		}
		mapOfFriends.erase(name);
		numOfFriends--;
	}
	void removeFanPage(const string& name)
	{
		if (mapOfFansPage.find(name) == mapOfFansPage.end())
		{
			eror6 ex( this->name, name);
			throw ex;
		}
		mapOfFansPage.erase(name);
		numOfFanPage--;

	}

	//print functions
	void printAllStatus() const;
	void print10Status() const;//print 10 most recent status.
	void print10StatusOfEachFriend() const;
	void printAllFriends() const;



	//void print() const
	//{
	//	cout << name;
	//}

	void printName()
	{
		cout << name;
	}

	//get functions
	string getName()
	{
		return name;
	}



	//small functions to make the code more readble
	void getFriendsName(string& name);
	void getFansPageName(string& name);



	//operators

	bool operator>(const Friend& fr)
	{
		return this->numOfFriends >= fr.numOfFriends;


	}
	bool operator>(const FansPage& fansPage);

	bool operator==(const Friend& fr)
	{
		return this->name == fr.name;
	}
	bool operator!=(const Friend& fr)
	{
		return !(this->name == fr.name);
	}
	Friend& operator+=(const Friend& fr)
	{
		Friend* newFriendPtr = new Friend(fr.name);
		*newFriendPtr = fr;
		needTodeDelete.push_back(fr.name);
		this->addFriend(fr.name, newFriendPtr);
	}

	Friend& operator=(const Friend& fr)
	{
		name = fr.name;
		vectorOfStatus = fr.vectorOfStatus;
		numOfStatus = fr.numOfStatus;
		statusLogicalSize = fr.statusLogicalSize;
		numOfFriends = fr.numOfFriends;
		numOfFanPage = fr.numOfFanPage;
		mapOfFriends = fr.mapOfFriends;
		mapOfFansPage = fr.mapOfFansPage;
		return *this;
	}

	bool hasName(string name);

};