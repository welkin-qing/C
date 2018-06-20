#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double o,p,q;
	double sum;
	double squ;
	cin>>o>>p>>q;
	if(o+p>q&&o+q>p&&p+q>o)
	{
		sum=(o+p+q)/2;
		squ=sqrt(sum*(sum-o)*(sum-p)*(sum-q)); 
		//return(squ);
		cout<<squ<<endl;
	}
	else cout<<"No"<<endl;
	//return 0; 
}
