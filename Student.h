#include<iostream>
#include<string.h>
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;


class Student:public Library, public Login //class Student inherited with class Library and Login
{
	public:
		void StuMenu();//Student Menu
		void Borrow_Reservation();//Borrow book or make reservation	
};

#endif
