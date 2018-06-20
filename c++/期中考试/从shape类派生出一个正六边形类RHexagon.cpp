#include <iostream>
#include <cmath> 
using namespace std;

class shape {// ������
public:
 virtual double getArea()=0;// �����
 virtual double getPerimeter()=0; // ���ܳ�
};
class RHexagon:shape{
	private:
		double l;
	public:
		RHexagon(double l1)
		{
			l=l1;
		}
		double getArea()
		{
	    	return(6*pow(3,0.5)/4*l*l); 
		}
		double getPerimeter(){
			return(6*l);
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
