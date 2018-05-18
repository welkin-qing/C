#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char &c);//����һ�������������ȼ�

/*

������ɵĹ����ǽ�һ����׺���ʽת��Ϊһ����׺���ʽ��
�������룺a*b+c
���������ab*c+

*/

int main()
{
//-----------------�����-------------------
string s;
cin>>s; //�������
stack<char> sc;

sc.push('#'); //��Ϊջ�׵ı�־

//-----------------�����-------------------
for(int i=0;i<s.length();i++)//��������ַ��������������
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

int precedence(char &c)//����һ�������������ȼ�
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
