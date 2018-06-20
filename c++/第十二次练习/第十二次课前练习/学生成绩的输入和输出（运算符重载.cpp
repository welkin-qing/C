#include <iostream>
#include <string>
using namespace std;

/* 请在这里填写答案 */
class Student
{
public:

	friend istream &operator>>(istream &input,Student &stu)
	{
		input>>stu.name>>stu.number;
		return input;
	}
	friend ostream &operator<<(ostream &output,Student &stu)
	{
		i++;
		if(stu.number>=60)
		{
			output<<i<<". "<<stu.name<<" PASS";
		}
	
		if(stu.number<60) 
		{
			output<<i<<". "<<stu.name<<" FAIL"; 
		}
		return output;
	}
private:
	string name; int number;
	static int i;
};
int Student::i=0;

int main(){
    int i, repeat;
    Student st;
    cin>>repeat;
    for(i=0;i<repeat;i++){
        cin>>st;
        cout<<st<<endl;
    }
    return 0;
}
