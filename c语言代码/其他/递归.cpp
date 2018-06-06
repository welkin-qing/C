#include<stdio.h>
#include<math.h>
/*求n的阶乘*/ 
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
	printf("输入数字n:\n");
	scanf("%d",&n);
	m=function(n);
	printf("%d",m);
	
}*/
/*求x的n次方*/
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
 	printf("请输入x,n\n");
 	scanf("%d,%d",&x,&n);
 	m=function(x,n);
 	printf("%d",m);
  } 
