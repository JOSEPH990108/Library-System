#include<iostream>
#include "StudentList.cpp"

int main()
{
	const int size=3;
	int i;
	Student newstudent;
	StudentList alist;
	
	cout<<"Inserting "<<size<<" objects\n";
	for(i=0; i<size; i++)
	{
		fflush(stdin);
		newstudent.setStudentID();
		newstudent.setMark();
		alist.Add(newstudent);
	}
	alist.DisplayList();
	
	cout<<"Deleting\n";
	alist.Remove();
	cout<<"After Removing 1 object\n";
	alist.DisplayList();
	return 0;
}
