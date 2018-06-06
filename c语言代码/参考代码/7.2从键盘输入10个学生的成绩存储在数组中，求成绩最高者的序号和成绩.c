/*从键盘输入10个学生的成绩存储在数组中，求成绩最高者的序号和成绩*/
#include"stdio.h"
#define N  10
main()
{
	int a[N];
	int i,min,max,b;
	printf("请输入十个学生的成绩：");
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
	printf("第%d个学生成绩max=%d\n",b,max);
}
	
