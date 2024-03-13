#include<iostream>
#include "Student.cpp"

using namespace std;

class StudentList
{
	private:
		struct ListNode
		{
			Student astudent;
			ListNode *link;
		};
		ListNode *head;
		
	public:
		StudentList();
		~StudentList();
		int IsEmpty();
		void Add(Student newstudent);
		void Remove();
		void DisplayList();	
};

StudentList::StudentList()
{
	head=NULL;
}

StudentList::~StudentList()
{
	cout<<"\nDestructing the object..\n";
	while(IsEmpty()!=0)
		Remove();
	if(IsEmpty()==0)
		cout<<"All students have benn deleted from a list\n";	
}

int StudentList::IsEmpty()
{
	if(head==NULL)
		return 0;
	else
		return 1;
}

/*void StudentList::Add(Student newstudent) //LIFO
{
	ListNode *newPtr = new ListNode;
	if(newPtr==NULL)
		cout<<"Cannot allocate memory";
	else
		{
			newPtr->astudent=newstudent;
			newPtr->link=head;
			head=newPtr;
		}
}*/

void StudentList::Add(Student newstudent) // FIFO
{
	ListNode *newPtr=new ListNode;
	ListNode *temp = head;
	
	newPtr->astudent=newstudent;
	newPtr->link=NULL;
	
	if(temp==NULL)
		head=newPtr; 
	else
		{
			while(temp->link!=NULL)
			{
				temp=temp->link;
			}
			temp->link=newPtr; 
		}
}

/*void StudentList::Remove() // DELETE FIRST NODE
{
	if(IsEmpty()==0)
		cout<<"List empty on remove.";
	else
	{
		ListNode *temp=head;
		head=head->link;
		temp->link==NULL;
		delete temp;
	}
}*/

void StudentList::Remove() //DELETE LAST NODE
{
	if(IsEmpty()==0)
		cout<<"List empty on remove.";
	else
	{
		ListNode *temp=head;
		ListNode *pre=head;
		while(temp->link!=NULL)
		{
			pre=temp;
			temp=temp->link;
		}
		if(temp==head)
		{
			head=NULL;
		}
		else
		{
			pre->link=NULL;
			delete temp;
		}
	}
}

void StudentList::DisplayList()
{
	ListNode *curr=head;
	if(IsEmpty()==0)
		cout<<"List Empty.";
	else
	{
		cout<<"Current List: \n\n";
		while(curr!=NULL)
		{
			fflush(stdin);
			curr->astudent.getStudentID();
			curr->astudent.getMark();
			curr=curr->link;
		}
		cout<<"\n";
	}
}
