#include "Control.h"



//constractor]

Control::Control()
{

	this->addFriend("idan");
	this->addFriend("binyamin");
	this->addFriend("iris");



	

	this->addFansPage("page1");
	this->addFansPage("page2");
	this->addFansPage("page3");

	this->mapOfFriends["idan"]->addStatus("Status1");
	this->mapOfFriends["idan"]->addStatus("Status2");
	this->mapOfFriends["binyamin"]->addStatus("Status3");
	this->mapOfFriends["binyamin"]->addStatus("Status4");
	this->mapOfFriends["iris"]->addStatus("Status5");
	this->mapOfFriends["iris"]->addStatus("Status6");

	this->mapOfFriends["idan"]->addFansPage("page1", mapOfFansPage["page1"]);
	this->mapOfFriends["binyamin"]->addFansPage("page2", mapOfFansPage["page2"]);
	this->mapOfFriends["iris"]->addFansPage("page3", mapOfFansPage["page3"]);

	this->mapOfFriends["idan"]->addFriend("iris", mapOfFriends["iris"]);
	this->mapOfFriends["binyamin"]->addFriend("idan", mapOfFriends["binyamin"]);
	this->mapOfFriends["iris"]->addFriend("binyamin", mapOfFriends["binyamin"]);
	this->mapOfFansPage["page1"]->addFriend("idan", mapOfFriends["idan"]);
	this->mapOfFansPage["page2"]->addFriend("binyamin", mapOfFriends["binyamin"]);
	this->mapOfFansPage["page3"]->addFriend("iris", mapOfFriends["iris"]);

}

//print functions









//manu fanctions

void Control::function1AddFriend()
{
	cin.ignore(); //"ingore the enter key"
	string name;
	cout << "please enter the friend's name \n";
	cin >> name;
	try 
	{
		addFriend(name);
	}
	catch (eror1 ex)
	{
		ex.print();
	}

	
}



void Control::function2AddFansPage()
{
	cin.ignore(); //"ingore the enter key"
	string name;
	cout << "please enter the fansPage's name \n";
	cin >> name;
	try 
	{
		addFansPage(name);		
	}
	catch (eror1 ex)
	{
		ex.print();
	}
}




void Control::function3AddStatus()
{
	cin.ignore(); //"ingore the enter key"
	string statusText;
	cout << "please enter the status\n";
	cin >> statusText;
	
	int answer;
	cout << "do you want to add status to fans page or a friend?\n";
	cout << "1.friend\n" << "2.fans page" << endl;

	cin >> answer;
	if (answer == 1)
	{

		try
		{
			addStatusToAFriend(statusText);
		}
		catch (eror10 ex)
		{
			ex.print();
		}
		
	}

	else if (answer == 2)
	{
		
		try
		{
		 addStatusToAFansPage(statusText);		
		}
		catch (eror10 ex3)
		{
			ex3.print();
		}
		
	}

}


void Control::function4AllStatus()
{
	//clean buffer
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int answer = 1;
	cout << " do you want to show all status of a friend or of a fans page?\n";
	cout << " 1.friend\n 2.fans page\n";
	cin >> answer;
	string name;

	if (answer == 1)
	{
		try 
		{
			getFriendsName(name);
			mapOfFriends[name]->printAllStatus();
		}
		catch (eror10 ex3)
		{
			ex3.print();
		}
			
	}
	else if (answer == 2)
	{
		try
		{
			getFansPageName(name);
			mapOfFansPage[name]->printAllStatus();
		}
		catch (eror10 ex2)
		{
			ex2.print();
		}

	}
}

void Control::function5TenStatus()
{
	//clean buffer
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string name;
	try 
	{
		getFriendsName(name);
		mapOfFriends[name]->print10Status();
	}
	catch(eror10 ex)
	{
		ex.print();
	}
}

void Control::function6Connection()
{
	string name1, name2;
	bool succses = false;
	try
	{
		getFriendsName(name1);
		getFriendsName(name2);
		mapOfFriends[name1]->addFriend(name2, mapOfFriends[name2]);
		mapOfFriends[name2]->addFriend(name1, mapOfFriends[name1]);
	}
	catch (eror10 ex)
	{
		ex.print();
	}
	catch (eror3 ex1)
	{
		ex1.print();
	}
	
}


void Control::function7Delete()
{
	string name1, name2;
	try
	{
		getFriendsName(name1);
		mapOfFriends[name1]->getFriendsName(name2);
		mapOfFriends[name1]->removeFriend(name2);
		mapOfFriends[name2]->removeFriend(name1);
	}
	catch (eror10 ex)
	{
		ex.print();
	}
	catch (eror4 ex)
	{
		ex.print();
	}
	catch (eror2 ex)
	{
		ex.print();
	}
}



void Control::function8AddFriendToFansPage()
{
	//problem with the catch
	string friendsName, FansPageName;
	try
	{
		getFriendsName(friendsName);
	}
	catch (eror10 ex)
	{
		ex.print();
	}
	try
	{
		getFansPageName(FansPageName);
		mapOfFriends[friendsName]->addFansPage(FansPageName,mapOfFansPage[FansPageName]);
		mapOfFansPage[FansPageName]->addFriend(friendsName, mapOfFriends[friendsName]);
	}
    
	catch (eror10 ex1)
	{
		ex1.print();
	}
	catch (eror3 ex1)
	{
		ex1.print();
	}


}

void Control::function9RemoveFriendFromFansPage()
{
	string fanPageName, friendName;
	try
	{
		getFansPageName(fanPageName);
		mapOfFansPage[fanPageName]->getFriendsName(friendName);
		mapOfFansPage[fanPageName]->removeFriend(friendName);
	}
	catch (eror1 ex1)
	{
		ex1.print();
	}
	catch (eror9 ex1)
	{
		ex1.print();
	}
}

void Control::function10PrintAllObjects()const
{
	cout << "the friends are:\n";
	auto it = mapOfFriends.begin();
	for (it; it != mapOfFriends.end(); it++)
		cout << it->first <<",";

	cout << "\nthe fans pages are:\n";
	auto it1 = mapOfFansPage.begin();
	for (it1; it1 != mapOfFansPage.end(); it1++)
		cout << it1->first<<",";
	cout << "\n";
}


int  Control::menu()
{
	int answer;
	cout << " 1.addFriend\n 2.add fans page\n 3.add status\n 4.present all status\n 5.present 10 most recent status\n 6.connection between friends\n 7.delete friendship between friens'n\n";
	cout << " 8.add friend to fans page\n 9.remove friend from fans page\n 10.present all the objeces in the system\n 11.prest all the friend of an object\n 12.exit\n";
	cout << " please choose an action: ";
	cin >> answer;
	
	switch (answer)
	{
	case 1:
		function1AddFriend();
		if(menu()==1)
			break;
	case 2:
		function2AddFansPage();
		if (menu() == 1)
			break;
	case 3:
		function3AddStatus();
		if (menu() == 1)
			break;
	case 4:
		function4AllStatus();
		if (menu() == 1)
			break;
	case 5:
		function5TenStatus();
		if (menu() == 1)
			break;
	case 6:
		function6Connection();
		if (menu() == 1)
			break;
	case 7:
		function7Delete();
		if (menu() == 1)
			break;
	case 8:
		function8AddFriendToFansPage();
		if (menu() == 1)
			break;
	case 9:
		function9RemoveFriendFromFansPage();
		if (menu() == 1)
			break;
	case 10:
		function10PrintAllObjects();
		if (menu() == 1)
			break;
	case 11:
		function11PrintAllFriendsOfASpecificObject();
		if (menu() == 1)
			break;
	case 12:
		cout << "get out from the application";
		return 1;
	default:
		cout << "please choose a correct number of action\n";

	}


}


// small functions
void Control::addStatusToAFriend(const string& statusStr)
{

	string name;
	cout << "please enter  a friend's name\n";
	cin >> name;
	if (mapOfFriends.find(name) == mapOfFriends.end())
	{
		eror10 ex(name);
		throw ex;
	}
	else
	{
		mapOfFriends[name]->addStatus(statusStr);
	}


}

void Control::addStatusToAFansPage(const string& statusStr)
{

	string name;
	cout << "please enter  a fansPage's name\n";
	cin >> name;
	if (mapOfFansPage.find(name) == mapOfFansPage.end())
	{
		eror10 ex( name);
		throw ex;
	}
	else
	{
		mapOfFriends[name]->addStatus(statusStr);
	}


}

void Control::getFriendsName( string& name)
{
	bool succses = false;
	
	cout << "please enter  a friend's name\n";
	cin >> name;
	if (mapOfFriends.find(name) == mapOfFriends.end())
	{
		eror10 ex( name);
		throw ex;
	}
		
}

void Control::getFansPageName(string& name)
{
	
	cout << "please enter  a FansPage's name\n";
	cin >> name;
	if (mapOfFansPage.find(name) == mapOfFansPage.end())
	{
		eror10 ex( name);
		throw ex;
	}
	
}

void Control::function11PrintAllFriendsOfASpecificObject()
{
	int answer = 1;
	cout << " do you want to show all friend of a friend or of a fans page?\n";
	cout << " 1.friend\n 2.fans page\n";
	cin >> answer;
	string name;

	if (answer == 1)
	{
		try
		{
			getFriendsName(name);
			mapOfFriends[name]->printAllFriends();
		}
		catch (eror10 ex)
		{
			ex.print();
		}
	}
	if (answer == 2)
	{
		try
		{
			getFansPageName(name);
			mapOfFansPage[name]->printAllFriends();
		}
		catch(eror10 ex1)
		{
			ex1.print();
		}
	}
}

Control:: ~Control()
{
	auto it = mapOfFriends.begin();
	for (it; it != mapOfFriends.end(); it++)
	{
		//free al status
		for (Status* i : it->second->vectorOfStatus)
			delete(i);
 
		    //if we have 2 copies of friend. one in friend object and the other in control
			for (int i = 0; i < it->second->needTodeDelete.size(); i++)
			{
				delete it->second -> mapOfFriends[it->second->needTodeDelete[i]];
			}
		
		
		delete(it->second);//free the object
	}

	auto it1 = mapOfFansPage.begin();
	for (it1; it1 != mapOfFansPage.end(); it1++)
	{
		//free al status
		for (Status* i : it1->second->vectorOfStatus)
			delete(i);

		for (int i = 0; i < it1->second->needTodeDelete.size(); i++)
		{
			delete it1->second->mapOfFriends[it1->second->needTodeDelete[i]];
		}
		delete(it1->second);//free the object
	}
}