#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[7]={"lenovo"},b[7];
	int i;
	printf("ÇëÊäÈëÃÜÂë£º\n");
	for(i=0;i<3;i++)
	{
		gets(b);
		if(strcmp(a,b)==0)
		{
			printf("ÃÜÂëÕıÈ·!\n");
			break;
		}
		else
			printf("ÃÜÂë´íÎó!\n");
		while(i>=2)
		{
			printf("½ûÖ¹ÊäÈë!");  break;
		}
	}
/*	if(i>=2&&strcmp)
		printf("½ûÖ¹ÊäÈë\n");*/
	return 0;
}
