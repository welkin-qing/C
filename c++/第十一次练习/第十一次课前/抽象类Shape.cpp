#include <iostream>
using namespace std;
const double PI=3.14;

class Shape {
	public:
		virtual double getArea()=0;
		virtual double getPerim()=0;
};

/* ------请在这里填写答案 ------*/
class Rectangle:public Shape
{
	private:
		double weight;
		double height;
	public:
		Rectangle(double a,double b)
		{
			weight=a;
			height=b;
		}
		double getArea()
		{
			return weight*height;
		}
		double getPerim()
		{
			return 2*(weight + height); 
		 } 
};
class Circle:public Shape
{
	private:
		double rid;
	public:
		Circle(double r)
		{
			rid=r;
		}
		double getArea()
		{
			return PI*rid*rid; 
		}
		double getPerim()
		{
			return 2*PI*rid;
		 } 
};

int main() {
	Shape *p;
	int n;
	double w,h,r;
	scanf("%d",&n);
	switch(n) {
		case 1: {
			cin>>w>>h;
			Rectangle rect(w,h);
			cout<<"area="<<rect.getArea()<<endl;
			cout<<"perim="<<rect.getPerim()<<endl;
			break;
		}
		case 2: {
			cin>>r;
			Circle c(r);
			cout<<"area="<<c.getArea()<<endl;
			cout<<"perim="<<c.getPerim()<<endl;
			break;
		}
	}

	return 0;
}
