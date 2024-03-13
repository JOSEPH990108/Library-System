#include<iostream>
#include<string.h>
#ifndef LOGIN_H
#define LOGIN_H
using namespace std;

class Login//Login class
{
	private:
		string user,pass,u,p,reguser,regpass;
		int choice, count;	
	
	public:
		void LibLoginMenu();//Librarian login interface
        void LibLogin();//Librarian login 
        void LibRegister();//Librarian registration
        void StuLoginMenu();//Student login interface
        void StuLogin();//Student login 
        void StuRegister();//Student registration interface
};

#endif
