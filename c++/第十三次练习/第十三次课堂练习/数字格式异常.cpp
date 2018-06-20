#include <iostream>
#include<string.h>
using namespace std;
int f;
int toNumb(char co[])
{
	int len=strlen(co);
	int i;
	int sum=0;
	int w=1;
	for(i=len-1;i>=0;i--)
	{
		if(!(co[i]<='9' && co[i]>='0'))
		{
			f=1;
			return 0;
		}
		sum+=w*(co[i]-'0');
		w*=10;
	}
	return sum;
}
int main ()
{
	string a,b;
	while(1)
	{
		cin>>a>>b;
		f=0;
		int m=toNumb(&a[0]);
		int n=toNumb(&b[0]);
		if(f)
		{
			cout<<"Incorrect input and re-enter two integers:"<<endl;
			continue;
		}
		else
		{
			cout<<"Sum is "; 
			cout<<m+n<<endl;
			break;
		}
	}
	
}

