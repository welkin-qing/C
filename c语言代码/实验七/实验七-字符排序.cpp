#include<stdio.h>
main()
{
	char s[100];
    int i,j,k,t,n;
	gets(s);
	puts(s);
    for(n=0;s[n];n++);
	for(i=0;i<n-1;i++)
	{
	k=i;
	for(j=i+1;j<n;j++)
	if(s[j]<s[k])
	k=j;
	t=s[i];
	s[i]=s[k];
	s[k]=t;
    }
	printf("%s\n",s);
}



/*类似于实验五的单词排序*/ 
