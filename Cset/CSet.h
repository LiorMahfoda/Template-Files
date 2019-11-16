/* Assignment: 6 – Part Template 
Campus: Beer Sheva 
Author: Lior Mahfoda, ID: 302782230 
Date: 26/05/2014*/

#ifndef CSET_H
#define CSET_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // I/O libary
using namespace std;
#include <assert.h> // Allocation check

	// Declatarions //
template <class T>
class CSet
{
	// Private //
	T* arr;
	int size;

	public:
/*-----------------------------------------------------------------------------
   Name:  Found method

   Purpose:  help method to see if T value is in a group
   Receive:  template T value
-----------------------------------------------------------------------------*/
	bool Found(T);
/*-----------------------------------------------------------------------------
   Name:  constructor for class "CSET"

   Purpose:  sets default values
   Receive:  none
-----------------------------------------------------------------------------*/
	CSet(){ arr = NULL, size = 0 ;};

/*-----------------------------------------------------------------------------
   Name:  copy constructor for class "CSET"

   Purpose:  copy an object of a template
   Receive:  const class "CSET" by reference 
-----------------------------------------------------------------------------*/
	CSet(const CSet<T>& other);

/*-----------------------------------------------------------------------------
   Name:  distructor for class "CSET"

   Purpose:  deletes the template group
   Receive:  none
-----------------------------------------------------------------------------*/
	~CSet(){ delete[] arr;};

/*-----------------------------------------------------------------------------
   Name:  assign opeartor = for class "CSET"

   Purpose:  assign the template group into another one
   Receive:  CSET class by reference
-----------------------------------------------------------------------------*/
	CSet<T>& operator = (const CSet<T>);

/*-----------------------------------------------------------------------------
   Name:  add opeartor += for class "CSET"

   Purpose:  adding a value to the group if doesn't exist
   Receive:  template value and size of the dynamic array
-----------------------------------------------------------------------------*/
	CSet<T>& operator += (T);

/*-----------------------------------------------------------------------------
   Name:  sub opeartor -= for class "CSET"

   Purpose:  subtract a value from the group if exist
   Receive:  template value and size of the dynamic array
-----------------------------------------------------------------------------*/
	CSet<T>& operator -= (T);

/*-----------------------------------------------------------------------------
   Name:  operator - for class "CSET"

   Purpose:  return template group of things that are in base group but noy in parameter group
   Receive:  const template group  
-----------------------------------------------------------------------------*/
	CSet<T> operator - (CSet<T>&);

/*-----------------------------------------------------------------------------
   Name:  operator << for class "CSET"

   Purpose:  print the entire group
   Receive: ostream class,template const group  
-----------------------------------------------------------------------------*/
	friend ostream& operator << <T>( ostream& os, const CSet<T>&);  

/*-----------------------------------------------------------------------------
   Name:  Union method for class "CSET"

   Purpose:  unite all values into one group
   Receive:  template group  
-----------------------------------------------------------------------------*/
	CSet<T> Union(CSet<T>&);

/*-----------------------------------------------------------------------------
   Name:  Union method for class "CSET"

   Purpose:  unite all values into one group
   Receive:  template group  
-----------------------------------------------------------------------------*/
	CSet<T> Intersect(CSet<T>&);

}; // End class CSET
	// Implemntaion //

template <class T>
bool CSet<T>::Found(T val)
{
	for (int i=0; i<size; i++)
		if (arr[i] == val)
			return true;
	return false;
}

template <class T>
CSet<T>::CSet(const CSet<T>& other)
	{
		arr = new T[other.size];
		assert(arr);
		for (int i=0; i<other.size;i++)
			arr[i] = other.arr[i];
		this->size = other.size;
	}

template <class T>
CSet<T>& CSet<T>::operator = (const CSet<T> other)
{
	delete[] this->arr;
	arr = new T[other.size];
	assert(arr);
	for (int i=0; i<other.size;i++)
		arr[i] = other.arr[i];
	this->size = other.size;
	return *this;
}

template <class T>
CSet<T>& CSet<T>::operator += (T val)
{
	bool temp = Found(val); 
	if (!temp) // value doesn't exist in group
		{
			T* help = new T[size+1]; // help array
			assert(help);
			for (int i = 0; i < size ; i++)
				help[i] = arr[i]; // copy values	
			help[size] = val;
			delete[] arr; // delete original
			arr = help; // change pointers
			size++; // increment
		} // end if

	return *this;
} // end operator

template <class T>
CSet<T>& CSet<T>::operator -= (T val)
{
	if (Found(val))
	{
		if (size!=0 && size!=1)
		{
			T* tmp = new T[size-1]; // help array
			int index = 0;
			assert(tmp);
			for (int i=0; i < size ;i++)
				if (arr[i] != val) // if value found in group
				{
					tmp[index] = arr[i]; // copy values
					index++; // next location
				}
		delete arr; // delete original
		arr = tmp; // change pointers
		size--; // reduce size
		} //end if
	else
		if (size == 1)
		{
			delete[] arr;
			arr = NULL;
			size--;
 		} //end if
	} // end if

	return *this;
} // end operator

template <class T>
CSet<T> CSet<T>::Union(CSet<T>& other)
{
	CSet temp(*this);
	for(int i=0; i<other.size; i++) 
		temp += other.arr[i];
	return temp;
}

template <class T>
CSet<T> CSet<T>::Intersect(CSet<T>& other)
{
	CSet temp;	
	for (int i=0; i <size ; i++)
		if (this->Found(other.arr[i]))
			temp += other.arr[i];
	return temp;
}

template <class T>
CSet<T> CSet<T>::operator - (CSet<T>& other) 
{
	CSet temp;
	CSet tmp(other);
	for(int i=0; i<size; i++)
		if(this->Found(arr[i]) && !tmp.Found(arr[i])) //
			temp += arr[i];
	return temp;
}
template <class T>
ostream& operator<<( ostream& os, const CSet<T>& group)
{
	for (int i=0; i<group.size; i++)
		os<<group.arr[i]<<" ";
	os<<endl;
	return os;
}
#endif CSET_H
