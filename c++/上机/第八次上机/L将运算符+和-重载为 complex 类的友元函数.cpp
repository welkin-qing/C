#include<iostream>
using namespace std;
class complex
{
	private: //˽�г�Ա
		double real;
		double imag;
	public:
		complex(double r=0.0,double i=0.0)
		{ real=r; imag=i; } //���캯��
		friend complex operator + (complex c1,complex c2);
		//���������+Ϊ��Ԫ����
		friend complex operator - (complex c1,complex c2);
		//���������-Ϊ��Ԫ����
		void display();
};
complex operator + (complex c1,complex c2)
{
	complex c;
	c.real=c1.real+c2.real;
	c.imag=c1.imag+c2.imag;
	return  c;
}
complex operator - (complex c1,complex c2)
{
	complex c;
	c.real=c1.real-c2.real;
	c.imag=c1.imag-c2.imag;
	return  c;
} 
void complex::display()
{
	cout<<real<<"+"<<imag<<"i"<<endl; 
}
int main()
{
	complex a(1,2),b(3,4);
	complex k;
	k=a+b;
	k.display();
	k=b-a;
	k.display();
}

