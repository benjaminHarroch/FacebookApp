#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "FansPage.h"
#include "Status.h"
#include "Friend.h"
#include <map>
#include "Exeption1.h"
using namespace std;

class Control
{
	map< string, Friend*> mapOfFriends;
	int numOfFriends = 0;
	

	map< string,  FansPage*> mapOfFansPage;
	int numOfFanPage = 0;



public:

	//constractor
	Control();

	//discractor
	~Control();
	
	


	//add fucntions
	void addFriend( const string& name)noexcept(false)
	{
		if (mapOfFriends.find(name) != mapOfFriends.end())
		{
			eror1 ex( name);
			throw ex;
		}
		numOfFriends++;
		Friend*newFriend = new Friend(name);
		string temp = name;
		mapOfFriends.insert({ temp ,newFriend });
	}
	void addFansPage(  const string& name)noexcept(false)
	{

		if (mapOfFansPage.find(name) != mapOfFansPage.end())
		{
			eror1 ex( name);
			throw ex;
		}
		numOfFanPage++;
		FansPage* newFansPage = new FansPage(name);
		
		mapOfFansPage.insert({ name,  newFansPage });

	}

	//print fucntions
	void printFriendsWithIndex()const;
	void printFriendsWithIndexWithoutspecificIndex(int index)const;
	void printFansPagesWithIndex()const;
	void printFriendsWithIndexWithouTheFriendsOfTheFansPage(FansPage* fansPage)const;//for function 8
	void printFriendsWithIndexWithouTheFriendsOfTheFriend(Friend* friend1)const;

	//small functions to make the code more readble
	void addStatusToAFriend(const string&);
	void addStatusToAFansPage(const string&);
	void getFriendsName( string& name);
	void getFansPageName( string& name);
	
	//manu fanctions
	void function1AddFriend();
	void function2AddFansPage();
	void function3AddStatus();
	void function4AllStatus();
	void function5TenStatus();
	void function6Connection();
	void function7Delete();
	void function8AddFriendToFansPage();
	void function9RemoveFriendFromFansPage();
	void function10PrintAllObjects()const;
	void function11PrintAllFriendsOfASpecificObject();

	int  menu();
	
};