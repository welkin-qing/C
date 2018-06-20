#include <iostream>
#include <string>
using namespace std;

class Student{
	private:
		int number;
		string name;
		float score;
	public:
		Student(int number1=0,string name1="noname",float score1=0); 
		void modify(float score1)
		{ score=score1;  }
		friend istream & operator >> (istream &input, Student &stu)
		{
			cout<<"Please input a student's number, name and score:\n";
			input>>stu.number>>stu.name>>stu.score;
			return input;
		}
		friend ostream & operator << (ostream &output, Student &stu)
		{
			output<<"number: "<<stu.number<<" name: "<<stu.name
			<<" score: "<<stu.score<<'\n';
			return output;
		}
};
//���캯���Ķ���
Student::Student (int number1,string name1,float score1)
{
	number=number1;
	name=name1;
	score=score1;
}

int main( )
{  
	Student stu1; 
	cout<<stu1; //��ѧ��Student�����stu1��Ϊһ���������

	cin>>stu1; //��ѧ��Student�����stu1��Ϊһ����������

	cout<<stu1; //��ѧ��Student�����stu1��Ϊһ���������
	return 0;
}

