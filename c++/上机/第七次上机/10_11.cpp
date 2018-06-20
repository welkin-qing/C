#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map <string, string> m;
	int i;
	string s;
	
	m.insert( pair <string, string> ( "yes",    "no"));
	m.insert( pair <string, string> (  "up",  "down"));
	m.insert( pair <string, string> ("left", "right"));
	m.insert( pair <string, string> ("good",   "bad"));
	
	cout << "Enter word:";
	cin  >> s;
	
	map <string, string>::iterator p;
	
	p = m.find(s);
	if( p != m.end())
		cout << "Opposite: " << p->second << endl;
	else
		cout << "Word not in map.\n";
		
	return 0;
	
}
