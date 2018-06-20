#include<iostream>
#include<string>
using namespace std;
void filename(const string & str){
	int found=str.find_last_of("/\\");
	cout<<str.substr(0,found)<<endl;
	cout<<str.substr(found+1)<<endl; 
}
int main()
{
	string str1;
	getline(cin,str1);
	filename(str1);
	return 0;
}
