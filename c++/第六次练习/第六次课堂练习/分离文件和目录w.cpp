#include <iostream>
#include<string>
using namespace std;


void filename(const string & str)
{
   int  found=str.find_last_of("/\\");
   //find_last_of()��������ִ�м򵥵�ģʽƥ��,����������б�ܡ�/����б�ܡ�\����λ�� 
	cout<<str.substr(0,found)<<endl;  //��0����¼λ��ȡ�Ӵ� 
	cout<<str.substr(found+1)<<endl; //�Ӹ�λ�õ�����ȡ�Ӵ� 
}
int main()
{
	string str1;
	getline(cin,str1);
	filename(str1);
	return 0;
}

