#include<stdio.h>
#include<string.h> 
#define N 20
struct student{
	char name[20];
	int english;
	int math;
	int com;
}stu[N];
struct studnet1{
    char name[20];
	int english;
	int math;
	int com;
	double ever;	
}stu1[N];
main()
{
	FILE *fp,*fp1; 
	int i,n,j;
	double ever[N];
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
	//fclose(fp);
	for(j=0;j<i;j++)     
	{
	    ever[j]=(stu[j].english+stu[j].math+stu[j].com)/3.0;
	    printf("%f\n",ever[j]);
	}
	//fclose(fp);
	fp1=fopen("stu-store.txt","w");
	if(fp1==NULL)
	{
		printf("不能打开此文件!\n");
		return 0;
	}
/*	for(i=0;i<n;i++)
	{
		strcpy(stu1[i].name,stu[i].name);
		stu1[i].english=stu[i].english;
		stu1[i].math=stu[i].math;
		stu1[i].com=stu[i].com;
		stu1[i].ever=ever[i];
		printf("%10s",stu1[i].name);
		printf("%5d",stu1[i].english);
		printf("%5d",stu1[i].math);
		printf("%5d",stu1[i].com);
		printf("%5f\n",stu1[i].ever);
		fprintf(fp1,"%s %d %d %d %d\n",stu1[i].name,&stu1[i].english,&stu1[i].math,&stu1[i].com,&stu1[i].ever); 
	    /*fprintf("%d",&stu1[i].english);  //stu1[i].english=stu[i].english;
	    fprintf("%d",&stu1[i].math); //
	    fprintf("%d",&stu1[i].com); //stu1[i].com=stu[i].com;
	    fprintf("%d",&stu1[i].ever); //stu1[i].ever=ever[i];
	}   */
	fclose(fp);
	fclose(fp1);
	return 0;
}
