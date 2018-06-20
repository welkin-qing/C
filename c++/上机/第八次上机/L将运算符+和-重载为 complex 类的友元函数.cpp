#include<iostream>
using namespace std;
class complex
{
	private: //私有成员
		double real;
		double imag;
	public:
		complex(double r=0.0,double i=0.0)
		{ real=r; imag=i; } //构造函数
		friend complex operator + (complex c1,complex c2);
		//重载运算符+为友元函数
		friend complex operator - (complex c1,complex c2);
		//重载运算符-为友元函数
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

