#include<iostream>
using namespace std;
#include <iostream>
#include <cmath> 
using namespace std;

class shape {// ������
public:
 virtual double getArea()=0;// �����
 virtual double getPerimeter()=0; // ���ܳ�
};
//���ύ�Ĵ��뽫Ƕ�뵽����
class RTriangle:shape{
	private:
		double w,h;
	public:
		RTriangle(double w1,double h1)
		{
			w=w1;
			h=h1;
		 }
		 double getArea(){
		 	return(w*h/2);
		}
		double getPerimeter(){
			return(w+h+sqrt(w*w+h*h));
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
