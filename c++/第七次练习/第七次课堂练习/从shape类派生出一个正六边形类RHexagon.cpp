#include <iostream>
#include <cmath> 
using namespace std;

class shape {// 抽象类
public:
 virtual double getArea()=0;// 求面积
 virtual double getPerimeter()=0; // 求周长
};
//你提交的代码将嵌入到这里
class RHexagon :public shape
{
	private:
		
	double rad;
	public:
	 RHexagon(double s)
	 {
	 	 rad=s;
	 }	
	double getArea()
	{
		return( 6 * pow(3,0.5)  / 4 *rad *rad );
	}
	double getPerimeter()
	{
		return 6*rad;
	}
	
};

int main()
{
  double s;
  cin>>s;
  RHexagon p(s);
  cout<<p.getArea()<<endl;
  cout<<p.getPerimeter()<<endl;	
}
