#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class Score
{ //Score ¿‡∂®“Â
	float computer;
	float english;
	float mathematics;
	public:
		Score(float x1, float y1, float z1);
		Score( );
		void print( );
		void modify(float x2, float y2, float z2);
}; 

class Student 
{
	private:
		int number;
		char *name;
		float score;
		Score score1;
	public:
		Student(int number1,char *name1,float score1,float x1, float y1, float z1);
		Student(int number1,char *name1,float score1);
		~Student();
		void modify(float score2,float x2, float y2, float z2)
		{
			score=score2;
			score1.modify(x2, y2,z2);
		}
		void print();
};

Student::Student(int number1,char *name1,float score1,float x1, float y1, float z1):score1(x1,y1,z1)
{
	number=number1;
	name=new char[strlen(name1)+1];
	strcpy(name,name1);
	score=score1;
}
Student::Student(int number1,char *name1,float score1):score1()
{
	number=number1;
	name=new char[strlen(name1)+1];
	strcpy(name,name1);
	score=score1;
}
Student::~Student()
{
	delete [] name;
}
void Student::print()
{
	cout<<"number: "<<number<<" name: "<<name
	    <<" score: "<<score<<'\n'; 
	score1.print( );   
}




Score::Score(float x1, float y1, float z1)
{
	computer=x1;
	english=y1;
	mathematics=z1;
}

Score::Score()
{
	computer=100;
	english=100;
	mathematics=100;
}

void Score::print( )
{
	cout<<" computer: "<<computer<<endl;
	cout<<" english: "<<english<<endl;
	cout<<" mathematics: "<<mathematics<<endl;
	cout<<'\n'<<endl;
}

void Score::modify(float x2, float y2, float z2)
{
	computer=x2;
	english=y2;
	mathematics=z2;
}

int main()
{
	int numberi;
	char namei[15];
	float scorei;
	float a,b,c;
	cout<<"Enter three grads:\n";
	cout<<"computer"<<endl;
	cin>>a;
	cout<<"english"<<endl;
	cin>>b;
	cout<<"mathematics"<<endl;
	cin>>c;
	
	cout<<"Enter number:\n"; cin>>numberi;
	cout<<"Enter name :\n"; cin>>namei;
	cout<<"Enter score:\n";cin>>scorei;
	Student stu1(numberi,namei,scorei,a,b,c);

	stu1.print();
	
	cout<<"Enter number:\n"; cin>>numberi;
	cout<<"Enter name :\n"; cin>>namei;
	Student stu2(numberi,namei,scorei);
	stu2.print();
	cout<<"Enter three grads:\n";
	cout<<"computer"<<endl;
	cin>>a;
	cout<<"english"<<endl;
	cin>>b;
	cout<<"mathematics"<<endl;
	cin>>c;
    stu2.modify(87,a,b,c);
	stu2.print();
	return 0;

}

