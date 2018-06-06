/*将整形数组中的所有元素镜像对调，第一个与最后一个，第二个与倒数第二个，按照对调的结果输出*/
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
	
