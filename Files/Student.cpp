/* Assignment: 6 – Part files
Campus: Beer Sheva 
Author: Lior Mahfoda, ID: 302782230 
*/

#include "Student.h"

Student::Student()
{
	Id = 0; Num_first = 0; Num_sec = 0;
	First = NULL; Last = NULL;
	Sex = "Unknown";
	Middle = 0; Final = 0; Grade = 0;
}

Student::Student(int id, char* first, char* last,char* sex,int middle,int final)
{
	Id = id;
	First = first;
	Num_first = strlen(first);
	Last = last;
	Num_sec = strlen(last);
	Sex = sex;
	Middle = middle;
	Final = final;
	Grade = (float)(max*Final + min*Middle);
}
Student::Student(const Student& other)
{
	First = new char[strlen(other.First)+1];								
	assert(First);													   		
	Last = new char[strlen(other.Last)+1];					    	
	assert(Last);												 			

	strcpy(First, other.First);													
	strcpy(Last, other.Last); 
	Sex = other.Sex;
	Id = other.Id;
	Middle = other.Middle;
	Final = other.Final;
	Grade = other.Grade;
}

Student::~Student()
{
	delete[] First;
	delete[] Last;
}

ostream& operator <<(ostream& os,const Student& stu)
{
	os<<stu.Id<<endl;
	os<<stu.Sex<<endl;
	os<<stu.First<<endl;
	os<<stu.Last<<endl;
	os<<stu.Middle<<endl;
	os<<stu.Final<<endl;
	os<<stu.Grade<<endl;
	cout<<endl;

	return os;
}

istream& operator >> (istream& in,Student& stu)
{
	char first[SIZE+1]; char last[SIZE+1];
	int gender;
	cout<<"Enter id: "; cin>>stu.Id;
	while (stu.Id<=999 || stu.Id >9999)
	{
		cout<<"Enter id: "; 
		cin>>stu.Id;
	}
	cout<<"Enter gender: 1 for male, 2 for female: ";
	cin>> gender;
	while (gender>2 ||gender <=0)
	{
		cout<<"Enter gender: 1 for male, 2 for female: ";
		cin>> gender;
	}
	if (gender == 1)
		stu.Sex = "male";
	else
		if (gender == 2)
			stu.Sex = "female";
	cout<<"How many chars in first name? "; 
	in>> stu.Num_first;
	while( stu.Num_first<=0 ||stu.Num_first>SIZE)
	{
		cout<<endl;
		cout<<"How many chars in first name?";
		in>> stu.Num_first;
	} // end while
	cout<<"Enter first name: "; in>>first; 
	stu.First = new char[stu.Num_first+1];
	assert(stu.First);
	strcpy(stu.First,first);
	cout<<"How many chars in last name? ";
	in>>stu.Num_sec;
	while( stu.Num_sec<=0 ||stu.Num_sec>SIZE)
	{
		cout<<endl;
		cout<<"How many chars in last name? ";
		in>>stu.Num_sec;
	}
	cout<<"Enter last name: "; 
	in>>last;
	stu.Last = new char[stu.Num_sec+1];
	assert(stu.Last);
	strcpy(stu.Last,last);
	cout<<"Enter middle grade: "; in>>stu.Middle;
	cout<<"Enter final grade: "; in>>stu.Final;
	stu.Grade = (float)(max*stu.Final + min*stu.Middle);

	return in;
}

Student& Student::operator = (const Student other)
{
	First = new char[strlen(other.First)];								
	assert(First);													   		
	Last = new char[strlen(other.Last)];					    	
	assert(Last);												 			
	strcpy(First, other.First);													
	strcpy(Last, other.Last); 
	Sex = other.Sex;
	Id = other.Id;
	Middle = other.Middle;
	Final = other.Final;
	Grade = other.Grade;
	return *this;
}