#include<stdio.h>
#include<string.h>
main()
{
	char a[3][80]={0};
	int n=0,m=0,num=0,space=0,qita=0;
	int i,j; 
	int sum=0,length,count;
	for(i=0;i<3;i++)
	{
	
		gets(a[i]);
		
	}
		for(i=0;i<3;i++)
	{

		printf("%s\n",a[i]);
		sum+=strlen(a[i]);
		
	}
	for(i=0;i<3;i++)
	{
	  length = strlen(a[i]);  
    for (int i=0;i<length;i++)  
    {  
        if(a[i]!=' ')  
        {  
            count++;  
            while(a[i]!=' '&&a[i]!='\0')  
            {  
                i++;  
            }  
        }  
    }  
}
    printf("%d\n",count);  

	printf("%d",sum);
	for(i=0;i<3;i++)
	for(j=0;j<80;j++) 
	{
	
	if(a[i][j]<='9'&&a[i][j]>='0')   num++;
	else if(a[i][j]<='z'&&a[i][j]>='a')     m++;
	else if(a[i][j]<='Z'&&a[i][j]>='A')    n++;
	else if(a[i][j]==' ')            space++;
	else qita++;
    }
    printf("num=%d\n,m=%d\n,n=%d\n,space=%d\n,qita=%d\n",num,m,n,space,qita);
    printf("%d",sum);
 } 
