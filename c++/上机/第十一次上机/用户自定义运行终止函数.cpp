#include <iostream> 
using namespace std; 
void myterm() //�Զ����������ֹ���� 
{  
	cout<<"This is my terminater."<<endl;  
	//...�ͷų����������ϵͳ��Դ  
	exit(1); 
} 
int main() 
{  
	//...  
	try{   
		set_terminate(myterm);   
		//...   
		throw "Exception ... ";  
	}  
	catch(int i){  }  
	return 0; 
} 

