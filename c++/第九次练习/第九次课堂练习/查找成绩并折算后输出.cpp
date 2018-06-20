#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<string,int>tex;
	string s,s1;
	int f;
	while(1)
	{
		cin>>s;
		if(s=="noname")
		break;
		cin>>f;
		tex.insert(pair<string,int>(s,f));
		
	}
	cin>>s1;
	map<string,int>::iterator p;
	p=tex.find(s1); 
    if(p!=tex.end() )
	{
		cout<<p->second*0.21<<endl;
		
	}
	else
	cout<<"Not found.";
	return 0;
}
