#pragma once
#include "Status.h"
#include "Friend.h"
#include <vector>
#include <map>
#include "Exeption1.h"
class Friend;
class FansPage {


	string name;
    vector < Status*> vectorOfStatus;
	int numOfStatus = 0;
	int statusLogicalSize = 1;

	map<const string, Friend*> mapOfFriends;
	int numOfFriends = 0;

	vector<string>needTodeDelete;//the names we need to delete. this is for diitractor

	friend class Control;
	friend class Friend;
public:


	//constractor
	FansPage( string name1)
	{	
		name =  name1;
	}

	//distractor
	~FansPage() =  default;
	

	//add functions
	void addStatus(const string& str);
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

	//remove functions
	void removeFriend(const string& name)
	{
		if (mapOfFriends.find(name) != mapOfFriends.end())
		{
		    eror1 ex( name);
			throw ex;
		}
		mapOfFriends.erase(name);
		numOfFriends--;
	}

	//printFunctions
	void print()
	{
		cout << name;
	};
	void printAllStatus() const ;
	void printAllFriends() const ;
	void printAllFriendWithIndex() const;//for function 9;


	//get fucntions
	const string& getName() const
	{

		return name;
	}
	int getNumOfFriends() const
	{
		return numOfFriends;
	}


	//small functions
	void getFriendsName(string& name);
	int getNumOfFriends()
	{
		return numOfFriends;
	}



	//operators

	bool operator>(const Friend& fr);
	
	bool operator>(const FansPage& fansPage)
	{

		return this->numOfFriends >= fansPage.numOfFriends;
	};

	bool operator==(const FansPage& fan)
	{
		return this->name == fan.name;
	}
	bool operator!=(const FansPage& fan)
	{
		return !(this->name == fan.name);
	}
	FansPage& operator+=(const Friend& fr);
	

	FansPage& operator=(const FansPage& fan)
	{
		name = fan.name;
		vectorOfStatus = fan.vectorOfStatus;
		numOfStatus = fan.numOfStatus;
		statusLogicalSize = fan.statusLogicalSize;
		numOfFriends = fan.numOfFriends;
		mapOfFriends = fan.mapOfFriends;
	
		return *this;
	}
	bool hasName(string name);
};

