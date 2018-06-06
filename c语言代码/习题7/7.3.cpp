#include<stdio.h>
#include<math.h>
main()
{
	double a[90],b[45];
	int i;
	for(i=0;i<90;i++)
	{
		a[i]=sin(i);
		 
	}
	for(i=0;i<45;i++)
	{
		b[i]=tan(i);
	}
	for(i=0;i<90;i++)  printf("%f\n",a[i]);
	for(i=0;i<45;i++)  printf("%d\n",b[i]);
	printf("%f",a[30]);
}
