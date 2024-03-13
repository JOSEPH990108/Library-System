#include<iostream>
#include<istream>
#include<sstream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include "Library.h"
#include "Login.h"
#include "Librarian.h"
#include "Student.h"

using namespace std;

void Library::MainMenu()
{
	Student stu;// Create object for class Student
	Librarian lib;//Create object for class Librarian
	cout<<"\n\t\t\t\t\t ______________________________________________";
	cout<<"\n\t\t\t\t\t|                                              |";
	cout<<"\n\t\t\t\t\t|********WELCOME TO UTHM LIBRABRY SYSTEM*******|";
	cout<<"\n\t\t\t\t\t|******************MAIN MENU*******************|";
	cout<<"\n\t\t\t\t\t|***********PLEASE SELECT ANY OPION************|";
	cout<<"\n\t\t\t\t\t|______________________________________________|";
	cout<<"\n\n\n\t\t\t\t\t 1. STUDENT\n\t\t\t\t\t 2. LIBRARIAN\n\t\t\t\t\t 3. EXIT\n";
	cout<<"\n\t\t\t\t\tEnter your choice [1/2/3]: "; cin>>choice;//
	switch(choice)
	{
		case 1:
				system("cls");
				stu.StuLoginMenu();
				break;

		case 2:
				system("cls");
				lib.LibLoginMenu();
				break;

		case 3:
				cout<<"\n\n\n\t\t\t\t\tThanks for using this library system.";
				cout<<"\n\n\t\t\t\t\tCreated by CHONG ZI YONG          AI190188";
				cout<<"\n\t\t\t\t\t           EUGENE TANG WEN LIANG  AI190216";
				cout<<"\n\t\t\t\t\t           HEAH XUE XIAN          AI190273";
				cout<<"\n\t\t\t\t\t           ALI YOUSIF MATER MATER BI180006";
				exit(1);
				break;

		default:
				cout<<"\n\t\t\t\t\tInvalid input.";
				system("PAUSE");
				cin.get();
				system("cls");
				MainMenu();
	}
}

void Library::push(string t, string i, string a, string p, int q)
{
    temp=new Books;
    temp->title=t;
    temp->isbn=i;
    temp->author=a;
    temp->publisher=p;
    temp->quantity=q;
    temp->link=NULL;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        curr=head;
        while(curr->link!=NULL)
        {
            curr=curr->link;
        }
        curr->link=temp;
    }
}

void Library::readfile()
{
	ifstream infile;
	infile.open("Books.txt");
	while(getline(infile, line))//read until the file end
	{
		if(counter==6)//while counter equal to six, it will reset to one
			counter=1;

		switch(counter)
		{
			case 1:
			 		t=line; //when counter equal to one, the particular line inside text file store into string t
			 		break;

			case 2:
			 		i=line; //when counter equal to two, the particular line inside text file store into string i
			 		break;

			case 3:
			 		a=line; //when counter equal to three, the particular line inside text file store into string a
			 		break;

			case 4:
			 		p=line; //when counter equal to four, the particular line inside text file store into string p
			 		break;

			case 5:
					stringstream ava(line); //when counter equal to five, the particular line inside text file store into integer q stringstream "name"(line) used to convert string to integer
					ava>>q;
					break;
		}
		if(counter==5)//if counter equal to five, push the variable value stored inside t,i,a,p,q into linked list 
            push(t,i,a,p,q);
        counter++;//increment counter by 1
    }
}

void Library::writelatest()
{
    ofstream outfile;//create object for ofstream
    outfile.open("temp.txt");//open file temp.txt
    temp=head;
    while(temp!=NULL)//write all data inside linked list into temp text file
    {
        outfile << temp->title << endl; 
        outfile << temp->isbn << endl;
        outfile << temp->author << endl;
        outfile << temp->publisher << endl;
        outfile << temp->quantity << endl;
        temp=temp->link;
    }
    outfile.close();

    remove("Books.txt");//delete original Books text file
    rename("temp.txt", "Books.txt");//rename temp text file to Books text file
}

void Library::display()
{
    system("cls");
    if(head==NULL)
    {
    	cout<<"\n\t\t\t\t\t\tUTHM LIBRARY BOOKLIST\n\n";
    	cout<<"\n\t\t\t\t\tThere are no any book records.\n\t\t\t\t\t";
    	system("PAUSE");
        cin.get();
        system("cls");
        MainMenu();
	}
	else
	{
		curr=head;//set curr struct pointer to head (address of first node)
    	cout<<"\n\t\t\t\t\t\tUTHM LIBRARY BOOKLIST\n\n";
    	cout<<"TITLE   \t\t\tISBN   \t\tAUTHOR   \t\t\tPUBLISHER   \t\t\tQUANTITY"<<endl<<endl;
    	while(curr!=NULL)//loop all nodes inside the linked list
    	{
    		cout<<curr->title<<"         \t"<<curr->isbn<<"   \t"<<curr->author<<"     \t\t"<<curr->publisher<<"             \t"<<curr->quantity<<endl;
    		curr=curr->link;
    	}	
	}
}

int Library::searchbook()
{
    if(head==NULL)//Check availability of node inside the linked list
    {
        cout<<"\n\t\t\t\t\tThere are no any book records.\n\t\t\t\t\t";
        system("PAUSE");
        cin.get();
        system("cls");
        MainMenu();
    }
    else
    {
        Books *temp1;//create an temp1 struct pointer
        temp1=head;//store the address of first node inside the linked list to temp1 struct pointer
        fflush(stdin);
        cout<<"\n\t\t\t\t\tEnter the title of the book: "; getline(cin,target);//User's input title of book
        for(int i=0;target[i]!='\0';i++)//Convert small letter to capital letter
            {
                if(target[i]>='a'&&target[i]<='z')
            	target[i]-=32;
            }
        for(curr=head; curr!=NULL; curr=curr->link)//search max two similar book title
        {
            if(curr->title!=target)
            {
                continue;
            }
            found++;//increment by one
            switch(found)
            {
                case 1:
                    temp=curr;
                    system("cls");
                    cout<<"\n\t\t\t\t\t\t\tDisplaying information...\n\n";
                    cout<<"TITLE   \t\t\tISBN   \t\tAUTHOR   \t\t\tPUBLISHER   \t\tQUANTITY"<<endl<<endl;
                    cout<<temp->title<<"   \t\t"<<temp->isbn<<"   \t"<<temp->author<<"     \t\t"<<temp->publisher<<"      \t"<<temp->quantity<<endl;
                    break;

                case 2:
                    system("cls");
                    cout<<"\n\t\t\t\t\t\tDisplaying information...\n\n";
                    cout<<"TITLE   \t\t\tISBN   \t\tAUTHOR   \t\t\tPUBLISHER   \t\tQUANTITY"<<endl<<endl;
                    cout<<temp->title<<"   \t\t"<<temp->isbn<<"   \t"<<temp->author<<"     \t\t"<<temp->publisher<<"      \t"<<temp->quantity<<endl;
                    cout<<curr->title<<"   \t\t"<<curr->isbn<<"   \t"<<curr->author<<"     \t\t"<<curr->publisher<<"      \t"<<curr->quantity<<endl;
                    break;
            }
        }
    }
    return found;
}

void Login::LibLoginMenu()//Librarian Login Menu
{
	cout<<"\n\t\t\t\t\t ______________________________________________";
	cout<<"\n\t\t\t\t\t|                                              |";
    cout<<"\n\t\t\t\t\t|********WELCOME TO UTHM LIBRABRY SYSTEM*******|";
    cout<<"\n\t\t\t\t\t|************LIBRARIAN LOGIN SYSTEM************|";
    cout<<"\n\t\t\t\t\t|______________________________________________|";
    cout<<"\n\n\n\t\t\t\t\t 1. Register\n\t\t\t\t\t 2. Login\n";
    cout<<"\n\t\t\t\t\t Enter your choice: "; cin>>choice;//User's input

    if(choice==1)
    {
        LibRegister();
    }
    else if(choice==2)
    {
        LibLogin();
    }
    else
    {
        cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";
        system("PAUSE");
        system("cls");
        LibLoginMenu();
    }
}

void Login::LibLogin()
{
    system("cls");
    login:
    cout<<"\n\t\t\t\t\t ______________________________________________";
	cout<<"\n\t\t\t\t\t|                                              |";
    cout<<"\n\t\t\t\t\t|********WELCOME TO UTHM LIBRABRY SYSTEM*******|";
    cout<<"\n\t\t\t\t\t|************LIBRARIAN LOGIN SYSTEM************|";
    cout<<"\n\t\t\t\t\t|______________________________________________|";
    cout<<"\n\n\n\t\t\t\t\tPlease enter the Username and Password"<<endl;
    cout<<"\t\t\t\t\tUSERNAME: ";cin>>user;//Enter username
    cout<<"\t\t\t\t\tPASSWORD: ";cin>>pass;//Enter password

    ifstream input("LibDatabase.txt");//create object for ifstream and open LibDatabase text file 
    while(input>>u>>p)//seek all username and password that stored inside LibDatabase text file
    {
        if(u==user && p==pass)//If username and password inputted by user is equal to u and p from the LibDatabase text file
        {
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {
        cout<<"\t\t\t\t\tHELLO "<<user<<" LOGIN SUCCESSFULLY\n\t\t\t\t\t";
        system("PAUSE");
        system("cls");
        Librarian lib;//Create object for class Librarian
		lib.readfile();//Read data from Books text file and store inside node of linked list
        lib.LibMenu();//Display Librarian Main Menu
    }
    else
    {
        cout<<"\n\t\t\t\t\tLOGIN ERROR\n\t\t\t\t\tPlease check your USERNAME and PASSWORD\n\t\t\t\t\t";//Invalid username or password inputted by user
        system("PAUSE");
        system("cls");
        goto login;
    }
}

void Login::LibRegister()
{
    system("cls");
    cout<<"\n\t\t\t\t\t ______________________________________________";
	cout<<"\n\t\t\t\t\t|                                              |";
    cout<<"\n\t\t\t\t\t|********WELCOME TO UTHM LIBRABRY SYSTEM*******|";
    cout<<"\n\t\t\t\t\t|*********LIBRARIAN REGISTRATION SYSTEM********|";
    cout<<"\n\t\t\t\t\t|______________________________________________|";
    cout<<"\n\n\n\t\t\t\t\tEnter the USERNAME: ";cin>>reguser;//Librarian's input for username registration
    cout<<"\n\t\t\t\t\tEnter the PASSWORD: ";cin>>regpass;//Librarian's input for password

    ofstream reg("LibDatabase.txt",ios::app);//Create object for ofstream and open LibDatabase text file for append new username and password of librarian
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout<<"\t\t\t\t\tRegistration Sucessful\n";
	LibLoginMenu();
}

void Login::StuLoginMenu()
{
    cout<<"\n\t\t\t\t\t ______________________________________________";
	cout<<"\n\t\t\t\t\t|                                              |";
    cout<<"\n\t\t\t\t\t|********WELCOME TO UTHM LIBRABRY SYSTEM*******|";
    cout<<"\n\t\t\t\t\t|*************STUDENT LOGIN SYSTEM*************|";
    cout<<"\n\t\t\t\t\t|______________________________________________|";
    cout<<"\n\n\n\t\t\t\t\t 1. Register\n\t\t\t\t\t 2. Login\n";
    cout<<"\n\t\t\t\t\t Enter your choice: "; cin>>choice;//User's input

    if(choice==1)
    {
        StuRegister();
    }
    else if(choice==2)
    {
        StuLogin();
    }
    else
    {
        cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";
        system("PAUSE");
        system("cls");
        StuLoginMenu();
    }
}

void Login::StuLogin()
{
    system("cls");
    login:
    cout<<"\n\t\t\t\t\t ______________________________________________";
	cout<<"\n\t\t\t\t\t|                                              |";
    cout<<"\n\t\t\t\t\t|********WELCOME TO UTHM LIBRABRY SYSTEM*******|";
    cout<<"\n\t\t\t\t\t|*************STUDENT LOGIN SYSTEM*************|";
    cout<<"\n\t\t\t\t\t|______________________________________________|";
    cout<<"\n\n\n\t\t\t\t\tPlease enter the Username and Password"<<endl;
    cout<<"\t\t\t\t\tUSERNAME: ";cin>>user;
    cout<<"\t\t\t\t\tPASSWORD: ";cin>>pass;

    ifstream input("StuDatabase.txt");//create object for ifstream and open StuDatabase text file 
    while(input>>u>>p)//seek all username and password that stored inside StuDatabase text file
    {
        if(u==user && p==pass)//If username and password inputted by user is equal to u and p from the StuDatabase text file
        {
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {
        cout<<"\t\t\t\t\tHELLO "<<user<<" LOGIN SUCCESSFULLY\n\t\t\t\t\t";
        system("PAUSE");
        system("cls");
        Student stu;//Create object for class Student
		stu.readfile();//Read data from Books text file and store inside node of linked list
        stu.StuMenu();//Display Student Main Menu
    }
    else
    {
        cout<<"\n\t\t\t\t\tLOGIN ERROR\n\t\t\t\t\tPlease check your USERNAME and PASSWORD\n\t\t\t\t\t";//Invalid username or password inputted by user
        system("PAUSE");
        system("cls");
        goto login;
    }
}

void Login::StuRegister()
{
    system("cls");
    cout<<"\n\t\t\t\t\t ______________________________________________";
	cout<<"\n\t\t\t\t\t|                                              |";
    cout<<"\n\t\t\t\t\t|********WELCOME TO UTHM LIBRABRY SYSTEM*******|";
    cout<<"\n\t\t\t\t\t|**********STUDENT REGISTRATION SYSTEM*********|";
    cout<<"\n\t\t\t\t\t|______________________________________________|";
    cout<<"\n\n\n\t\t\t\t\tEnter the USERNAME: ";cin>>reguser;//Student's input for username registration
    cout<<"\t\t\t\t\tEnter the PASSWORD: ";cin>>regpass;//Student's input for password

    ofstream reg("StuDatabase.txt",ios::app);//Create object for ofstream and open StuDatabase text file for append new username and password of student
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout<<"\t\t\t\t\tRegistration Sucessful\n";
	StuLoginMenu();
}

void Librarian::LibMenu()//Librarian Main Menu
{
	int choice;
	cout<<"\n\t\t\t\t\t ______________________________________________";
	cout<<"\n\t\t\t\t\t|                                              |";
	cout<<"\n\t\t\t\t\t|********WELCOME TO UTHM LIBRABRY SYSTEM*******|";
	cout<<"\n\t\t\t\t\t|*****************LIBRARIAN MENU***************|";
	cout<<"\n\t\t\t\t\t|************PLEASE SELECT ANY OPION***********|";
	cout<<"\n\t\t\t\t\t|______________________________________________|";
	cout<<"\n\n\n\t\t\t\t\t 1. BOOKLIST\n\t\t\t\t\t 2. SEARCH\n\t\t\t\t\t 3. ADD\n\t\t\t\t\t 4. DELETE\n\t\t\t\t\t 5. MODIFY\n\t\t\t\t\t 6. MAIN MENU\n\t\t\t\t\t 7. EXIT\n";
	cout<<"\n\t\t\t\t\tEnter your choice [1/2/3/4/5/6]: ";
	cin>>choice;
	switch(choice)
	{
		case 1://If choice equal to one
                {
                    display();//Display all available book from linked list
                    reenter:
                    char op;
                    cout<<"\n\t\t\t\t\tWould you like to continue the service[Y/N]: ";cin>>op;//Ask user whether want to continue or end the service
                    if(op=='Y'||op=='y')//Go back Librarian Main Menu 
                    {
                        system("cls");
                        LibMenu();
                    }
                    else if(op=='N'||op=='n')//Go back Main Menu 
                    {
                        system("cls");
                        MainMenu();
                    }
                    else
                    {
                        cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";//Retry again if op not equal to 'Y' or 'N'
                        system("PAUSE");
                        goto reenter;
                    }
                }
                break;

		case 2:
                {
                    int f;
                    f=searchbook();//store return value from searchbook function 
                    if(f>0)
                    {
                        cho:
                        char choice;
                        cout<<"\nWould you like to continue the service?[Y/N]: ";cin>>choice;//Ask user whether want to continue or end the service
                        if(choice=='Y'||choice=='y')
                        {
                            system("cls");//Go to Librarian Main Menu 
                            LibMenu();
                        }
                        else if(choice=='N'||choice=='n')//Go to Main Menu
                        {
                            system("cls");
                            MainMenu();
                        }
                        else
                        {
                            cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";//Retry again if op not equal to 'Y' or 'N'
                            system("PAUSE");
                            goto cho;
                        }
                    }
                    else
                    {
                        cout<<"\n\t\t\t\t\tBook not found!\n\t\t\t\t\t";//If search target not found inside the linked list
                        system("PAUSE");
                        system("cls");
                        LibMenu();
                    }
                }
				break;

		case 3:
				add();//Go to add new book function
				break;

		case 4:
				DeleteBook();//Go to delete book function
				break;

		case 5:
                Modify();//Go to modify book function
				break;

        case 6:
                system("cls");
				MainMenu();//Go to Main Menu
				break;

		case 7:
				cout<<"\n\n\n\t\t\t\t\tThanks for using this library system.";
				cout<<"\n\n\t\t\t\t\tCreated by CHONG ZI YONG          AI190188";
				cout<<"\n\t\t\t\t\t           EUGENE TANG WEN LIANG  AI190216";
				cout<<"\n\t\t\t\t\t           HEAH XUE XIAN          AI190273";
				cout<<"\n\t\t\t\t\t           ALI YOUSIF MATER MATER BI180006";
				exit(1);
				break;

		default:
				cout<<"\n\t\t\t\t\tInvalid input. Please press any key to continue.";//If user's input is other than integer 1 to integer 7
				cin.get();
				system("cls");
				LibMenu();//Go to Librarian Main Menu
	}
}

void Librarian::DeleteBook()
{
    string tar;
    int f=0;
    display();//Display all books inside the linked list 
    if(head==NULL)//Check availability of node inside the linked list 
    {
        cout<<"\t\t\t\t\tThere are no any book resources.\n\t\t\t\t\t";
        system("PAUSE");
        system("cls");
        LibMenu();
    }
    else
    {
        curr=head;//Set the address of first node inside the linked list to curr struct pointer
        fflush(stdin);
        cout<<"\n\n\t\t\t\t\tEnter the ISBN of book: "; getline(cin,tar);
    //If target is found in the head
        if(curr!=NULL&&curr->isbn==tar)
        {
            f=1;
            head=curr->link;
            curr->link=NULL;
            free(curr);
            writelatest();
            cout<<"\n\t\t\t\t\tBook information deleted from the list.\n\t\t\t\t\t";
            system("PAUSE");
            display();
            system("cls");
            LibMenu();
        }
        else
        {
            //Search through the nodes
            while(curr!=NULL&&curr->isbn!=tar)
            {
                temp=curr;
                curr=curr->link;

                if(curr->isbn==tar)
                {
                    f=1;
                    temp->link=curr->link;
                    curr->link=NULL;
                    free(curr);
                    writelatest();
                    cout<<"\n\t\t\t\t\tBook information deleted from the list.\n\t\t\t\t\t";
                    system("PAUSE");
                    display();
                    system("cls");
                    LibMenu();
                }
            }
        }
    }

}

void Librarian::Modify()
{
    int choice, qt;
    string tgt, tt, isb, auth, publ;

    display();
    fflush(stdin);
    cout<<"\n\n\t\t\t\t\tEnter the ISBN of book: "; getline(cin,tgt);
    for(curr=head; curr!=NULL; curr=curr->link)
        {
            if(curr->isbn==tgt)
            {
                cout<<"\n\n\t\t\t\t\t1. EDIT TITLE\n\t\t\t\t\t2. EDIT ISBN\n\t\t\t\t\t3. EDIT AUTHOR";
                cout<<"\n\t\t\t\t\t4. EDIT PUBLISHER\n\t\t\t\t\t5. EDIT QUANTITY\n\t\t\t\t\t6. EDIT";
                chc:
                fflush(stdin);
                cout<<"\n\n\t\t\t\t\tEnter your choice: "; cin>>choice;
                switch(choice)
                {
                    case 1: //Edit target book's TITLE
                            fflush(stdin);
                            cout<<"\n\t\t\t\t\tEnter the new TITLE: ";getline(cin,tt);
                            for(int i=0;tt[i]!='\0';i++)//Convert small letter to capital letter
                            {
                                if(tt[i]>='a'&&tt[i]<='z')
                                tt[i]-=32;
                            }
                            curr->title=tt;//Replace existing title to new title
                            writelatest();//Update latest data inside the linked list into Books text file
                            break;

                    case 2: //Edit target book's ISBN
                            fflush(stdin);
                            cout<<"\n\t\t\t\t\tEnter the new ISBN: ";getline(cin,isb);
                            curr->isbn=isb;//Replace existing isbn to new isbn
                            writelatest();
                            break;

                    case 3: //Edit target book's AUTHOR
                            fflush(stdin);
                            cout<<"\n\t\t\t\t\tEnter the new AUTHOR: ";getline(cin,auth);
                            for(int i=0;auth[i]!='\0';i++)//Convert small letter to capital letter
                            {
                                if(auth[i]>='a'&&auth[i]<='z')
                                auth[i]-=32;
                            }
                            curr->author=auth;//Replace existing author to new author
                            writelatest();//Update latest data inside the linked list into Books text file
                            break;

                    case 4: //Edit target book's PUBLISHER
                            fflush(stdin);
                            cout<<"\n\t\t\t\t\tEnter the new PUBLISHER: ";getline(cin,publ);
                            for(int i=0;publ[i]!='\0';i++)//Convert small letter to capital letter
                            {
                                if(publ[i]>='a'&&publ[i]<='z')
                                publ[i]-=32;
                            }
                            curr->publisher=publ;//Replace existing publisher to new publisher
                            writelatest();//Update latest data inside the linked list into Books text file
                            break;

                    case 5: //Edit target book's QUANTITY
                            fflush(stdin);
                            cout<<"\n\t\t\t\t\tEnter the new QUANTITY: ";cin>>qt;
                            curr->quantity=qt;//Replace existing quantity to new quantity
                            writelatest();//Update latest data inside the linked list into Books text file
                            break;

                    case 6: //Edit whole target book
                            fflush(stdin);
                            cout<<"\n\t\t\t\t\tEnter the new TITLE: ";getline(cin,tt);
                            for(int i=0;tt[i]!='\0';i++)
                            {
                                if(tt[i]>='a'&&tt[i]<='z')
                                tt[i]-=32;
                            }
                            curr->title=tt;
                            fflush(stdin);
                            cout<<"\n\t\t\t\t\tEnter the new ISBN: ";getline(cin,isb);
                            curr->isbn=isb;
                            fflush(stdin);
                            cout<<"\n\t\t\t\t\tEnter the new AUTHOR: ";getline(cin,auth);
                            for(int i=0;auth[i]!='\0';i++)
                            {
                                if(auth[i]>='a'&&auth[i]<='z')
                                auth[i]-=32;
                            }
                            curr->author=auth;
                            fflush(stdin);
                            cout<<"\n\t\t\t\t\tEnter the new PUBLISHER: ";getline(cin,publ);
                            for(int i=0;publ[i]!='\0';i++)
                            {
                                if(publ[i]>='a'&&publ[i]<='z')
                                publ[i]-=32;
                            }
                            curr->publisher=publ;
                            fflush(stdin);
                            cout<<"\n\t\t\t\t\tEnter the new QUANTITY: ";cin>>qt;
                            curr->quantity=qt;
                            writelatest();
                            break;

                    default:
                            cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";//User's input is other than integer 1 to integer 6
                            system("PAUSE");
                            goto chc;
                }
            }
        }
        cout<<"\n\t\t\t\t\tEdit successfully.\n\t\t\t\t\t";
        system("PAUSE");
        system("cls");
        LibMenu();

}

void Librarian::add()
{
    add:
	ofstream outfile("Books.txt",ios::app);//Create object for ofstream and open the Books text file for append new book information
	temp=new Books;
	fflush(stdin);
	cout<<"\n\t\t\t\t\tEnter the title of the book: ";
	getline(cin,temp->title);
	for(int i=0;temp->title[i]!='\0';i++)//Convert small letter to capital letter
            {
                if(temp->title[i]>='a'&&temp->title[i]<='z')
            	temp->title[i]-=32;
            }
    	outfile << temp->title << endl; //write into file
    fflush(stdin);
	cout<<"\t\t\t\t\tEnter the Isbn of the book: ";
	getline(cin,temp->isbn);
	for(int i=0;temp->isbn[i]!='\0';i++)
            {
                if(temp->isbn[i]>='a'&&temp->isbn[i]<='z')
            	temp->isbn[i]-=32;
            }
        outfile << temp->isbn << endl;
    fflush(stdin);
	cout<<"\t\t\t\t\tEnter the Author of the book: ";
	getline(cin,temp->author);
	for(int i=0;temp->author[i]!='\0';i++)
            {
                if(temp->author[i]>='a'&&temp->author[i]<='z')
            	temp->author[i]-=32;
            }
        outfile << temp->author << endl;
    fflush(stdin);
	cout<<"\t\t\t\t\tEnter the Publisher of the book: ";
	getline(cin,temp->publisher);
	for(int i=0;temp->publisher[i]!='\0';i++)
            {
                if(temp->publisher[i]>='a'&&temp->publisher[i]<='z')
            	temp->publisher[i]-=32;
            }
        outfile << temp->publisher << endl;
    fflush(stdin);
	cout<<"\t\t\t\t\tEnter the Quantity of the book: ";
	cin >> temp->quantity;
		outfile << temp->quantity << endl;
	temp->link=NULL;
	outfile.close();

	if(head==NULL)//If there are no node inside the linked list
	{
		head=temp; //store temp struct pointer's address into head
	}
	else
	{
		curr=head; //store head into curr struct pointer 
		while(curr->link!=NULL)//Loop till last node inside the linked list
		{
			curr=curr->link;
		}
		curr->link=temp;
	}
	cout<<"\n\t\t\t\t\tBook added successfully.";
	reenter:
	char op;
	cout<<"\n\t\t\t\t\tWould you like to add more book?[Y/N]: ";cin>>op;//Ask user whether want to continue to add new book
	if(op=='y'||op=='Y')//Add another book
	{
		goto add;
	}
	else if(op=='n'||op=='N')//Go to Librarian Main Menu
	{
	    system("cls");
        LibMenu();
	}
	else
	{
		cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";//User's input is other than 'Y' or 'N'
		system("PAUSE");
		goto reenter;//Retry again
	}
}

void Student::StuMenu()
{
	int choice;
	cout<<"\n\t\t\t\t\t ______________________________________________";
	cout<<"\n\t\t\t\t\t|                                              |";
	cout<<"\n\t\t\t\t\t|*******WELCOME TO UTHM LIBRABRY SYSTEM********|";
	cout<<"\n\t\t\t\t\t|*****************STUDENT MENU*****************|";
	cout<<"\n\t\t\t\t\t|***********PLEASE SELECT ANY OPION************|";
	cout<<"\n\t\t\t\t\t|______________________________________________|";
	cout<<"\n\n\n\t\t\t\t\t 1. BOOKLIST\n\t\t\t\t\t 2. SEARCH\n\t\t\t\t\t 3. BORROW/RESERVATION\n\t\t\t\t\t 4. MAIN MENU\n\t\t\t\t\t 5. EXIT\n\n";
	cout<<"\t\t\t\t\tEnter your choice [1/2/3/4/5]: "; cin>>choice;
	switch(choice)
	{
		case 1: 
				{
                    display();
                    reenter:
                    char op;
                    cout<<"\n\t\t\t\t\tWould you like to continue the service[Y/N]: ";cin>>op;
                    if(op=='Y'||op=='y')
                        {
                            system("cls");
                            StuMenu();
                        }
                    else if(op=='N'||op=='n')
                    {
                        system("cls");
                        MainMenu();
                    }
                    else
                    {
                        cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";
                        system("PAUSE");
                        goto reenter;
                    }
                }
				break;
		
		case 2:
				{
                    int f;
                    f=searchbook();
                    if(f>0)
                    {
                        cho:
                        char choice;
                        cout<<"\nWould you like to continue the service?[Y/N]: ";cin>>choice;
                        if(choice=='Y'||choice=='y')
                        {
                            system("cls");
                            StuMenu();
                        }
                        else if(choice=='N'||choice=='n')
                        {
                            system("cls");
                            MainMenu();
                        }
                        else
                        {
                            cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";
                            system("PAUSE");
                            goto cho;
                        }
                    }
                    else
                    {
                        cout<<"\n\t\t\t\t\tBook not found!\n\t\t\t\t\t";
                        system("PAUSE");
                        system("cls");
                        StuMenu();
                    }
                }
				break;
		
		case 3: 
				Borrow_Reservation();
				break;
		
		case 4:
				system("cls");
				MainMenu();
				break;
				
		case 5:
				cout<<"\n\n\n\t\t\t\t\tThanks for using this library system.";
				cout<<"\n\n\t\t\t\t\tCreated by CHONG ZI YONG          AI190188";
				cout<<"\n\t\t\t\t\t           EUGENE TANG WEN LIANG  AI190216";
				cout<<"\n\t\t\t\t\t           HEAH XUE XIAN          AI190273";
				cout<<"\n\t\t\t\t\t           ALI YOUSIF MATER MATER BI180006";
				exit(1);
				break;
				
		default: 
				cout<<"\n\t\t\t\t\tInvalid input. Please press any key to continue.";
				cin.get();
				system("cls");
				StuMenu();
	}
}

void Student::Borrow_Reservation()
{
	string tar;
    int qty;
    char opn;
	
	system("cls");
	borrow:
    display();
    fflush(stdin);
    cout<<"\n\n\t\t\t\t\tEnter the ISBN of book: "; getline(cin,tar);
    for(curr=head; curr!=NULL; curr=curr->link)
        {
            if(curr->isbn==tar)
            {
                qty=curr->quantity;

                    if(qty>0)
                    {
                        opion:
                        cout<<"\n\t\t\t\t\tYou can either choose to borrow[B] or make reservation[R]: ";cin>>opn;
                        switch(opn)
                        {
                            case 'b': case 'B':
                                curr->quantity-=1;
                                writelatest();
                                cout<<"\t\t\t\t\tBook <<"<<curr->title<<">> is borrow successful.\n\t\t\t\t\t";
                                reenter:
                    			char op;
                    			cout<<"\n\t\t\t\t\tWould you like to continue the service[Y/N]: ";cin>>op;
                    			if(op=='Y'||op=='y')
                        		{
                            		system("cls");
                            		Borrow_Reservation();
                        		}
                    			else if(op=='N'||op=='n')
                    			{
                        			system("cls");
                        			StuMenu();
                    			}
                    			else
                    			{
                       				cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";
                        			system("PAUSE");
                        			goto reenter;
                    			}
                                break;
                            case 'r': case 'R':
                                    curr->quantity-=1;
                                    writelatest();
                                    cout<<"\t\t\t\t\tBook <<"<<curr->title<<">> reservation has been make successfully.\n\t\t\t\t\t";
                                    enter:
                    			char optn;
                    			cout<<"\n\t\t\t\t\tWould you like to continue the service[Y/N]: ";cin>>optn;
                    			if(optn=='Y'||optn=='y')
                        		{
                            		system("cls");
                            		Borrow_Reservation();
                        		}
                    			else if(optn=='N'||optn=='n')
                    			{
                        			system("cls");
                        			StuMenu();
                    			}
                    			else
                    			{
                       				cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";
                        			system("PAUSE");
                        			goto enter;
                    			}
                                    break;
                            default:
                                    cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";
                                    system("PAUSE");
                                    goto opion;
                        }
                    }
                    else
                    {
                        cout<<"\n\t\t\t\t\tUnable to borrow or make reservation for this "<<curr->title<<", "<<curr->isbn<<endl;
                        cout<<"\t\t\t\t\tThis book is temporary unavailable.\n\t\t\t\t\t";
                        		renter:
                    			char op;
                    			cout<<"\n\t\t\t\t\tWould you like to continue the service[Y/N]: ";cin>>op;
                    			if(op=='Y'||op=='y')
                        		{
                            		system("cls");
                            		Borrow_Reservation();
                        		}
                    			else if(op=='N'||op=='n')
                    			{
                        			system("cls");
                        			StuMenu();
                    			}
                    			else
                    			{
                       				cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";
                        			system("PAUSE");
                        			goto renter;
                    			}
                    }
                }
            }
            cout<<"\n\t\t\t\t\tInvalid input.\n\t\t\t\t\t";
			system("PAUSE");
			system("cls");
			goto borrow; 
}

int main()
{
	Library library;
	library.MainMenu();
}

