#include <iostream> 
using namespace std;  
// ���ύ�Ĵ��뽫��Ƕ�뵽����
class shape {// ������
	public:
 		virtual double getArea()=0;// �����
 //virtual double getPerimeter()=0; // ���ܳ�
};
//���ύ�Ĵ��뽫Ƕ�뵽����
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
