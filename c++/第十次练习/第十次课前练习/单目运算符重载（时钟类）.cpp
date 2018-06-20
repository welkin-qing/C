#include<iostream>
using namespace std;

class Clock {
	public:
		Clock(int NewH=0, int NewM=0, int NewS=0);
		void ShowTime();
		friend Clock operator++(Clock& op);         //ǰ�õ�Ŀ���������
		friend Clock operator++(Clock& op,int);     //���õ�Ŀ���������
	private:
		int Hour, Minute, Second;
};

Clock::Clock(int NewH, int NewM, int NewS) {
	Hour=NewH;
	Minute=NewM;
	Second=NewS;
}
void Clock::ShowTime() {
	cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

/*---------����������д��-----------*/
Clock operator++(Clock& op)
{
	++op.Second;
	if(op.Second>=60)
	{
		op.Second=op.Second-60;
		op.Minute++;
		if(op.Minute>=60)
		{
			op.Minute=op.Minute-60;
			op.Hour++;
		op.Hour=op.Hour%24;
		}
	}
	return op;
}

Clock operator++(Clock& op,int)
{
	Clock ob;
	ob=op;
	op.Second++;
	if(op.Second>=60)
	{
		op.Second=op.Second-60;
		op.Minute++;
		if(op.Minute>=60)
		{
			op.Minute=op.Minute-60;
			op.Hour++;
			op.Hour=op.Hour%24;
		}
	}
	return ob;
}


int main() {
	int h, m, s;
	cin>>h>>m>>s;
	Clock a(h,m,s);

	(++a).ShowTime();
	(a++).ShowTime();
	a.ShowTime();

	return 0;
}
