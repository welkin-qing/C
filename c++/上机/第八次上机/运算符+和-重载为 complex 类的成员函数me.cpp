#include<iostream>
using namespace std; 
class complex    //���������� 
{ 
	public:     //�ⲿ�ӿ�  
		complex(double r=0.0,double i=0.0) //���캯��  
		{real=r;imag=i;}     
		complex operator + (complex c2); //+����Ϊ��Ա����  
		complex operator - (complex c2); //-����Ϊ��Ա����  
		void display( );  //������� 
	private:      		//˽�����ݳ�Ա  
		double real;   //����ʵ��  
		double imag;   //�����鲿 
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
