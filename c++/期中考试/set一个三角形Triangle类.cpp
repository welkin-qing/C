#include <iostream> 
using namespace std;  
// 你提交的代码将被嵌入到这里
class Triangle{
	private:
		double width;
		double height;
	public:
		Triangle(double w,double h)
		{
			width=w;
			height=h;
		}
		double getArea()
		{
			return(width*height/2);
		}
};
int main( )
{
  double w,h;
  cin>>w>>h;
  Triangle t(w,h);
  cout<<"The area of the Triangle is: "<<t.getArea( )<<endl;
}
