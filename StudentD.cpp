//#include"Student1.cpp"

/*int main()
{
	Student student;
	
	student.SetData();
	student.GetData();
	
return 0; 
}*/

#include <iostream>

using namespace std;

class A {
   public:
      void print(){ cout << "print A" << endl; };
};

class B: public A {
    public:
       virtual void print(){ cout << "print B" << endl; };
};

class C: public B {
     public:
        void print(){ cout << "print C" << endl; };
};

int main()
{
   A *a = new C();
   B *b = new C();

   a->print(); // will print 'print A'
   b->print(); // will print 'print C'

   return 1;
}
