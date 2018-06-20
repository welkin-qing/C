#include<iostream>
#include<cstring>
using namespace std;
class Student {
	private:
	int number;
	char *name;
	float score;
	public:
	student(int num,char *na,float sco);
	void print();
};
student::student(int num,char *na,float sco)
{
	number=num;
	name=new char(strlen(na)+1);
	strcpy(name,na);
	score=sco;
}
void student::print()
{
	cout<<number<<endl<<name<<endl<<score<<endl;
}
int  main()
{
	Student   a[5]={student(1,"zhangsan",90), student(2,"lisi",78),student(3,"wangwu",88),student(4,"maliu",90),student(5,"singto",100)};
	student *p=a;
	int i;
	for(i=0;i<5;i++)   a[i].print();
	for(p=a;p<a+5;p++)  p->print();
}

