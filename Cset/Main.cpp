/* Assignment: 6 – Part Template 
Campus: Beer Sheva 
Author: Lior Mahfoda, ID: 302782230 
*/

#include "Menu.h"
				// Implimintation //
Menu::Menu()
{
	int pick = 0;
	do 
	{
		cout<<"Please enter 1 for add element to group"<<endl;
		cout<<"Please enter 2 for remove element from group"<<endl;
		cout<<"Please enter 3 for union 2 char groups"<<endl;
		cout<<"Please enter 4 intersect 2 char groups"<<endl;
		cout<<"Please enter 5 for difference between 2 char groups"<<endl;
		cout<<"Please enter 6 for print a group"<<endl;
		cout<<"Please enter 7 to exit the program"<<endl;
		cin>>pick;
		cout<<endl;
		
		switch (pick)
		{
			case ADD:
				AddElement();	
				break;

			case REMOVE:
				RemoveElement();
				break;

			case UNION:
				Union();
				break;
	
			case INTERSECT:
				Intersect();
				break;

			case DIFFERENCE:
				Difference();
				break;

			case PRINT:
				Print();
				break;

			case EXIT:
				exit(1); // exit the main program
		
			default:
				break;
		} // end switch case
		cout<<endl;
		}	while (pick != EXIT); // end do-while loop
} // end method


void Menu::AddElement()
{
	int decision; // for choice
	cout<<"Add choices"<<endl;
	cout<<"For long group press 1"<<endl;
	cout<<"For 1'st char group press 2"<<endl;
	cout<<"For 2'nd char group press 3"<<endl;
	cout<<"For string group press 4"<<endl;
	cin>>decision;
	cout<<endl;
	if (decision == LONG) // long group
	{
		long element;
		cout<<"Enter a long number to add: ";
		cin>>element;
		longs += element;
	} // end if
	else
		if (decision == CHAR1) // char group number 1
		{
			char element;
			cout<<"Enter a char to add: ";
			cin>>element;
			tavs1 += element;
		} // end else-if
			else // string group
				if (decision == CHAR2 ) // char group number 2
				{
					char element;
					cout<<"Enter a char to add: ";
					cin>>element;
					tavs2 += element;
				} // end else-if
				else 
					if (decision == STRING)
					{
						string element;
						cout<<"Enter a string to add: ";
						cin>>element;
						strings += element;	
					} // end else
} // end method

void Menu::RemoveElement()
{
	int decision; // for choice
	cout<<"Remove choices"<<endl;
	cout<<"For long group press 1"<<endl;
	cout<<"For 1'st char group press 2"<<endl;
	cout<<"For 2'nd string group press 3"<<endl;
	cout<<"For string group press 4"<<endl;
	cin>>decision;
	cout<<endl;

	if (decision == LONG) // long group
	{
		long element;
		cout<<"Enter a long number to remove:";
		cin>>element;
		longs -= element;
	} // end if
	else
		if (decision == CHAR1) // char group number 1
		{
			char element;
			cout<<"Enter a char to remove: ";
			cin>>element;
			tavs1 -= element;
		} // end else-if
			else // string group
				if (decision == CHAR2) // char group number 2
				{
					char element;
					cout<<"Enter a char to remove: ";
					cin>>element;
					tavs2 -= element;
				} // end else-if
				else // string group
				
					if (decision == STRING)
					{
						string element;
						cout<<"Enter a string to remove: ";
						cin>>element;
						strings -= element;	
					} // end else-if
}// end method

void Menu::Union()
{
	cout<<"The result union of 2 char group is: "<<endl;
	cout<<tavs1.Union(tavs2);
} // end method

void Menu::Intersect()
{
	cout<<"The result intersect of 2 char group is: "<<endl;
	cout<<tavs1.Intersect(tavs2);
} // end method

void Menu::Difference()
{
	int choice1,choice2;
	cout<<"Difference choices"<<endl;
	cout<<"Pick you choice of base group"<<endl;
	cout<<"For char group number 1 press 2"<<endl;
	cout<<"For char group number 2 press 3"<<endl;
	cin>>choice1;
	cout<<endl;
	cout<<"Pick you choice of parameter group"<<endl;
	cout<<"For char group number 1 press 2"<<endl;
	cout<<"For char group number 2 press 3"<<endl;
	cin>>choice2;
	cout<<endl;
	if (choice1 == CHAR1) //1'st pick //base group
	{
		if (choice2 == CHAR2) //base group
			cout<< tavs1-tavs2<<endl;
		else // parameter group
			cout<< tavs1-tavs1<<endl;
	} // end if
	else //2'nd pick  // base group
		if (choice2 == CHAR2) // parameter group
			cout<< tavs2-tavs2<<endl;
		else
			cout<< tavs2-tavs1<<endl;
			 // base group
} // end method


void Menu::Print()
{
	//typedef enum { LONG = 1, CHAR1 = 2, CHAR2 = 3, STRING = 4} Choice;
	int choice;
	cout<<"Print choices"<<endl;
	cout<<"For long group press 1"<<endl;
	cout<<"For 1'st char group press 2"<<endl;
	cout<<"For 2'nd string group press 3"<<endl;
	cout<<"For string group press 4"<<endl;
	cin>>choice;
	cout<<endl;
	if (choice == LONG) // long
		cout<<longs;
	else
		if (choice == CHAR1) // char number 1
			cout<<tavs1;
		else
			if (choice == CHAR2) // char number 2
				cout<<tavs2;
			else // string
				if (choice == STRING)
					cout<<strings;
} // end method

