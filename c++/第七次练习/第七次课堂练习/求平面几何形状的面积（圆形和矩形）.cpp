#include <iostream>
#include <cmath> 
using namespace std;
class Shape{
	public:
    	double area ( ){ return -1; }
};
//你提交的代码将嵌入到这里。 
class Circle : public Shape{
	private:
		double r;
	public:
		Circle (double r1)
		{
			r=r1;
		}
		double area()
		{
			return(3.14*r*r);
		}
};
class Rectangle : public Shape{
	private:
		double w,h;
	public:
		Rectangle (double w1,double h1)
		{
			w=w1;
			h=h1;
		}
		double area()
		{
			return(h*w);
		}
};
int main()
{
    double r,h,w;
    cin>>r>>h>>w;
    Circle c(r); 
	Rectangle rect(h,w);

    cout<<"The area of the Circle is "<<c.area( )<<endl;
    cout<<"The area of the Rectangle is "<<rect.area( )<<endl;

    return 0;
}
