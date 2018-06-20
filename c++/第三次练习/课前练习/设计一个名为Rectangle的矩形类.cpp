//在这里给出函数被调用进行测试的例子。例如：
#include <iostream>
using namespace std;
//你提交的代码将嵌入到这里
class Rectangle{
	private:
		double width;
		double height;
		
	public:
		void set(double width1,double height1)
		{
			double width=width1;
			double height=height1;
		}
		double getArea()
		{
			double squ;
//			squ=width*height;
//			cout<<squ<<endl;
			return(width*height);
		}
		double getPerimeter()
		{
			double sum;
//			sum=(width+height)*2;
//			cout<<sum<<endl;
			return((width+height)*2);
		}
}a;
int main()
{    
    double m,n;
    cin>>m;
    cin>>n;
    Rectangle a;
    a.set(m,n);
    cout<<a.getArea()<<endl;
    cout<<a.getPerimeter()<<endl;
    return 0;
}
