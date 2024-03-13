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
	cout<<"Student ID: "<<stdata.StudentID<<endl;
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
		cout<<"A";
	else if(stdata.Mark>=70 && stdata.Mark<80)
		cout<<"B";
	else if(stdata.Mark>=60 && stdata.Mark<70)
		cout<<"C";
	else if(stdata.Mark>=50 && stdata.Mark<60)
		cout<<"D";
	else if(stdata.Mark<50)
		cout<<"E";
}

int main()
{
	Student student;
	student.setStudentID();
	student.setMark();
	student.getStudentID();
	student.getMark();
}
