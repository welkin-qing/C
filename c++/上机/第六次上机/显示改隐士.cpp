#include <iostream>
//��һ�ַ��������¹��캯�� 
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
	cout<<Min<int>(i,cobj1)<<endl;//��ʽʵ����
	//cout<<Min(i,cobj1)<<endl;
	cout<<Min(dobj1,dobj2)<<endl; //��ʽʵ����
	cout<<Min<char>(cobj2,j)<<endl; //��ʽʵ����
	//cout<<Min(cobj2,j)<<endl;
	return 0;
}

