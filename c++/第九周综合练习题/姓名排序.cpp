#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string a;
	vector<string> s;
	while(1){
		getline(cin,a);
		if(a =="end")
		break;
		s.push_back(a);
	}
	sort(s.begin(),s.end());
	vector<string>::iterator p=s.begin();
	while(p!=s.end())
	{
		cout<<*p<<' ';
		p++;
	}
	cout<<endl;
	return 0;
} 
