/*�Ӽ�������10��ѧ���ĳɼ��洢�������У���ɼ�����ߵ���źͳɼ�*/
#include"stdio.h"
#define N  10
main()
{
	int a[N];
	int i,min,max,b;
	printf("������ʮ��ѧ���ĳɼ���");
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	min=max=a[0];
	for(i=1;i<N;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
			b=i+1;
		}
	}
	printf("��%d��ѧ���ɼ�max=%d\n",b,max);
}
	
