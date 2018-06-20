#include <iostream>
#include <cmath> 
using namespace std;

class shape {// ������
public:
 virtual double getArea()=0;// �����
 virtual double getPerimeter()=0; // ���ܳ�
};
//���ύ�Ĵ��뽫Ƕ�뵽����
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
