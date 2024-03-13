#include <iostream>
#include <fstream>

using namespace std;
class Student
{
	private:
		struct Data
		{
			char Name[25];
			char Course[25];
			int Result;	
		}Stdata;
		
	public:
		void SetData();
		void GetData(); 
		 
};

void Student::SetData()
{
	fstream input("student.dat", ios::in|ios::out);
	fflush(stdin);
	cout<<"Enter student name: ";
	cin>>Stdata.Name;
	cout<<"Enter student course: ";
	cin>>Stdata.Course;
	fflush(stdin);
	cout<<"Enter student Result: ";
	cin>>Stdata.Result;
	
	input.seekg(0,ios::end);
	input.write((char*)&Stdata, sizeof(Stdata));
	input.close();
}

void Student::GetData()
{
	fstream output("student.dat",ios::in|ios::out);
	output.seekg(0,ios::beg);
	while(!output.eof())
	{
		output.read((char*)&Stdata, sizeof(Stdata));
			if(output.eof())
			{
				break;	
			}
			else
			{
				cout<<"\nStudent name: "<<Stdata.Name;
				cout<<"\n";
				cout<<"\nStudent course: "<<Stdata.Course;
				cout<<"\n";
				cout<<"\nStudent result: "<<Stdata.Result;
				cout<<"\n";
			}			
	}	
	output.close();
}
