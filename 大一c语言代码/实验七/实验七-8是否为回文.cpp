#include<stdio.h>
main()
{
    char a[100];
    int i=0,j=0;
    printf("Please input string:");
	gets(a);
	while(a[i]!='\0')
	i++;
	i--;
	for(;j<=i;i--,j++)
	{
	  if(a[i]!=a[j])
	  break;
	}
	if(j<=i)
	printf("%s 不是回文\n",a);
	else
	printf("%s 是回文\n",a);

} 
