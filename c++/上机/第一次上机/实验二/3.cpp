#include <iostream> 
using namespace std; 
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
long max(long a,long b)
{
	if(a>b) return a;
	else return b;
}
double max(double a,double b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	cout<<max(34,76)<<endl;
	cout<<max(34123431,2342325)<<endl;
	cout<<max(234.54,456.1)<<endl;
}

