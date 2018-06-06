#ifndef wq
	#define wbt 1
	#include "wbt.cpp"
	#define wbt 1
#endif

int putGraph()
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
	i=putGraph();
	if(i==-1)  printf("Ê§°Ü£¡");
}
#endif
