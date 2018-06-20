//输入样例:
//16.8
//输出样例:
//485.5875
//84
#include<iostream>
#include<math.h>
using namespace std;
double fun1(double n);
double fun2(double n);
int main()
{
	double n; 
	cin>>n;
	cout<<fun1(n)<<endl;
	cout<<fun2(n)<<endl;
 }
double fun1(double m)
{
	double squ;
	squ=m*m*sqrt(25+10*sqrt(5))/4;
	return(squ);
}
double fun2(double m)
{
	double sum;
	sum=5*m;
	return(sum);
}
