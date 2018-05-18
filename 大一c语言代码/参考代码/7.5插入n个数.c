/*在有序的数组中插入若干个数，使数列在插入过程中始终保持有序*/
#include <stdio.h>
#define N 10 
int a[N];
int main()
{
	int n,i,j,k;
	int x,y;
	y=N;
	printf("插入n个数:n=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个数",i+1);
		scanf("%d",&x);	/*数组元素的插入,从最后一个元素开始，往后移动*/
		for(j=0;j<y+1;j++)
		{
			if(x<a[j]||j==y)
			{
				for(k=y+1;k>j;k--)
					a[k]=a[k-1];
				a[j]=x;
				break;
			}
		}
		y++;
	}
	for(i=0;i<y;i++) printf("%d ",a[i]);
	return 0;
}

