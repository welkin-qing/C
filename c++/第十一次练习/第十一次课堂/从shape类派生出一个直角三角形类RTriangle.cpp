#include <iostream>
#include <cmath> 
using namespace std;

class shape {// 抽象类
public:
 virtual double getArea()=0;// 求面积
 virtual double getPerimeter()=0; // 求周长
};
//你提交的代码将嵌入到这里
class RTriangle :shape{
	private:
		double a,b;
	public:
		RTriangle(double a1,double b1)
		{
			a=a1;
			b=b1;
		}
		double getArea()
		{
			return(a*b*0.5);
		}
		double getPerimeter()
		{
			return(a+b+sqrt(a*a+b*b));
		}
};
int main()
{
  double a,b;
  cin>>a>>b;
  RTriangle t(a,b);
  cout<<t.getArea()<<endl;
  cout<<t.getPerimeter()<<endl;	
}
