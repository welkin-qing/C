#include<stdio.h>
#include<math.h>
/*��n�Ľ׳�*/ 
/*int function(int n)
{
	long int f;
	if(n==0) return(1);
	f=function(n-1)*n;
	return(f);
}
main()
{
	int n,m;
	printf("��������n:\n");
	scanf("%d",&n);
	m=function(n);
	printf("%d",m);
	
}*/
/*��x��n�η�*/
int function(int x,int n)
{
	long int f;
	if(n==0) return(1);
	f=function(x,n-1)*x;
	return(f);
 } 
 main()
 {
 	int x,n,m;
 	printf("������x,n\n");
 	scanf("%d,%d",&x,&n);
 	m=function(x,n);
 	printf("%d",m);
  } 
