#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
Student(string s,int a,int b):name(s),id(a),score(b){}
void display();
private:
string name;
 int id;
 int score;
};
void Student::display()
{
cout<<"����:"<<ends<<name<<endl;
cout<<"ѧ��:"<<ends<<id<<endl;
cout<<"�ɼ�:"<<ends<<score<<endl;
}
int main()
{
 Student stu("С��",19,97);
 stu.display();
 system("pause");
 return 0;
}
