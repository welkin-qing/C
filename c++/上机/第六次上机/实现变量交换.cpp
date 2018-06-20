#include<iostream>
using namespace std;
template <class T>
void Swap (T &x,T &y)
{
	T t;
	t=x;
	x=y;
	y=t;
}
main()
{
	int i=9,j=20;
	char c1='a',c2='b';
	cout<<"before exchange:\n";
	cout<<"i="<<i<<"\tj="<<j<<endl;
	cout<<"c1="<<c1<<"\tc2="<<c2<<endl;
	Swap(i,j);
	Swap(c1,c2);
	cout<<"after exchange:\n"; 
	cout<<"i="<<i<<"\tj="<<j<<endl;
	cout<<"c1="<<c1<<"\tc2="<<c2<<endl;
}
