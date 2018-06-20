#include <iostream>
#include <cmath>
#include<string.h> 
using namespace std;
class Person {
	protected:
     	string name;
     	int age;
	public:
     	Person();	  
     	Person (string p_name, int p_age);
     	void display () {cout<<name<<“:”<<age<<endl;}
};
class Student : public Person{
	private:
		int ID;//学号
		float cpp_score;//cpp上机成绩
		float cpp_count;//cpp上机考勤
		float cpp_grade;//cpp总评成绩
     //总评成绩计算规则：cpp_grade = cpp_score * 0.9 + cpp_count * 2;
     public:
     	Student(float cpp_score1,float cpp_count1,float cpp_grade1)
     	{
     		cpp_grade=cpp_grade1;
     		cpp_count=cpp_count1;
     		cpp_score=cpp_score1;
     		
		 }
		 float fun1()
		 {
		 	cpp_grade = cpp_score * 0.9 + cpp_count * 2;
		 }
		 void print()
		 {
		 	cout<<ID<<name<<cpp_grade<<endl; 
		 }
}; 
int main()
{
	string name;
	int age;
	int ID;
	float cpp_score;
	float cpp_count;
	cin>>name>>ID>>age>>cpp_score>>cpp_count;
	Student stu;
	
}
