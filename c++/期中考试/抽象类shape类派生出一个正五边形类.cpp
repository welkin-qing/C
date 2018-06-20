#include <iostream>
#include <cmath> 
using namespace std;

class shape {// 抽象类
public:
 virtual double getArea()=0;// 求面积
 virtual double getPerimeter()=0; // 求周长
};
class RPentagon : public shape{
	private:
		double line;
	public:
		 RPentagon(double s)
		{
			line=s;
		}
		double getArea(){
			return(line*line*sqrt(25+10*sqrt(5))/4);
		}
		double getPerimeter(){
			return(5*line);
		}
};
int main()
{
  double s;
  cin>>s;
  RPentagon p(s);
  cout<<p.getArea()<<endl;
  cout<<p.getPerimeter()<<endl;	
}
