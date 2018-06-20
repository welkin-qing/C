#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1("This is a test");
	string str2("ABCDEFG");
	cout<<str1<<endl;
	cout<<str2<<endl<<endl;
	cout<<str1.insert(5,str2)<<endl;
    cout<<str1.erase(5,7)<<endl;
    cout<<str1.replace(5,2,str2)<<endl;
    return 0;
}



