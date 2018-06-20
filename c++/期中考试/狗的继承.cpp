#include <iostream>
//#include <cmath> 
using namespace std;
class shape{
	public:
		virtual double getAge()=0;
}; 
class Animal:public shape{
	private:
		double age;
	public:
		Animal(double age1)
		{
			age=age1;
		}
		double getAge()
		{
			return(age);
		 } 
}; 
class shape1{
	public:
		virtual double showInfor()=0;
};
class Dog:public shape1{
	private:
		double age;
		string color;
	public:
		Dog(double age1,string color1)
		{
			age=age1;
			color=color1;
		}
		double showInfor(){
			cout<<"age:"<<age;
			cout<<'\n';
			cout<<"color:"<<color;
		}
};

int main(){
	Animal ani(5);
	cout<<"age of ani:"<<ani.getAge()<<endl;
	Dog dog(5,"black");
	cout<<"infor of dog:"<<endl;
	dog.showInfor();
}
