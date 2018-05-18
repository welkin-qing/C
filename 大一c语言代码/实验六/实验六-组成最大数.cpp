#include<stdio.h>
int function(int b)
{
	int ge,shi,bai,qian;
	int a[4],i,j,t;
	ge=b%10;
	shi=b/10%10;
	bai=b/100%10;
	qian=b/1000;
	a[0]=ge;
	a[1]=shi;
	a[2]=bai;
    a[3]=qian;
    	for(i=0;i<3;i++)   
	{
		for(j=i+1;j<4;j++) 
		if(a[i]<a[j])
		{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		}
		
	}
    for(i=0;i<4;i++)
    printf("%d",a[i]);   /*因为没有返回值所以就在函数中输出*/
}
main()
{
	int s,m;
	printf("number");
	scanf("%d",&s);  /*若想在主函数中输出 则需要一个值和返回值的类型相同 且最后输出m的值即可*/
	m=function(s);
}
