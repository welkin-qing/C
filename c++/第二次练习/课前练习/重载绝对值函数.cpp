#include"iostream"
//using namespace std;

using std::cin;
using std::cout;
using std::endl;
//你提交的代码将被嵌入到这里
int abs(int a);
long abs(long a);
double abs(double a);
int main()
{
  int x1; long x2; double x3;
  cin>>x1>>x2>>x3;
  cout<<"x1="<<abs(x1)<<endl;
  cout<<"x2="<<abs(x2)<<endl;
  cout<<"x3="<<abs(x3)<<endl;
  return 0;
}
int abs(int a)
{
	if(a<0)  a=-a;
	return(a);
 } 
long abs(long a)
{
	if(a<0)  a=-a;
	return(a);
}
double abs(double a)
{
	if(a<0) a=-a; 
	return(a);
}
