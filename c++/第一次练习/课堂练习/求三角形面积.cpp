//此题在进行错误的过程中会在No后边出现0 
//是因为函数的作用较不完美
//可改成不用函数调用的方式解决 
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
