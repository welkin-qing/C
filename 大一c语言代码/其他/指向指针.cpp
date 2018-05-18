#include<stdio.h>
main()
{
	char  *name[]={"forgive",
	           "forget",
	           "remeber",
	           "togher"
	               };
	char **p=name;
	printf("%s\n",*p);
	printf("%c\n",**p);
	printf("%s\n",*(p+1));
	printf("%c",*(*(p+1)+2));
 } 

    
