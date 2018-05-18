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
	double ever;
	fp=fopen("store.txt","rw");
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
　const char * szwrite = " this is a text";
　　FILE *fp = fopen("test.txt", "a+");
　　if (fp==0)
    {
　　printf("can't open file\n");
　　return 0;
　　}
　　fseek(fp, 0,SEEK_END);
　　fwrite(szwrite, strlen(szwrite) * sizeof(char), 1, fp);
　　fclose(fp);
　　return 0;
　　}
	fclose(fp);
	
} 
