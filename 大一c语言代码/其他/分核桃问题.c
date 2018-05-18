#include<stdio.h>
int min(int a,int b,int c,int i);
main()
{
    int a,b,c,n;
    scanf("%d%d%d",&a,&b,&c);
	n=(a>b)?  a:b;
	n=(n>c)?  n:c;
	n=min(a,b,c,n);
	printf("%d\n",n);
}
int min(int a,int b,int c,int i)
{
	  int m=i;
	while(!(m%a==0&&m%b==0&&m%c==0))
		m+=i;
	return m;

}