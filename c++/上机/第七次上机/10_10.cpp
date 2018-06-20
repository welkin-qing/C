#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

int main()
{
	list <char> lst;
	int i;
	
	for( i = 0; i < 10; i++)
		lst.push_back( 'A' + ( rand() % 26));
		
	cout << "Original contents: ";
	
	list <char>::iterator p = lst.begin();
	
	while( p != lst.end()){
		cout << *p;
		p++;
	}
	cout << endl << endl;
	
	lst.sort();
	cout << "Sorted contents: ";
	p = lst.begin();
	while( p != lst.end()){
		cout << *p;
		p++;
	}
	cout << endl;
	
	return 0;
}

