#include<iostream>
using namespace std; 
class complex 
{
 	public:   
		complex(double r=0.0,double i=0.0)  
		{ real=r; imag=i; } //构造函数  
		friend complex operator + (complex c1,complex c2); 
		//重载运算符+为友元函数  
		friend complex operator - (complex c1,complex c2); 
		//重载运算符-为友元函数  
		void display(); //显示复数的值 
	private: //私有成员  
		double real;  
		double imag; 
};
complex operator + (complex c1,complex c2)
{
	complex c;
	c.real=c1.real+c2.real;
	c.imag=c1.imag+c2.imag;
	return c;
}
complex operator - (complex c1,complex c2)
{
	complex c;
	c.real=c1.real-c2.real;
	c.imag=c1.imag-c2.imag;
	return c;
}
void complex::display()
{
	cout<<real<<"+"<<imag<<"i"<<endl;
}
int main()
{
	complex a(0.5,4.7),b(0.6,4.8);
	complex k;
	cout<<"a=";
	a.display();
	cout<<"b=";
	b.display();
	k=a+b;
	cout<<"k=a+b=";
	k.display();
	k=a-b;
	cout<<"k=a-b=";
	k.display();
}
