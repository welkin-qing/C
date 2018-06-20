#include<iostream>
#include<string.h>
#include<list>
using namespace std;
int main()
{
	list<string>lis;
	int i,n;
	string s;
	cin>>n;
	for(i=0;i<n;i++)
	{
	    cin>>s;
	    lis.push_back(s); 
	}
	lis.sort(); 
		list<string>::iterator p=lis.begin() ;
		while(p!=lis.end() )
		{
			cout<<*p<<endl;
			p++;
		 } 
	return 0;
}
