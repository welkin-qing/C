#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class Person
{
protected:
	string name;
	int age;
public:
	Person(){
	}
	Person (string p_name, int p_age)
	{
		name=p_name;
		age=p_age;
	}
    void display () {cout<<name<<":"<<age<<endl;}
};
class student:public Person
{
private:
	int ID;//学号
	float cpp_score;//上机成绩
	float cpp_count;//上机考勤
	float cpp_grade;//总评成绩   //总评成绩计算规则：cpp_grade = cpp_score * 0.9 + cpp_count * 2;
public:
	student(){}
	student(string p_name, int p_age,int id,float score,float count):Person(p_name,p_age)
	{
		ID=id;
		cpp_score=score;
		cpp_count=count;
		cpp_grade=score*0.9+count*2;
		//p_grade = cpp_score * 0.9 + cpp_count * 2;
	}
	void print()
	{
		cout<<age<<" "<<name<<" ";
		cout<<fixed<<setprecision(1)<<cpp_grade<<endl;
		//cout<<fixed<<setprecision(1)<<cpp_grade;
	}
};

int main()
{

	student st[100];
	int age,id,nums=0;
	float sc,count;
	string n;
	while(1)
	{
		cin>>n;
		if(n!="0")
		{cin>>age>>id>>sc>>count;
		student m(n,age,id,sc,count);
			st[nums]=m;
			nums++;
			
		}
		else 
		for(int i=0;i<nums;i++)
	{
		st[i].print();
	}
}
	
	
return 0;
 } 

