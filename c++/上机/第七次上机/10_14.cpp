#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1( "This is a test.");
	string str2( "ABCDEFG");
	
	cout << "Initial strings: \n";
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << "\n\n";
	
	//insert()
	cout << "Insert str2 into str1: \n";
	str1.insert( 5, str2);
	cout << str1 << "\n\n";
	
	//eraser()
	cout << "Remove 7 chars from str1: \n";
	str1.erase( 5, 7);
	cout << str1 << "\n\n";
	
	//replace()
	cout << "Replace 2 chars in str1 with str2: \n";
	str1.replace( 5, 2, str2);
	cout << str1 << endl;
	
	return 0;
}

