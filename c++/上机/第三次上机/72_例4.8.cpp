#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

class myString{
	char s[80];
	public:
		void prnf() {cout<<s<<"\n";}
		void set (char *str) {strcpy(s,str);}
};
myString input()
{
	char instr[80];
	myString str;
	cout<<"Enter a string: ";
	cin>>instr;
	str.set(instr);
	return str;
}
int main()
{
	myString ob;
	ob=input();
	ob.prnf();
	return 0;
}
