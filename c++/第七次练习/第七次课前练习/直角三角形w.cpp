#include <iostream>
#include <cmath> 
using namespace std;

class shape {// 抽象类
public:
 virtual double getArea()=0;// 求面积
 virtual double getPerimeter()=0; // 求周长
};
class RTriangle:public shape  
{private:
 	double x,y;  

public:  
    RTriangle(){}  
    RTriangle(double a,double b){x = a;y=b;} 
double getArea();// 求面积
 double getPerimeter(); // 求周长
  
};  
double RTriangle::getArea()  
 {  
     return (x*y)/2;
 }  
double RTriangle::getPerimeter()
 {
 	return x+y+(sqrt(x*x+y*y));
 }
  
int main()
{
  double a,b;
  cin>>a>>b;
  RTriangle t(a,b);
  cout<<t.getArea()<<endl;
  cout<<t.getPerimeter()<<endl;	
}

