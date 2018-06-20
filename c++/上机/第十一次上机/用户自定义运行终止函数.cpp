#include <iostream> 
using namespace std; 
void myterm() //自定义的运行终止函数 
{  
	cout<<"This is my terminater."<<endl;  
	//...释放程序中申请的系统资源  
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

