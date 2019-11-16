/* Assignment: 6 – Part Template 
Campus: Beer Sheva 
Author: Lior Mahfoda, ID: 302782230 
Date: 26/05/2014*/

#ifndef MENU_H
#define MENU_H
#include "CSet.h"
#include <string>
typedef enum { LONG = 1, CHAR1 = 2, CHAR2 = 3, STRING = 4} choice;
typedef enum { ADD = 1, REMOVE = 2, UNION = 3, INTERSECT = 4, DIFFERENCE = 5, PRINT = 6, EXIT = 7} option;

 // Declarations //

class Menu
{
	// Private //
	CSet<long> longs;
	CSet<char> tavs1;
	CSet<char> tavs2;
	CSet<string> strings; 

	public:
/*-----------------------------------------------------------------------------
   Name:  constructor for class "Menu"

   Purpose:  sets default values
   Receive:  none
-----------------------------------------------------------------------------*/
		Menu();
/*-----------------------------------------------------------------------------
   Name:  disstructor for class "Menu"

   Purpose:  
   Receive:  none
-----------------------------------------------------------------------------*/
		~Menu(){ };  
/*-----------------------------------------------------------------------------
   Name:  void method "AddElement" for class "Menu"

   Purpose:  add value to array
   Receive:  none
-----------------------------------------------------------------------------*/
		void AddElement();
/*-----------------------------------------------------------------------------
   Name:  void method "RemoveElement" for class "Menu"

   Purpose:  remove value from array
   Receive:  none
-----------------------------------------------------------------------------*/
		void RemoveElement();
/*-----------------------------------------------------------------------------
   Name:  void method "Union" for class "Menu"

   Purpose:  union 2 char groups to one with all values
   Receive:  none
-----------------------------------------------------------------------------*/
		void Union();
/*-----------------------------------------------------------------------------
   Name:  void method "Intersect" for class "Menu"

   Purpose:  intersect 2 char groups into one with share values
   Receive:  none
-----------------------------------------------------------------------------*/
		void Intersect();

/*-----------------------------------------------------------------------------
   Name:  void method "Difference" for class "Menu"

   Purpose:  all values that are in the base group bot not in parameter group: user input
   Receive:  none
-----------------------------------------------------------------------------*/
		void Difference();

/*-----------------------------------------------------------------------------
   Name:  void method "Print" for class "Menu"

   Purpose:  intersect 2 char groups into one with share values
   Receive:  none
-----------------------------------------------------------------------------*/
		void Print();
};

#endif MENU_H


















