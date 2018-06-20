#include <iostream>
#define pi 3.1415926
using namespace std;

class shape {
public:
  double getArea(){ return -1; };// 求面积
  double getPerimeter(){ return -1;  }; // 求周长
};

/* 你提交的代码将被嵌入到这里 */

class Circle:public shape
{
	private:
		double r;
	public:
		Circle(double r1)
		{
			r=r1;
		}
	double getArea()
	{
		return(r*r*pi);
	}
	double getPerimeter()
	{
		return(2*r*pi);
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
/* 请在这里填写答案 */


