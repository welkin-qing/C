#include <iostream> 
using namespace std; int main( ) 
{  
	int m,n;  
	cout<<"Please input two integers:"; cin>>m>>n;  
	try{ 
		if (n==0)   throw 0;   
		cout<< (m/n)<<endl; //在try代码块中包含需要监控的程序部分  
		}  
	catch(int) //catch 语句捕获一个整型异常
  	{   
		cout<<"Divided by 0!"<<endl;   
		return -1;  
	}   
	return 0; 
} 


