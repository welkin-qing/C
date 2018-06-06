#include<stdio.h>
int function(int a[])
{
	int i,j,t;
	double sum=0;
	double ever=1;
	for(i=0;i<9;i++)
	for(j=i;j<10;j++)
	{
		if(a[i]>a[j])
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	for(i=1;i<9;i++)
	{
		sum+=a[i];
	}
	ever=sum/8.0;
	return(ever);
 } 
 /*
void fac(int a[])
{
	int i,j;
	for(i=0;i<10;i++)
	for(j=0;j<10;j++)
	{
		scanf("%d",&a[i]);
	}
}*/
void store(double a[])
{
	int i,j,t;
	for(i=1;i<2;i++)
	for(j=i;j<3;j++)
	{
		if(a[i]>a[j])
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
}
 
 main()
 {
 	int a[10]={98,97,65,67,64,62,63,68,69,97};
 	int b[10]={98,97,95,96,89,87,85,86,84,32};
	int c[10]={98,99,100,56,52,68,84,86,87,89};
 	double d[3]={0},t;
 	double fun[3]={0};
 	int i,j;
	d[0]=function(a);
    d[1]=function(b);
 	d[2]=function(c);
 	fun[0]=d[0];
 	fun[1]=d[1];
 	fun[2]=d[2];
 	store(d);
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    {
    	if(d[i]==fun[j]) printf("成绩是%f的是第%d位同学\n",d[i],j+1);
	}
}
 
