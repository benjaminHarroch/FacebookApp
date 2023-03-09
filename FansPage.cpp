#include "FansPage.h"

//add functions
void FansPage::addStatus(const string& str)
{
	Status* newStatus = new Status(str);
	numOfStatus++;
	if (numOfStatus == statusLogicalSize)
	{
		statusLogicalSize *= 2;
		vectorOfStatus.resize(statusLogicalSize);
		vectorOfStatus[numOfStatus - 1] =newStatus;
	}
	else
	{
		vectorOfStatus[numOfStatus - 1] =newStatus;
	}
}





//print fanctions

void FansPage::printAllStatus() const
{
	int i;
	if (numOfStatus == 0)
		cout << "their are no status for this fans page\n";
	for (i = 0; i < numOfStatus; i++)
	{
		vectorOfStatus[i]->printStatus();
		cout << "\n";
	}
}

void FansPage::printAllFriends()const
{ 

	if (numOfFriends == 0)
	{
		cout << "their are no friends for this fans page\n";
		return;
	}
	auto it = mapOfFriends.begin();
	for (it; it != mapOfFriends.end(); it++)
		cout << it->first;
}


//small functions
void FansPage::getFriendsName(string& name1)
{
	if (numOfFriends == 0)
	{
		eror9 ex( name, this->name);
		throw ex;
	}
	cout << "please enter  a friend's name who is friend of: " << name << "\n";
	cin >> name;
	if (mapOfFriends.find(name1) == mapOfFriends.end())
	{
		eror9 ex( name, this->name);
		throw ex;
	}

}

//operator
FansPage& FansPage:: operator+=(const Friend & fr)
{
	Friend* newFriendPtr = new Friend(fr.name);
	*newFriendPtr = fr;
	needTodeDelete.push_back(fr.name);

	this->addFriend(fr.name, newFriendPtr);
	return *this;
}

bool FansPage::operator>(const Friend& fr)
{
	return this->numOfFriends >= fr.numOfFriends;


}

bool FansPage::hasName(string name)
{
	for (int i = 0; i < needTodeDelete.size(); i++)
	{
		if (needTodeDelete[i] == name)
			return true;
	}
	return false;
}