#include <iostream> 
using namespace std; 
void sqr_it(int *i);  // function prototype ����ԭ�� 
int main( ) 
{  
	int x;  
	x=10;  
	sqr_it(&x);  // compiling time error: type mismatch ���Ͳ�ƥ��  cout<<"The square of x is "<<x<<'\n'; 
	return 0; 
} 
void sqr_it(int *i) 
{  
	*i=(*i)*(*i); 
	cout<<*i;
}

