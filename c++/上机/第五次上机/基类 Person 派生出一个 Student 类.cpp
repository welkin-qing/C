#include <iostream> 
#include<cstring>
using namespace std; 
class Person  //基类 
{ 
	public:   
		Person(const char* s)   
		{
	 		name = new char[strlen(s)+1]; strcpy(name, s); 
	 		cout<<"This is the basic class!"<<endl;
		}   
		~Person() //析构函数 
		{ 
			delete [] name;	
			cout<<"This is the basic class!"<<endl;
		} 
		
	protected:   
		char* name; 
}; 
class Student:public Person{  //派生 
	private:
		long number;
		int score; 
	public:
		Student(char* s,long n,int sco):Person(s)
		{
			number=n;
			score=sco;
			cout<<"This is the derive class!"<<endl;
		}
		~Student (){
			cout<<"This is the derive class!"<<endl;
		}
		void show()
		{
		//	cout<<"This is the derive class!"<<endl;
			cout<<"number:"<<number<<endl;
			cout<<"name:"<<name<<endl;
			cout<<"score:"<<score<<endl;
		}
};
int main(){
	long num;
	char* name;
	int score;
	
	//cout<<"Enter a student's name,number and score: "<<endl;
	//cin>>name>>num>>score;
	cout<<endl<<"构造函数："<<endl; 
	Student stu("welkin",151027,100);
	cout<<endl;
	stu.show();
	cout<<endl<<"析构函数："<<endl; 
		
	return 0;
}

