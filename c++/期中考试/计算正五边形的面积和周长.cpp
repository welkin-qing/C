#include<iostream>
#include<math.h>
using namespace std;
double line(double n);
long double area(double n);
int main()
{
	double n;
	cin>>n;
	cout<<line(n)<<endl;
	cout<<area(n)<<endl;
 } 
double line(double n)
{
	return(5*n);
}
long double area(double n)
{
	return(n*n*sqrt(25+10*sqrt(5))/4); 
}
