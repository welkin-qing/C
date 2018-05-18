#include<stdio.h>
#define N 100
int add(int n,int i);
main()
{
     int n,i,j,a[N];
	 scanf("%d",&n);
	 for(i=1;i<=n/2;i++)
	 {
         a[i]=add(n,i);
	 }
	 for(j=1;j<=n/2;)
	 {
		 if(a[j]!=n)
			 j++;
	 }
	 printf("NONE");
}
int add(int n,int i)
{
     int j,p=i,m=0,count=0;
	 for(;i<n;i++)
	 {
	      m=m+i;
          count++;
		  if(m>=n)
		    break;
	 }
	 if(m==n)
	    {
	        printf("%d=",m);
			for(j=1;j<count;j++)
			{
				printf("%d+",p);
				p++;
			}
			printf("%d",i);
			printf("\n");
			return m;
	 }
	 //else
		//return 0;
}
