#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
class Student{
	char s[80];
	long int num;
	double weight;
	double height;
	int age;
	public:
		void prnf() {
			cout<<"name:"<<s<<"\n";
			cout<<"num:"<<num<<"\n";
			cout<<"weight:"<<weight<<"\n";
			cout<<"height:"<<height<<"\n";
			cout<<"age:"<<age<<"\n";
		}
		void set (char *str) {strcpy(s,str);}
};
Student input()
{
	char instr[80];
	long int num;
	double weight;
	double height;
	int age;
	Student str;
	cout<<"Enter a name: ";
	cin>>instr;
	str.set(instr);
	cout<<"Enter a num: ";
	cin>>num;
	cout<<"Enter a weight: ";
	cin>>weight;
	cout<<"Enter a height: ";
	cin>>height;
	cout<<"Enter a age: ";
	cin>>age;
	return str;
}
int main()
{
	Student ob;
	ob=input();
	ob.prnf();
	return 0;
}
