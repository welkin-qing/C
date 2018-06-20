//第二种方法,利用指针 
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
	cout<<min<int>(i,cobj1)<<endl; //显式实例化  
	cout<<min(dobj1,dobj2)<<endl;  //隐式实例化  
	cout<<min<char>(cobj2,j)<<endl; //显式实例化  
	return 0; 
} 

