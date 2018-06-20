#include<iostream>
#include<string>
using namespace std;
class student{
	private:
		string num;
		double score;
	public:
		void set(string n,double s)
		{
			num=n;
			score=s;
		}
	friend double average(student *p,int count);
}stu[100];
double average(student *p,int count)
{
	double sum;
	double aver;
	for(int i=0;i<count;i++)
	{
		sum=sum+p[i].score;
	}
	aver=sum/count;
	return(aver);
}
int main()
{
	string num;
	int score;
	int k=0;
	while(1){
		cin>>num;
		if(num=="0") break;
		cin>>score;
		stu[k].set(num,score);
		k++;
	}
	cout<<average(stu,k);
	return 0;
}
