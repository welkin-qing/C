#include<iostream>
using namespace std;
class A {

public:

 void f1 (int d);
 void f2 (const int &d);
 void f3 (int d) const;
private:

   int data;
}; 
int main()
{
	A a;
	int m;
	cin>>m;
	f1(m);
 } 
