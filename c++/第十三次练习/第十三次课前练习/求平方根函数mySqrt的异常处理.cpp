#include<iostream>
#include<math.h>
using namespace std;
double mySqrt(double x)
{ 
    return sqrt(x); 
}
int main()
{
   double x;
   cin>>x;
   try
   {
    if(x<0)
      throw "Error: Can not take sqrt of negative number";
   	  cout<<"The sqrt of "<<x<<" is "<<mySqrt(x)<<endl;
   }	
   catch (const char  *s)
   {
   	cout<<s;
   }
   return 0;
}
