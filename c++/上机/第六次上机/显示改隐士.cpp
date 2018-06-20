#include <iostream>
//第一种方法，重新构造函数 
using namespace std;
template <class T>
T Min(T a, T b)
{
	return (a<b)?a:b;
}
int main( )
{
	double dobj1=1.1, dobj2=2.2;
	char cobj1='c', cobj2='W';
	int i=12,j= 68;
	cout<<Min<int>(i,cobj1)<<endl;//显式实例化
	//cout<<Min(i,cobj1)<<endl;
	cout<<Min(dobj1,dobj2)<<endl; //隐式实例化
	cout<<Min<char>(cobj2,j)<<endl; //显式实例化
	//cout<<Min(cobj2,j)<<endl;
	return 0;
}

