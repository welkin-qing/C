#include <iostream> 
using namespace std; int main( ) 
{  
	int m,n;  
	cout<<"Please input two integers:"; cin>>m>>n;  
	try{ 
		if (n==0)   throw 0;   
		cout<< (m/n)<<endl; //��try������а�����Ҫ��صĳ��򲿷�  
		}  
	catch(int) //catch ��䲶��һ�������쳣
  	{   
		cout<<"Divided by 0!"<<endl;   
		return -1;  
	}   
	return 0; 
} 


