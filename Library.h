#include<iostream>
#include<string.h>
#ifndef LIBRARY_H
#define LIBRARY_H

using namespace std;

struct Books
{
    string title, isbn, author, publisher;//attributes of books
    int quantity;//attributes of books
    struct Books *link;//Link to next Books node 
    
    public:
    	Books()
    	{
    		link = NULL;
		}
};

class Library//Library class
{
    protected:
        Books *head, *curr, *temp;
        int counter, choice, q, found;
        string t, i, a, p, line, target;
        
    public:
        Library()//Library constructor
        {
        	struct Books *link=NULL;
        	counter = 1;
        	found = 0;
            head=NULL;//Set head equal to NULL
        }
        void MainMenu();
		void push(string , string, string, string, int);//Push data into linked list 
        void display();//Display all booklist
        int searchbook();//Search book from booklist
        void readfile();//read books' data from file
        void writelatest();//write latest books' data into file
};
#endif
