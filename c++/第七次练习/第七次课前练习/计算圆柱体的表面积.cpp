#include <iostream>
using namespace std;
const double PI=3.1415926;
class Circle
{
protected:
   double radius;
public: 
   Circle(double r)
   {
      radius=r;
   }
   double getArea(){
      return PI*radius*radius;
   }
};
// 你提交的代码将嵌入在这里

class Cylinder :public Circle
{
private:
		 double height;             
public:
 Cylinder(double r1,  double h1):Circle(r1)
 {
 	height=h1;
 }
 double getArea()
 {
 	return (PI*radius*radius*2+2*PI*radius*height);
 }
};



/*
Cylinder :public Circle
{
         double height;             
public:
     Cylinder(double r,double h):Circle(r)
     {
	 
     //	radius=r;
     	height=h;
    }
double getArea()
{
	return (2*PI*radius*radius+2*PI*radius* height);
}	   
};*/
int main() 
{
   double r,h;
   cin>>r>>h;
   Cylinder Cy1(r,h) ;
   cout<<Cy1.getArea()<<endl;
   return 0;
}

