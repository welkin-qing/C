#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map <string, string> m;
	int i;
	string s;
	
	m.insert( pair <string, string> ( "jenny",    "1769266936"));
	m.insert( pair <string, string> (  "welkin",  "17691266930"));
	m.insert( pair <string, string> ("lisi", "15771726703"));
	m.insert( pair <string, string> ("meanning",   "18392995981"));
	
	cout << "Enter name:";
	cin  >> s;
	
	map <string, string>::iterator p;
	
	p = m.find(s);
	if( p != m.end())
		cout << "tele: " << p->second << endl;
	else
		cout << "Word not in map.\n";
		
	return 0;
	
}
