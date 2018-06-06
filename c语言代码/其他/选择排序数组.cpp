#include<stdio.h>
main()
{

	int a[10];
	int i,j,t;
	for(i=0;i<10;i++)    /*输入成绩*/ 
	{
		printf("成绩是");
		scanf("%d",&a[i]);
	}
	/*从小到大进行排序*/ 
	for(i=0;i<9;i++)   /*刚开始是i[0]去比较并把小值存在i[0]然后随着i的值变大从i[i+1]后开始比较*/ 
	{
		for(j=i+1;j<10;j++)  /*让i的值去和j比较，j的值比i大 ,且从第i+1开始往后比较*/ 
		if(a[i]>a[j])   /*如果i+1后边的值小于i则调换*/ 
		{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		}
		
	}
	for(i=0;i<10;i++)
	printf("%d\n",a[i]);
 } 
 

