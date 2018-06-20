#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //请注意：教材中遗漏了这一行。
using namespace std;

void load( vector <int> &);
void print( vector <int>);
const int SIZE = 8;

int main()
{
	vector <int> v (SIZE);
	
	load( v);
	sort( v.begin(), v.end());
	print( v);

	return 0;
}

void load( vector <int> & v)
{
	v[0] =12345;
	v[1] =78965;
	v[2] =34567;
	v[3] =23456;
	v[4] =12367;
	v[5] =45678;
	v[6] =56777;
	v[7] =22234;
}

void print(vector <int> v)
{
	int i = 0;
	
	for( i = 0; i < SIZE; i++)
		cout << v[i] << endl;
	
	cout << endl;
	
}

