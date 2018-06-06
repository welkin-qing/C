#include<stdio.h>
main()
{
	char s[3][10];
	int i,j,n,k,t;
	printf("ÇëÊäÈë×Ö·û´®");
    for(i=0;i<3;i++)
	{
	
		gets(s[i]);
		
		
	}
	for(n=0;s[][n];n++);
	for(i=0;i<n-1;i++)
	{
	k=i;
	for(j=i+1;j<n;j++)
	if(s[][j]<s[][k])
	k=j;
	t=s[][i];
	s[][i]=s[][k];
	s[][k]=t;
    }
    puts(s);
 } 
