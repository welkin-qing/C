/*�����������е�����Ԫ�ؾ���Ե�����һ�������һ�����ڶ����뵹���ڶ��������նԵ��Ľ�����*/
#include"stdio.h"
#define N 100
main()
{
	int i,t,a[N],b[N],n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		b[i]=a[n-i-1];
	for(i=0;i<n;i++)
		printf("%d\t",b[i]);
	printf("\n");
}
	
