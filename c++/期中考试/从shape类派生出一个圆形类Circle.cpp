#include <iostream>
#define PI 3.1415926 
using namespace std;

class shape {
public:
  double getArea(){ return -1; };// 求面积
  double getPerimeter(){ return -1;  }; // 求周长
};

class Circle:shape{
	private:
		double r;
	public:
		Circle(double r1)
		{
			r=r1;
		}
		double getArea()
		{
			return(r*r*PI);
		 }
		 double getPerimeter()
		 {
		 	return(PI*r*2);
		  } 
};

int main() {
  double r;
  cin>>r;
  Circle c(r);
  cout<<c.getArea()<<endl;
  cout<<c.getPerimeter()<<endl;
  return 0;
}

