#include<iostream>
using namespace std;
int myMax(int m,int n,int q){
	if(m>n&&m>q) return(m);
	if(n>m&&n>q) return(n);
	if(q>m&&q>n) return(q);
}
double myMax(double m,double n){
	if(m>n) return(m);
	else return(n); 
}
int main(){
	cout<<myMax(3,4)<<endl;
	cout<<myMax(3,4,5)<<endl;
	cout<<myMax(4.3,3.4)<<endl;
}

