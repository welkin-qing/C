#include<iostream>
using namespace std;
int main()
{
   int k,i=0,m=0;
   cin>>k;
   while(1)
   {
   int b=0,sum=0;
   while(1){
   cin>>i;
   m=i;
        b++;
        if(b<=k)
        {
        	sum+=i;
		}
		if((i=getchar())=='\n')break; 
    }
    if(m!=100){
   	if(b<=k)
   	cout<<sum/b<<'\n';
   	else
   	cout<<sum/k<<'\n';
   }
   if(m==100) break;
   }	
 } 
