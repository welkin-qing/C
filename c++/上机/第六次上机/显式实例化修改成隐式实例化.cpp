//�ڶ��ַ���,����ָ�� 
#include <iostream> 
using namespace std; 
template <class T>  
T min(T *a, T *b) 
{  
	return (a<b)?a:b;
}
 int main( ) 
{  
	double dobj1=1.1, dobj2=2.2;  
	char cobj1='c', cobj2='W'; 
	int i=12,j= 68; 
	//min<int>(i,cobj1); 
	cout<<min<int>(i,cobj1)<<endl; //��ʽʵ����  
	cout<<min(dobj1,dobj2)<<endl;  //��ʽʵ����  
	cout<<min<char>(cobj2,j)<<endl; //��ʽʵ����  
	return 0; 
} 

