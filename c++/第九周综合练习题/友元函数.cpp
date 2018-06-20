#include<iostream>
#include<string>
using namespace std;
class student
{
	private:
		string num;
		double score;
	public:
			void set(string num1,double score1)
			{
				num=num1;
				score=score1;
			}
	friend double average(student *p,int count);
		
		
}stu[100];
double average(student *p,int count)
{
		double ave;
		double  sum=0;
		int i;
		for(i=0;i<count;i++)
		{
				sum=sum+p[i].score;
				
		}
		ave=sum/count;
		return ave;
		
}
int main()
{
	string num;
	double score;
	int k=0;
	while(1)
	{
		cin>>num;
		if(num=="0")
		break;
		cin>>score;
		stu[k].set(num,score);
		k++;
	}
	cout<<average(stu,k);
	return 0;
}
