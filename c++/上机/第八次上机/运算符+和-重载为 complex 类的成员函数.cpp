#include<iostream>
using namespace std; 
class complex //����������
{
	private: //˽�����ݳ�Ա
		double real; //����ʵ��
		double imag; //�����鲿
	public: //�ⲿ�ӿ�
		complex(double r=0.0,double i=0.0) //���캯��
		{real=r;imag=i;}
		complex operator +(complex c2); //+����Ϊ��Ա����
		complex operator -(complex c2); //-����Ϊ��Ա����
		void display( ); //�������
};
complex complex::operator +(complex c2)
{
	complex c;
    c.real=real+c2.real;
	c.imag=imag+c2.imag;
	return c;	
}
complex complex::operator -(complex c2)
{
	complex c;
	c.real=real-c2.real;
	c.imag=imag-c2.imag;
	return c;
}
void complex::display()
{
	cout<<real<<"+"<<imag<<"i"<<endl; 
}
int main()
{
    complex a(8.5,2),b(3.2,4);
	complex k;
	k=a+b;
	k.display();
	k=b-a;
	k.display();
}

