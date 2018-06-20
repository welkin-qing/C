#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double m,n,p;
	double area,sum;
	cin>>m>>n>>p;
	sum=(m+n+p)/2;
	if(m+n>p&&m+p>n&&p+n>m){
		area=sqrt(sum*(sum-m)*(sum-n)*(sum-p));
		cout<<area<<endl;
	}else{
		cout<<"no"<<endl;
	}
}
