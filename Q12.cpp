#include<iostream>

using namespace std;

class Count
{
	private:
		int num[10];
		
	public:
		void setInput();
		void displayOutput();
};

void Count::setInput()
{
	int i;
	
	for(i=0;i <10; i++)
	{
		cout<<"Please enter an integer for integer["<<i<<"]: ";
		cin>>num[i];
	}
}

void Count::displayOutput()
{
	int max, i;
	
	max = num[0];
	
	for(i=1;i<10;i++)
	{
		if(num[i] > max)
		{
			max = num[i];
		}
	}
	
	cout<<"The biggest number is: "<<max;
}

int main()
{
	Count count;
	count.setInput();
	count.displayOutput();
}
