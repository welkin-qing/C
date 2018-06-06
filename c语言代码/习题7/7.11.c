#include<stdio.h>
main()
{
	char a[12][10]={"January",
	                "February",
					"March",
				    "April",
					"May",
					"June",
					"July",
					"August",
				    "September",
					"October",
					"November",
					"December"};
	int m,i;
    printf("«Î ‰»Î‘¬∑›");
    for(i=0;i<4;i++)
    {
    	scanf("%d",&m);
    	if(m<13&&m>0)   printf("%s\n",a[m-1]);
	    else printf("error\n"); 

	}
} 
