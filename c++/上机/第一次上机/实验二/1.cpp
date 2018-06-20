#include <iostream> 
using namespace std;
int model = 90;   // model is a const const int v[ ]={1,2,3,4}; // v[i] is a const 
int v[ ]={1,2,3,4}; // v[i] is a const 
const int x=90;   // error: no initializer
void f( ) {  
model =200; // error  
v[2]++; 
cout<<model<<' '<<x;  // error 
}
 
int main( ) 
{
	f();
}

