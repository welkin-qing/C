#include <iostream>
#include <string>
using namespace std;
//你提交的代码将被嵌入到这里
int Max(int a,int b)
{
	return  (a>b)?a:b;
}
char Max(char a,char b)
{
	return  (a>b)?a:b;
}
string Max(string a,string b)
{
	return  (a>b)?a:b;
}

 int main( )
{
  int m,n;
  char c,d;
  string s1,s2;
  cin>>m>>n;
  cin>>c>>d;
  cin>>s1>>s2;
  cout<<Max(m,n)<<endl;
  cout<<Max(c,d)<<endl;
  cout<<Max(s1,s2)<<endl;
    return 0 ;
}

