//�����ڽ��д���Ĺ����л���No��߳���0 
//����Ϊ���������ýϲ�����
//�ɸĳɲ��ú������õķ�ʽ��� 
#include<iostream>
#include<math.h>
using namespace std;
double fun1(double o,double p,double q);
int main(){
	double o,p,q;
	cin>>o>>p>>q;
	cout<<fun1(o,p,q)<<endl;
}
double fun1(double o,double p,double q)
{
	double sum;
	double squ;
	if(o+p>q&&o+q>p&&p+q>o)
	{
		sum=(o+p+q)/2;
		squ=sqrt(sum*(sum-o)*(sum-p)*(sum-q)); 
		return(squ);
	}
	else cout<<"No"<<endl;
}
