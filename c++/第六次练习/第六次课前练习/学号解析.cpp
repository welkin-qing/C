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
cout<<"姓名:"<<ends<<name<<endl;
cout<<"学号:"<<ends<<id<<endl;
cout<<"成绩:"<<ends<<score<<endl;
}
int main()
{
 Student stu("小明",19,97);
 stu.display();
 system("pause");
 return 0;
}
