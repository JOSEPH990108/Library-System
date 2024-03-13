#include<iostream>

using namespace std;

class Student
{
	private:
		struct Data
		{
			string StudentID;
			double Mark;	
		}stdata;
		
		
	public:
		void setStudentID();
		void getStudentID();
		void setMark();
		void getMark();
		void findGrade();	
};

void Student::setStudentID()
{
	cout<<"Enter Student's ID: "; getline(cin,stdata.StudentID);
}

void Student::setMark()
{
	cout<<"Enter Student's mark: "; cin>>stdata.Mark;
}

void Student::getStudentID()
{
	cout<<"\nStudent ID: "<<stdata.StudentID<<endl;
}

void Student::getMark()
{
	cout<<"Student's mark: "<<stdata.Mark<<endl;
	findGrade();
}

void Student::findGrade()
{
	char grade;
	
	if(stdata.Mark>=80)
		cout<<"A\n";
	else if(stdata.Mark>=70 && stdata.Mark<80)
		cout<<"B\n";
	else if(stdata.Mark>=60 && stdata.Mark<70)
		cout<<"C\n";
	else if(stdata.Mark>=50 && stdata.Mark<60)
		cout<<"D\n";
	else if(stdata.Mark<50)
		cout<<"E\n";
}

