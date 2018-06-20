#include <iostream>
#include <cmath>
using namespace std;
class Complex
{
private:
	double real,image;
	static int count;
public:
	Complex(double real1,double image1)
	{   real=real1;
		image=image1;
		count++;
	}
	void rev(double &real1,double &image1);
	friend void sum(Complex& c1,Complex& c2);
	friend void sum1(Complex& c1,Complex& c2);
	void print(double r2,double i2) ;
	static int getcount(){return count;}
	
};

void Complex::rev(double &real,double &image)
{
		real=-real;
	 image=-image;
}

void sum(Complex& c1,Complex& c2)
{
//	double dreal=c1.real+c2.real;
//	double dimage=c1.image+c2.image;
	cout<<"("<<c1.real+c2.real<<","<<c1.image+c2.image<<")"<<endl;	
}
void sum1(Complex& c1,Complex& c2)
{
  c2.rev(c2.real,c2.image);
	cout<<"("<<c1.real+c2.real<<","<<c1.image+c2.image<<")";	
}

void Complex::print(double r2,double i2){
	cout<<"("<<r2<<","<<i2<<")"<<endl;
}

int Complex::count=0;
int main()
{ double real1,image1,real2,image2;
cin>>real1>>image1>>real2>>image2;
	Complex c1(real1,image1);
	Complex c2(real2,image2);
	cout<<Complex::getcount()<<endl;
	sum(c1,c2);
	sum1(c1,c2);
	return 0;
	
	
}

