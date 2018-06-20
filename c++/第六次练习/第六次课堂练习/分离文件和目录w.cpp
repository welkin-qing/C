#include <iostream>
#include<string>
using namespace std;


void filename(const string & str)
{
   int  found=str.find_last_of("/\\");
   //find_last_of()函数可以执行简单的模式匹配,查找最后出现斜杠“/”或反斜杠“\”的位置 
	cout<<str.substr(0,found)<<endl;  //从0到记录位置取子串 
	cout<<str.substr(found+1)<<endl; //从该位置到结束取子串 
}
int main()
{
	string str1;
	getline(cin,str1);
	filename(str1);
	return 0;
}

