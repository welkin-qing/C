#include<stdio.h>
#define N 20
struct student{
	char name[20];
	int english;
	int math;
	int com;
}stu[N];
main()
{
	FILE *fp;
	int i,n,j;
	int m;
	double ever;
	fp=fopen("store.txt","r");
	if(fp==NULL)
	{
		printf("不能打开此文件!\n");
		return 0;
	}
	printf("该班的数据为:\n");
	i=0;
	while(fscanf(fp,"%s %d %d %d",stu[i].name,&stu[i].english,&stu[i].math,&stu[i].com)!=EOF)
	{
      	printf("%s ,%d ,%d ,%d\n",stu[i].name,stu[i].english,stu[i].math,stu[i].com);
		//printf("%s,",stu[i].name);
		/*printf("%d",stu[i].english);
		printf("%d",stu[i].math);
		printf("%d",stu[i].com);*/
		i++;
	}
	fclose(fp);
	m=0;
	for(j=0;j<i;j++)
	{
	    ever=(stu[j].english+stu[j].math+stu[j].com)/3.0;
	    printf("%f\n",ever);
	    if(ever>=90.0)    m++;
	}
	printf("大于90分的有%d个人\n",m);
}
