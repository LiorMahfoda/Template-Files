/* Assignment: 6 – Part files
Campus: Beer Sheva 
Author: Lior Mahfoda, ID: 302782230 
*/

#include "Student.h"
#include "MainFiles.h"

void main()
{
	MainFiles m;
	m.Run();

}

MainFiles::MainFiles()
{
	int index = 0,i = 0;
	arr = NULL; 
	ofstream InFile("students.data",ios::app); // open/create file
	if (InFile.is_open()) // couldn't open 
	{
		cout<<"How many students would you like to save? press 0 to only read from file"<<endl<<endl;
		cin>>NumOfStudents;
		if (NumOfStudents!=0)
		{
			InFile<<NumOfStudents<<" "<<endl;
			arr = new Student[NumOfStudents];
			while (index!=NumOfStudents)
			{
			cin>>arr[index]; // getting info of students
			InFile<<arr[index]; // write to file the student's info
			cout<<endl;
			index++;
			}
			InFile<<endl;
		}
		InFile.close();
		ifstream InFile("students.data",ios::in);
		string temp;
		getline(InFile,temp);
		NumOfStudents = stoi(temp);
		InFile.close();
	}
	else // file exist
	{
		ifstream InFile("students.data",ios::beg);
		string str;
		getline(InFile,str);
		while (getline(InFile,str))
		{
			string str;
			getline(InFile,str);
			for (int i = 0;!InFile.eof();i++)
			{
				short id = stoi(str);
				getline(InFile,str);
				const char* name1 = str.c_str();
				getline(InFile,str);
				const char* name2 = str.c_str();
				getline(InFile,str);
				const char* sex = str.c_str();
				getline(InFile,str);
				int num2 = stoi(str);
				getline(InFile,str);
				int num3 = stoi(str);
				Student stu;(id,name1,name2,sex,num2,num3);
				arr[i] = stu;
			}
		} // end while

	} // end else

}

MainFiles::MainFiles(const MainFiles& other)
{
	arr = other.arr; 
	NumOfStudents = other.NumOfStudents;
}


void MainFiles::Sort()
{
	 arr = new Student[NumOfStudents];
	 assert(arr);
	ifstream InFile("students.data",ios::beg);

	if (InFile.is_open())
	{
		string str;
		char* name1 = NULL;char* name2 = NULL; char*sex = NULL; 
		int num1,num2,num3;
		const char* tmp;
		getline(InFile,str);getline(InFile,str);
		for (int i = 0; i<NumOfStudents ;i++)
		{
			int id = stoi(str);
			getline(InFile,str);
			tmp = str.c_str();
			sex = new char[strlen(tmp)];
			strcpy(sex,tmp);
			getline(InFile,str);
			tmp = str.c_str();
			
			name1 = new char[strlen(tmp)];
			strcpy(name1,tmp);
			getline(InFile,str);
			tmp = str.c_str();
			name2 = new char[strlen(tmp)];
			strcpy(name2,tmp);
			getline(InFile,str);
			num1 = stoi(str);
			getline(InFile,str);
			num2 = stoi(str);
			getline(InFile,str);
			num3 = stoi(str);
			getline(InFile,str);
			Student stu(id,name1,name2,sex,num2,num3); // make a student object
			arr[i] = stu; // puts in array of students
			arr[i].SetFirst();
			arr[i].SetLast();	
		}
	}
	else
	{
		cerr<<"Couldn't create file";
		exit(1);
	}
	InFile.close(); // close file

	Student temp;
	for (int i = 0; i < NumOfStudents; i++ )
		if ( strcmp(arr[i].GetFirst(),arr[i+1].GetFirst()) )
		{
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = arr[i];
		}
		else
		{
			if  (strcmp(arr[i].GetFirst(),arr[i+1].GetFirst()) == 0)
				if (strcmp(arr[i].GetLast(),arr[i+1].GetLast()))
				{
					temp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = arr[i];
				}
		}
		ofstream ofs("studentsAsc.data"); // sorted file
		if (!ofs)
			for (int i=0; i< NumOfStudents; i++)
				cout<< arr[i]; // enter data to file

		ofs.close(); // close file
}

void MainFiles::Average()
{
	ifstream InFile("students.data",ios::in|ios::beg);
	if (!InFile.is_open())
	{
		cerr<<"Couldn't open file";
		exit(1);
	}
	else
	{
		string str1,str2,str;
		double TotalAvg = 0,temp = 0;
		int count = 0;
		getline(InFile,str); // skip 1'st line
		str1 = str; str2 = str;
		while (count< NumOfStudents)
		{		
			getline(InFile,str1);getline(InFile,str1);getline(InFile,str1);
			getline(InFile,str2);
			cout<<"Last name = "<<str2<<endl;
			cout<<"First name = "<<str1<<endl;	
			getline(InFile,str);getline(InFile,str);getline(InFile,str);
			cout<<"Final grade = "<<str<<endl;
			cout<<endl;
			temp = stod(str);
			TotalAvg += temp; 
			temp = 0; count++;
		}
		InFile.close();

		TotalAvg /= NumOfStudents;
		cout<<"Total average of all students is: "<<TotalAvg<<endl<<endl;
	
	}
}


void MainFiles::Run()
{
	ifstream InFile("students.data",ios::in); // open original file
	ifstream InFileSort("studentsAsc.data",ios::in); // open sorted file
	int choice = 0;
	do
	{
		cout<<"For print all students press 1"<<endl;
		cout<<"For sort students press 2"<<endl;
		cout<<"For print all students scores and avreage of all press 3"<<endl;
		cout<<"For exit the program press 4"<<endl;
		cin>>choice;
		cout<<endl;

		switch (choice)
		{
			case PRINT:
					int option;
					cout<<"To print by the original file press 1 "<<endl;
					cout<<"To print by the sorted file press 2 "<<endl;
					cin>>option;
					cout<<endl;
					switch (option)
					{

						case ORIGINAL:
							
							if (InFile.is_open()) // file opened successfully
							{
								string str;
								getline(InFile,str); // skip 1'st line
								while (!InFile.eof())
								{
									getline(InFile,str);
									cout<<"Id = "<<str<<endl;									
									getline(InFile,str);
									cout<<"First name = "<<str<<endl;									
									getline(InFile,str);
									cout<<"Last name = "<<str<<endl;
									getline(InFile,str);
									cout<<"Gender = "<<str<<endl;								
									getline(InFile,str);
									cout<<"Middle score = "<<str<<endl;					
									getline(InFile,str);
									cout<<"Final score = "<<str<<endl;
									getline(InFile,str);
									cout<<"Final grade = "<<str<<endl;
									cout<<endl;
								}
								InFile.close(); // close file

								}
						 break;

						case SORTED:
							if (InFileSort.is_open()) // file opened successfully
								{
									string str;
									getline(InFile,str);
									while (getline(InFile,str))
										cout<<str<<endl;
									InFileSort.close(); // close file
								}
								else
									cerr<<"No such file!"<<endl<<endl; // sorted file does'nt exist
							break;

					} // end 2'nd switch
				break;

			case SORT:
				Sort();
				break;

			case AVREAGE:

				Average();
				break;

			case EXIT:

				exit(1); // exit the program command
				break;

			default:
				break;

		} // end 1'st switch case

	} while (choice != EXIT); // end do=while loop
}

MainFiles::~MainFiles()
{
	delete[] arr;
}
