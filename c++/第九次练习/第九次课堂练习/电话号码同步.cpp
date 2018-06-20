#include<iostream>
#include<string>
#include<set>
#include <algorithm>
using namespace std;
int main()
{
	set<string> tex;
	string s;
	while(1)
	{
		getline(cin,s);
		tex.insert(s);
		if(s=="end")
		break;
	}
	while(1)
	{
		getline(cin,s);
		tex.insert(s);
		if(s=="end")
		break;
	}
	set<string>::iterator p=tex.begin() ;
	while(p!=tex.end()&&*p!="end")
	{
	
//		cout<<*p<<endl;
//		p++;
//		if(*p!="end")
//		{
			cout<<*p<<endl;
			p++;
			//	}		
	}
	return 0;
}
