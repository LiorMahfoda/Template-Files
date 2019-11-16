/* Assignment: 6 – Part files
Campus: Beer Sheva 
Author: Lior Mahfoda, ID: 302782230 
Date: 26/05/2014*/

#ifndef STUDENT_H
#define STUDENT_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // I/O libary
using namespace std;
#include <assert.h> // Allocation check
#include <string>
typedef enum {UNKNOWN = 0,MALE = 1, FEMALE = 2} Gender;
const int SIZE = 10;
#define min 0.2
#define max 0.8
class Student
{
	short Id; // student's id
	char* First; // student's first name
	short Num_first;
	char* Last; // student's last name
	short Num_sec;
	const char* Sex; // male / female
	int Middle; // middle test grade
	int Final; // final exam grade
	float Grade; // final course grade
	public:
		Student();
		Student(int id, char*, char*,char*,int ,int);
		Student(const Student& other);
		~Student();
		char* GetFirst(){ return First ;};
		char* GetLast(){ return Last ;};
		short SetFirst(){ return strlen(First);};
		short SetLast(){ return strlen(Last);};
		Student& operator = (const Student);
		friend ostream& operator <<(ostream&,const Student&);
		friend istream& operator >>(istream&,Student& stu);

};

#endif STUDENT_H
