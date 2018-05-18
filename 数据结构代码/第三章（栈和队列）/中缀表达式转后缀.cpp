#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char &c);//返回一个操作符的优先级

/*

程序完成的功能是讲一个中缀表达式转换为一个后缀表达式：
例如输入：a*b+c
将会输出：ab*c+

*/

int main()
{
//-----------------输入块-------------------
string s;
cin>>s; //输入完毕
stack<char> sc;

sc.push('#'); //作为栈底的标志

//-----------------处理块-------------------
for(int i=0;i<s.length();i++)//对输入的字符串进行逐个处理
{
char c=s.at(i);

switch(c)
{
case '+':
case '-':
case '*':
case '/':

while(precedence(c)<=precedence(sc.top()))
{ 
cout<<sc.top();
sc.pop();
}
sc.push(c);
break; 
case '(':
sc.push(c);
break;
case ')':
while(sc.top()!='(')
{
cout<<sc.top();
sc.pop();
}
sc.pop();
break;
default:
cout<<c;

}

}
while(sc.top()!='#')
{
cout<<sc.top();
sc.pop();
}
cout<<endl;

return 0;
}

int precedence(char &c)//返回一个操作符的优先级
{
switch(c)
{
case '+':
return 1;
case '-':
return 1;
case '*':
return 2;
case '/':
return 2;
case '(':
return 0;
case '#':
return -1;

}

} 
