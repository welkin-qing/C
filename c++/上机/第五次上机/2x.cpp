#include <iostream>
#include <cstring>
using namespace std;

class Person {
	protected:
		string name;
	public :
		Person(string n){
			//name = new char[n.length()+1];
			name = n;
			cout<<"This is the basic class!"<<endl;
		}
		~Person(){
			//delete [] name;
			cout<<"This is the basic class!"<<endl;
		}
};

class Student :public Person{
	private:
		int number;
		float score;
	public:
		Student(int num,string n,float s):Person(n){
			number = num;
			score = s;
			cout<<"This is the derive class!"<<endl;
		}
		~Student (){
			//delete [] name;
			cout<<"This is the derive class!"<<endl;
		}
		void show (){
			cout<<"number: "<<number<<", name: "<<name<<", score: "<<score<<endl;
		}
};

int main(){
	int num;
	string name;
	float score;
	
	cout<<"Enter a student's number,name and score: "<<endl;
	cin>>num>>name>>score;
	cout<<endl<<"构造函数："<<endl; 
	Student stu(num,name,score);
	cout<<endl;
	stu.show();
	cout<<endl<<"析构函数："<<endl; 
		
	return 0;
}

