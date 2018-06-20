#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //请注意：教材中遗漏了这一行。
using namespace std;

void load( vector <string> &);
void print( vector <string>);
const int SIZE = 8;

int main()
{
	vector <string> v (SIZE);
	
	load( v);
	sort( v.begin(), v.end());
	print( v);

	return 0;
}

void load( vector <string> & v)
{
	v[0] = "Japan";
	v[1] = "Italy";
	v[2] = "Spain";
	v[3] = "Egypt";
	v[4] = "Chile";
	v[5] = "Zaire";
	v[6] = "Nepal";
	v[7] = "Kenya";
}

void print(vector <string> v)
{
	int i = 0;
	
	for( i = 0; i < SIZE; i++)
		cout << v[i] << endl;
	
	cout << endl;
	
}

