#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int i,n;
	char str1[50];
	gets(str1);
	n=strlen(str1);
	if(n!=11)
	{
		cout<<"No!";
		return 0;
	}else{
		for(i=0;i<n;i++)
		{
			if((str1[i]<'0')||(str1[i]>'9'))
			{
				cout<<"No";
				return 0;
			}
		} 
	}
	if(str1[0]!='1')
	{
		cout<<"No";
		return 0;
	 }
	 else cout<<"Yes";
	 return 0;
	 
}
