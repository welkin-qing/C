#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int i,j,k;
	char t;
	string a;
	getline(cin,a);
	k=a.length();
	for(i=1;i<k;i++)
	{
		for(j=1;j<=(k-i);j++)
		if(a[j]<a[j-1])
		{
			t=a[j];
			a[j]=a[j-1];
			a[j-1]=t;
		}
	}
	cout<<a<<endl;
	return 0; 
}


