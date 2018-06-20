#include <iostream>
using namespace std;
/* 你提交的代码将被嵌入到这里 */
void f(int a[],int n,int &max,int &min);
int main( )
{
  int a[10];
  int max,min,i;
  for(i=0;i<10;i++){
     cin>>a[i];
  }
  f(a,10,max,min);
  cout<<"Max: "<<max<<endl;
  cout<<"Min: "<<min<<endl;
  return 0;
}
void f(int a[],int n,int &max,int &min)
{
//	int i,j;
//	int t;
//	for(i=0;i<9;i++)
//	for(j=i;j<10;j++)
//	{
//		if(a[i]>a[j])
//		{
//			t=a[i];
//			a[i]=a[j];
//			a[j]=t;
//		}
//	}
//	max=a[0];
//	min=a[9];


	max=min=a[0];
	for(int i=1;i<n;i++)
	{
		if(max<a[i]) max=a[i];
		if(min>a[i]) min=a[i];
		}	
}
