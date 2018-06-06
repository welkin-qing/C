#include <stdio.h>
#define N 20
void main()
{
	int i,j,n,q,count=1;
	int a[N][N]={0};
	printf("请输入该矩阵的行数或列数(1~20)：\n");
	scanf("%d",&n);
	if(n>N)//螺旋数组的实现
		printf("输入错误!\n");
	else
	{
		for(q=0;q<=n/2;q++)//通过循环的圈数控制
		{
			for(i=q;i<=n-q-1;i++)//对上方的横向输出控制
                a[q][i]=count++;
			for(i=q+1;i<=n-q-1;i++)//对右方纵向输出控制
                a[i][n-q-1]=count++;
			for(i=n-q-2;i>=q;i--)//对下方横向输出控制,减去前面的行数q+1行
                a[n-q-1][i]=count++;
			for(i=n-q-2;i>=q+1;i--)//对左方纵向输出控制,减去前面的行数q+1行
                a[i][q]=count++;
		}
		//输出螺旋数组
		printf("输出的矩阵如下：\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
                printf("%4d",a[i][j]);
			printf("\n");
		}
	}
}