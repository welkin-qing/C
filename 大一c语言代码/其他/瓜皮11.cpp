#include<stdio.h>
#include<string.h>
int main(void)
{
	char a[7]={"lenovo"},b[7];
	int i;
	printf("���������룺\n");
	for(i=0;i<3;i++)
	{
		gets(b);
		if(strcmp(a,b)==0)
		{
			printf("������ȷ!\n");
			break;
		}
		else
			printf("�������!\n");
		while(i>=2)
		{
			printf("��ֹ����!");  break;
		}
	}
/*	if(i>=2&&strcmp)
		printf("��ֹ����\n");*/
	return 0;
}
