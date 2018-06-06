#include<stdio.h>
#include<string.h>
main()
{
/*	char a[3][20];
	char (*p)[20]=a;
	int i,j;
	printf("ÊäÈë×Ö·ûÊı×é£º \n");
	for(i=0;i<3;i++)
	{
		gets(a[i]);
	}
		for(i=0;i<3;i++)
	{
		printf("%s\n",a[i]);
	}
	printf("\n%s\n",*a);
	printf("%s\n",*(a+1));
	printf("%c\n",**(a+1));
	printf("%c\n",*(*(a+1)+2));
	printf("%s\n",*p);
	printf("%s\n",*(p+1));*/
	

/*	char *name[]={
	                "abcd",
	                "fellow me",
                   	"basic"};
    char **p=name;
	printf("%s\n",*p);
	printf("%s\n",*(p+1));
	printf("%s\n",*name);
	printf("%c\n",**(p+1));
	printf("%c\n",**(name+1));    */
	
/*	int b[3][3]={1,2,3,4,5,6,7,8,9};
	int (*p)[3]=b; 
	printf("%d\n",b[2][2]);
	printf("%d\n",*(*(b+2)+2));
	printf("%d\n",*(*(p+2)+2));*/
	
	char p[100]="123456789";
	printf("letter:\n");
	gets(p);
	printf("%s\n",p+strlen(p)+1);
	          	
}
