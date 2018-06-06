#include<stdio.h>
main()
{
	int a[10]={56,78,67,89,98,67,57,45,95,87};
	int i,j,k,b;
		k=a[0];
	for(i=1;i<10;i++)
	{
	    
		if(a[i]>k)
		{
			k=a[i];
			b=i+1;
			
		}
	}
	printf("%d,µÚ%dÃû",k,b);
	
 } 
