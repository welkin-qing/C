#include <stdio.h>
#define N 20
void main()
{
	int i,j,n,q,count=1;
	int a[N][N]={0};
	printf("������þ��������������(1~20)��\n");
	scanf("%d",&n);
	if(n>N)//���������ʵ��
		printf("�������!\n");
	else
	{
		for(q=0;q<=n/2;q++)//ͨ��ѭ����Ȧ������
		{
			for(i=q;i<=n-q-1;i++)//���Ϸ��ĺ����������
                a[q][i]=count++;
			for(i=q+1;i<=n-q-1;i++)//���ҷ������������
                a[i][n-q-1]=count++;
			for(i=n-q-2;i>=q;i--)//���·������������,��ȥǰ�������q+1��
                a[n-q-1][i]=count++;
			for(i=n-q-2;i>=q+1;i--)//���������������,��ȥǰ�������q+1��
                a[i][q]=count++;
		}
		//�����������
		printf("����ľ������£�\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
                printf("%4d",a[i][j]);
			printf("\n");
		}
	}
}