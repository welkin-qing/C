#include<iostream>
using namespace std; 
class complex    //复数类声明 
{ 
	public:     //外部接口  
		complex(double r=0.0,double i=0.0) //构造函数  
		{real=r;imag=i;}     
		complex operator + (complex c2); //+重载为成员函数  
		complex operator - (complex c2); //-重载为成员函数  
		void display( );  //输出复数 
	private:      		//私有数据成员  
		double real;   //复数实部  
		double imag;   //复数虚部 
};  
complex complex::operator + (complex c2)
{
	complex c;
	c.real = real+c2.real;
	c.imag = imag + c2.imag;
	return c;
}
complex complex::operator -(complex c2)
{
	complex c;
	c.real = real - c2.real;
	c.imag = imag - c2.imag;
	return c;
}
void complex::display() 
{
	cout<<real<<"+"<<imag<<"i"<<endl;
}
int main()
{
	complex a(0,22.7),b(0,12.8);
	complex k;
	cout<<"a: ";
	a.display();
	cout<<"b: ";
	b.display();
	cout<<"a+b\n";
	k=a+b;
	k.display();
	cout<<"a-b\n";
	k=a-b;
	k.display();
}
