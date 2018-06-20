#include <iostream> 
using namespace std; 
int main()
{
	char *name;
	name= new char[20];
	cin>>name;
	 cout<<name;
	 delete name;
}

