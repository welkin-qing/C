#include<iostream>
#include<cstring>
using namespace std;
class Score
{ //Score 类定义
 	float computer;
 	float english;
 	float mathematics;
public:
	Score(float x1, float y1, float z1);//构造函数 
 	Score( );
void print( );
void modify(float x2, float y2, float z2);
};
Score::Score():computer(100),english(99),mathematics(98){
}
Score::Score(float x1,float y1,float z1):computer(x1),english(y1),mathematics(z1){
}
void Score::print(){
	cout<<"computer:"<<computer<<endl;
	cout<<"english:"<<english<<endl;
	cout<<"mathematics:"<<mathematics<<endl;
}
void Score::modify(float x2,float y2,float z2){
	computer=x2;
	english=y2;
	mathematics=z2;
	cout<<"T computer:"<<computer<<endl;
	cout<<"T english:"<<english<<endl;
	cout<<"T mathematics:"<<mathematics<<endl;
}
class Student{
	private:
		int number;
		char*name;
		float score;
	public:
		Score lsy1;
		Student(int number1,char*name1,float score1);
		~Student();
		void modify(float score1){
			score=score1;
		}
		void print();		
};
Student::Student(int number1,char*name1,float score1){
	number=number1;
	name=new char[strlen(name1)+1];
	strcpy(name,name1);
	score=score1;
}
Student::~Student(){
	delete [] name; 
}
void Student::print(){
	cout<<"number:"<<number<<"name:"<<name
	<<"score:"<<score<<endl;
}
int main(){
	int numberi;
	char namei[15];
	float scorei;
	cout<<"Enter number:\n";cin>>numberi;
	cout<<"Enter name:\n";cin>>namei;
	cout<<"Enter score:\n";cin>>scorei;
	Student stu1 (numberi,namei,scorei);
	cout<<"Enter number:\n";cin>>numberi;
	cout<<"Enter name:\n";cin>>namei;
	Student stu2 (numberi,namei,scorei);
	stu2.modify(87);
	stu1.print();
	stu2.print();
	cout<<"Score类测试1"<<endl; 
	stu1.lsy1.print();
	float a1,b1,c1;
	cout<<"请输入修改值1："<<endl; 
	cin>>a1>>b1>>c1;
	stu1.lsy1.modify(a1,b1,c1);
	cout<<"Score类测试2"<<endl;
	cout<<"请输入成绩（三门）"<<endl; 
	float h1,h2,h3;
	cin>>h1>>h2>>h3;
	Score lsy2(h1,h2,h3); 
	 lsy2.print();
	float x2,y2,z2;
	cout<<"请输入修改值："; 
	cin>>x2>>y2>>z2;
	lsy2.modify(x2,y2,z2);
	return 0;
}

