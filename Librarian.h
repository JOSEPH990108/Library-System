#include<iostream>
#include<string.h>
#ifndef LIBRARIAN_H
#define LIBRARIAN_H
using namespace std;

class Librarian:public Library, public Login //class Librarian inherited with class Library and Login
{		
	public:
		void LibMenu();//Librarian Menu
		void add();//Add books
		void DeleteBook();//Delete books
        void Modify();//Modify books
};

#endif
