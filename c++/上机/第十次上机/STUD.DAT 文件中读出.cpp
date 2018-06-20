#include <iostream>
#include <fstream>
#include <string.h> 
using namespace std;

class Student {
private:
	int number;
	char *name;
	float score;
public:
	Student(int number1, char *name1, float score1) {
		number = number1;
		name = new char[strlen(name1)+1];		// 申请动态存储单元
		strcpy(name, name1);
		score = score1;
	}
	~Student() {
		delete[] name;							// 释放动态内存单元
	}
	void modify(float score1) {
		score = score1;
	}
	friend ostream & operator << (ostream &output, Student &stu) {
		output << "number: " << stu.number << " name: " << stu.name << " score: " << stu.score << '\n';
		return output;
	} 
};

int main() {
	Student stu(2, "hahaha", 98);
	cout << " write student is:" << stu;

	ofstream fout("STUD.DAT", ios :: binary);
	fout.write((char *)&stu, sizeof(stu));
	fout.close();

	ifstream fin("STUD.DAT", ios :: binary);
	fin.read((char *)&stu, sizeof(stu));
	cout << "read stu is:" << stu << endl;
	fin.close();

	return 0;
}


