#include <iostream> 
#include<fstream>

using namespace std;

class catalogue{
	struct detail{
		char title [50], publisher[50];
		int copy;
	}book;
	
	public:
		void readInput();
}; 

void catalogue::readInput()
{
	ifstream input;
	input.open("booklist.dat");
	
	if(input.fail())
	{
		cout<<"Unable to open file\n";
		exit(1); 
	}
	
	while(input>>book.title>>book.publisher>>book.copy){
		cout<<book.copy<<endl;
		cout<<book.title<<endl;
		cout<<book.publisher<<endl<<endl;
	}
	
	input.close(); 
}
