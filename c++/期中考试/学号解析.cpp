#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	string s1(s,0,4);
	string s2(s,4,2);
	string s3(s,6,2);
	cout<<"year:"<<s1<<endl;
    cout<<"department:"<<s2<<endl;
    cout<<"class:"<<s3<<endl;
	return 0;	
} 
