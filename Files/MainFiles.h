/* Assignment: 6 – Part files
Campus: Beer Sheva 
Author: Lior Mahfoda, ID: 302782230 
Date: 26/05/2014*/

#ifndef MainFiles_h
#define MainFiles_h
#include <fstream> // Read & write files libary // ofstream,ifstream classes
typedef enum { PRINT = 1,SORT = 2, AVREAGE = 3,EXIT = 4} Option;
typedef enum { ORIGINAL = 1, SORTED = 2} Sort;
class MainFiles
{
	Student* arr; // array of students
	int NumOfStudents; // number of students extracted from file "Students.data"

	public:
		MainFiles(); // c'tor
		MainFiles(const MainFiles&); // copy c'tor
		~MainFiles(); // d'tor
		void Average(); // method calculates Avreage of all student's grades
		void Sort(); // sort array and make a new file
		void Run(); // method run the menu and the options

};

#endif MainFiles_h
