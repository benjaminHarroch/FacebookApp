#include "Friend.h"


//add functions
//get reference for avoid get NULL status
void Friend::addStatus( const string& str)
{
	Status* newStatus = new Status(str);
	numOfStatus++;
	if (numOfStatus == statusLogicalSize)
	{
		statusLogicalSize *= 2;
		vectorOfStatus.resize(statusLogicalSize);
		vectorOfStatus[numOfStatus-1] = newStatus;
	}
	else
	{
		vectorOfStatus[numOfStatus-1] = newStatus;
	}
	
}



//need to look one time again for this function---need to fix
  // |
  // |
  // |
 // \ /
 //  V
//remove functions



//print functions
void Friend::print10Status() const
{
	int i;
	
	for (i = 1; i <= 10; i++)
	{
		if ((numOfStatus - i) < 0)
			break;
		vectorOfStatus[numOfStatus - i]->printStatus();
		cout << "\n";
	    
	}
}

void Friend::print10StatusOfEachFriend() const
{
	

	if (numOfFriends == 0) {
		cout << name << "have no friend \n";
		return;
	}

	auto it = mapOfFriends.begin();
	for (it; it != mapOfFriends.end(); it++)
		it->second->print10Status();
}

void Friend::printAllFriends() const
{
	auto it = mapOfFriends.begin();
	for (it; it != mapOfFriends.end(); it++)
		cout << it->first<<"\n";
}

void Friend::printAllStatus() const
{
	int i;
	if (numOfStatus==0)
		cout << "their are no status for this friend\n";
	for (i = 0; i < numOfStatus; i++)
	{
		vectorOfStatus[i]->printStatus();
		cout << "\n";
	}
}


//small functions
void Friend::getFriendsName(string& name1)
{
	if (numOfFriends == 0)
	{
	    eror4 ex( name);
		throw ex;
	}
    cout << "please enter  a friend's name who is friend of: "<<name<<"\n";
	cin >> name;
	if (mapOfFriends.find(name1) == mapOfFriends.end())
		throw name1;
	
}
void Friend::getFansPageName(string& name1)
{
	if (numOfFanPage == 0)
	{
		eror7 ex(name);
		throw ex;
	}
	cout << "please enter  a fansPage's name who is friend of: " << name << "\n";
	cin >> name;
	if (mapOfFansPage.find(name1) == mapOfFansPage.end())
		throw name1;

}

bool Friend:: operator>(const FansPage& fansPage)
{
	return this->numOfFriends >= (fansPage.getNumOfFriends());


}


bool Friend::hasName(string name)
{
	for (int i = 0; i < needTodeDelete.size(); i++)
	{
		if (needTodeDelete[i] == name)
			return true;
	}
	return false;
}