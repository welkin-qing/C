#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a,b,c,m;
	int i,j;
	getline(cin,a);
	while(1){
		getline(cin,m);
		if(m.compare("end")==0)  break;
		a=a+'\n';
		a=a+m;
	}
	a=a;
	getline(cin,b);
	getline(cin,c);
	i=a.find(b);
	while(i!=string::npos)  //npos==-1表示不存在 
	{
		a.replace(i,b.length(),c);
		i=a.find(b,i+1);
	}
	cout<<a;
	return 0;
} 
