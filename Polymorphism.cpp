#include<iostream>
#define PI 3.142

using namespace std;

/*class Shape
{
	public: 
		Shape(){
		}
		virtual double area_cal()
		{
			return 0;
		}
};

class Rectangle : public Shape
{
	public:
		double width, height;	
		Rectangle(double w=10, double h=3){
			width = w;
			height = h;
		}
		double area_cal()
		{
			return width*height;
		}
};

class Circle : public Shape
{
	public:
		double radius;
		Circle(double r = 2)
		{
			radius = r;
		}
		double area_cal()
		{
			return PI*radius*radius;
		}	
};

int main()
{
	Circle cir;
	Rectangle rec;
	
	Shape *ptr, *ptr1;
	ptr = &cir;
	ptr1 = &rec;
	cout<<"Circle area = "<<ptr->area_cal();
	cout<<"\n\nRectangle area = "<<ptr1->area_cal();
}*/

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
     virtual int area ()
      { return 0; }
};

class Rectangle: public Polygon {
  public:
    int area ()
      { return width * height; }
};

class Triangle: public Polygon {
  public:
    int area ()
      { return (width * height / 2); }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon poly;
  
  poly.set_values(4,5);
  cout<<poly.area();
  
  trgl.set_values(4,5);
  cout<<trgl.area();
  /*Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  Polygon * ppoly3 = &poly;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly3->set_values (4,5);
  cout << ppoly1->area() << '\n';
  cout << ppoly2->area() << '\n';
  cout << ppoly3->area() << '\n';*/
  return 0;
}
