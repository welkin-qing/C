#include <iostream> 
using namespace std;  
// 你提交的代码将被嵌入到这里
class shape {// 抽象类
	public:
 		virtual double getArea()=0;// 求面积
 //virtual double getPerimeter()=0; // 求周长
};
//你提交的代码将嵌入到这里
class Triangle:public shape
{
	private :
		double a;
		double b;
	public:
		Triangle(double a1,double b1)
		{
		   a=a1;
		   b=b1;	
		}	
  double getArea()
	{
		return(a*b/2);
	
	}	
//	double getPerimeter()
//	{
//		return(a+b+sqrt(a*a+b*b));
//	}
};

int main( )
{
  double w,h;
  cin>>w>>h;
  Triangle t(w,h);
  cout<<"The area of the Triangle is: "<<t.getArea( )<<endl;
}
