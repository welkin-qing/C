#include<iostream>
using namespace std;
class counter{ 
	int value; 
public: 
	counter(int number);    
	void increment();        //��ԭֵ�� 1 
	void decrement();        //��ԭֵ�� 1 
	int getvalue();          //ȡ�ü�������ֵ 
	void print();            //��ʾ��������ֵ 
};
counter::counter(int number)
{
	value=number;
}
void counter::decrement()
{
	value=value-1;
}
void counter::increment()
{
	value=value+1;
}
int counter::getvalue()
{
	return value;
}
void counter::print()
{
	cout<<value<<endl;
}
int main()
{
	int numberi;
	cout<<"number:\n";
	cin>>numberi;
	counter coun1 (numberi);
	cout<<"number-1"<<"\n";
	coun1.decrement();
	coun1.print();
	cout<<"number+1"<<"\n";
	coun1.increment();
	coun1.print();
}
