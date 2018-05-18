#ifndef wq
	#define wbt 1
	#include "wbt.cpp"
#endif
int p()
{
	int i;
	char s[100][500];
	FILE *fp;
	fp=fopen("tu.txt","rt");
	if(fp==NULL)
		return -1;
	for(i=0;i<35;i++)
	{
		fgets(s[i],500,fp);
	}
	for(i=0;i<35;i++)
	{
		printf("%s",s[i]);
	}
	return 1;
}
 
 
 
 
#ifndef wq
int main()
{
	int i;
	i=p();
	if(i==-1)  printf("Ê§°Ü£¡");
}
#endif
