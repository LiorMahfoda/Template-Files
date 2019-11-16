/* Assignment: 6 – Part Template 
Campus: Beer Sheva 
Author: Lior Mahfoda, ID: 302782230 
Date: 26/05/2014*/

#ifndef TEMPLATEFUNCTIONS_H
#define TEMPLATEFUNCTIONS_H
#include "Rational.h" // Class Rational included
#include <string>

	// Declarations //

/*-----------------------------------------------------------------------------
   Name:  template function "MaxValue"

   Purpose:  returns the maximum value in the array
   Receive:  void type array and size of it
-----------------------------------------------------------------------------*/
template <class T>
T MaxValue (T* arr,int size);

/*-----------------------------------------------------------------------------
   Name:  bool template funtaion "ExistValue"

   Purpose:  returns true if value is in the array, else returns false
   Receive:  array, size and value to search
-----------------------------------------------------------------------------*/
template <class T>
bool ExistValue(T value,T* arr,int size);

	 // Implimintation //


template <class T>
T MaxValue (T* arr,int size) 
{
	T temp = arr[0];
	for (int i=1; i<size; i++)
		if (arr[i] > temp)
			temp = arr[i];
	return temp;
}

template <class T>
bool ExistValue(T value,T* arr,int size)
{
	for (int i=0; i<size; i++)
		if (arr[i] == value)
			return true; // if value exists
	return false; // otherwise default of false
}

#endif TEMPLATEFUNCTIONS_H