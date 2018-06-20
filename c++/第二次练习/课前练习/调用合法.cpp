#include<iostream>
using namespace std;
void f1(int * m,long & n); 
int main()
{
	int a;
	long b;
	cin>>a>>b;
	f1(&a,b);
}
void f1(int * m,long & n)
{
	cout<<m<<n<<endl;
	
}
