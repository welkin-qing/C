//������������������ý��в��Ե����ӡ����磺
#include <iostream>
using namespace std;
//���ύ�Ĵ��뽫Ƕ�뵽����
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
