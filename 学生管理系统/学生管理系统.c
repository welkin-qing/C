/*学生管理系统*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define N  20



struct student *creadlink();
struct student *gradeinput();
struct student *graderefer();
struct student *showallgrades();
struct student *result(struct student *);
struct student *graderemove(struct student *);
struct student *grademodification(struct student *);


void menu();
void quit();
void print();
void addto();
void login();
void landing();
void password();
void save(struct student *);
void  sort(struct student *);
void destroy(struct student *);
void chooce1(struct student *);
void chooce2(struct student *);
void chooce3(struct student *);
void gradesum(struct student *);


struct date
{
    int year;//年份
    int month;//月份
    int day;//日期
};

struct student 
{
    char  number[10];//学号
    char name[30];//姓名
    char sex[3];//性别
    char subject[N][20];//科目的名称
    double score[N];//成绩
    double average[N];//平均成绩
    double max[N];//最高成绩
    double min[N];//最低成绩
    char profession[20];//专业
    struct date birthday;//引用struct date e类型
    struct student  *next;
};



char key[N];
int k=0;
int point=0;
int iCount;//表示链表长度
char filename[40];//文件名



struct student *gradeinput()
{
    int i;
    int j=1;
    struct student *pHead=NULL;
    struct student *pEnd,*pNew;
    struct student *q;
    q=(struct student *)malloc(sizeof(struct student));
    printf("\t=============================================================\n");
    printf("\t                    *****添加学生信息*****             \n");
    printf("\t=============================================================\n");    
    pEnd= pNew =(struct student *)malloc(sizeof(struct student));
    printf("\t请输入学生的姓名：");
    fflush(stdin);
    scanf("%s",pNew->name);
    printf("\t请输入学生的学号：");
    fflush(stdin);
    scanf("%s",pNew->number);
    printf("\t请输入学生的性别：");
    fflush(stdin);  
    scanf("%s",pNew->sex);
    printf("\t请输入学生的出生年月日：");
    fflush(stdin);
    scanf("%d %d %d",&pNew->birthday.year,&pNew->birthday.month,&pNew->birthday.day);
    printf("\t请输入你的专业：");
    fflush(stdin);
    scanf("%s",pNew->profession);
    printf("\t请输入3门课程的信息：\n");
    for(i=0;i<3;i++)
    {
        printf("\t请输入科目的名称：");
        fflush(stdin);
        scanf("%s",pNew->subject[i]);
    }
    for(i=0;i<3;i++)
    {
        fflush(stdin);
        printf("\t请输入第一个学生%s科目的成绩：",pNew->subject[i]);
        scanf("%lf",&pNew->score[i]);
    }
    iCount++;
    fflush(stdin);
    while (j==1)
    {
        printf("\t=============================================================\n");
        printf("\t请选择以下选项：\n");
        printf("\t0、退出录入成绩\n");
        printf("\t1、继续录入成绩\n");
        printf("\t=============================================================\n");
        printf("\t");
        fflush(stdin);
        scanf("%d",&j);
        if(j!=1&&j!=0)
            while(j!=1&&j!=0)
            {
                printf("\t输入错误，请重新输入！\n");
                printf("\t=============================================================\n");
                printf("\t请选择以下选项：\n");
                printf("\t0、退出录入成绩\n");
                printf("\t1、继续录入成绩\n");
                printf("\t=============================================================\n");
                printf("\t");
                fflush(stdin);
                scanf("%d",&j);
            }
            if(j==0)
                system("cls");
            if(iCount==1)
            {
                pNew->next=NULL;
                pEnd=pNew;
                pHead=pNew;
            }
            else 
            {
                pNew->next=NULL;
                pEnd->next=pNew;
                pEnd=pNew;
            }
            fflush(stdin);
            if(j==1)
            {
                iCount++;
                pNew=(struct student *)malloc(sizeof(struct student));
                printf("\t请输入第%d个学生的姓名:",iCount);
                scanf("%s",pNew->name);
                printf("\t请输入第%d个学生的学号:",iCount);
                scanf("%s",pNew->number);
                printf("\t请输入第%d学生的性别：",iCount);
                scanf("%s",&pNew->sex);
                printf("\t请输入第%d学生的出生年月日：",iCount);
                fflush(stdin);
                scanf("%d%d%d",&pNew->birthday.year,&pNew->birthday.month,&pNew->birthday.day);
                printf("\t请输入你的专业：");
				fflush(stdin);
				scanf("%s",pNew->profession);
				for(i=0;i<3;i++)
                {
                    printf("\t请输入%s科目的成绩：",pHead->subject[i]);
                    fflush(stdin);
                    scanf("%lf",&pNew->score[i]);
                }
            	
            }
    }
    q->next=pHead;
    save(q);
    return pHead;
}

void save(struct student *pHead)
{
    struct student *p;
    FILE *fp;
    printf("\t请输入要保存的文件名:\n");
    printf("\t");
    fflush(stdin);
    gets(filename);
    if((fp=fopen(filename,"w+"))==NULL)
    {
        printf("\t写入文件出错，按任意键返回！");
        getchar();
        exit(0);
    }
    fp=fopen(filename,"w+");
    for(p=pHead->next;p!=NULL;p=p->next)
        fprintf(fp,"%s %s %s %s %d %d %d %.2lf %.2lf %.2lf ",p->profession,p->name,p->number,p->sex,p->birthday.year,p->birthday.month,p->birthday.day,p->score[0],p->score[1],p->score[2]);
	printf("\n");
    printf("\t写入文件成功，按任意键返回！");
    system("pause");
    system("cls");
    fclose(fp);
    destroy(pHead);
}

void destroy(struct student *pHead)
{
    struct student *pNew;
    do
    {
        pNew=pHead->next;
        pHead->next=pNew->next;
        if(pNew!=NULL)
            free(pNew);
    }while(pHead->next!=NULL);
        free(pHead);
}



void print(struct student *pHead)
{
    struct student *pTemp;
    int iIndex=1;
	int j=0;
    double average=0;
	pTemp=pHead;
	while(pTemp!=NULL)
	{
		if(j==0)
		{
			printf("\t专业\t\t姓名\t学号\t\t性别\t出 生 年 月\t\t科目1\t科目2\t科目3\n");
			j++;
		}
		printf("\t%s\t%s\t%s\t%s\t%d-%d-%d\t\t%.2lf\t%.2lf\t%.2lf\n",pTemp->profession,pTemp->name,pTemp->number,pTemp->sex,pTemp->birthday.year,pTemp->birthday.month,pTemp->birthday.day,pTemp->score[0],pTemp->score[1],pTemp->score[2]);
    pTemp=pTemp->next;
	}
	printf("\t按任意键退出查询系统\n");
    printf("\t");
    system("pause");
    system("cls");  
}



main()
{
    struct student *pHead=NULL;//定义头结点
    password();//登陆密码模块
}


void password()
{
	int i;
	do
	{
	printf("\t-------------------------------------------------------------\n");
	printf("\t                    欢迎使用用户注册登录界面\n");
	printf("\t-------------------------------------------------------------\n");
	printf("\t                       1-用户登录\n");
	printf("\t                       2-用户注册\n");
    printf("\t                       0-用户退出\n");
	printf("\t                       请输入你的选择:");
	scanf("%d",&i);
	if(i==0)
	{
		system("cls");
		quit();
	}
	else if(i==1)
	{
		system("cls");
		landing();
	}
	else if(i==2)
	{
		system("cls");
		login();
	}
	else
	{
		printf("\t                     输入错误!请重新输入!\n");
		printf("\t                     ");
		system("pause");
		system("cls");
	}
	}while(i!=0);
}

void landing()//登录
{
	FILE *fp;
	int i,j=0,a=100;
	char user[40];
	char word[40];
	char user1[40];
	char word1[40];
	printf("\t-------------------------------------------------------------\n");
	printf("\t                    用户登录界面\n");
	printf("\t-------------------------------------------------------------\n");
	printf("\t                    用户名:");
	fflush(stdin);
	gets(user);
	printf("\t                    密码：");
	fflush(stdin);
	while(j<=40)
	{
		fflush(stdin);
		word[j]=getch();
		fflush(stdin);
		putchar('*');
		fflush(stdin);
		if(word[j]==13)
			break;
		j++;
	}
	word[j]=0;
	printf("\n");
	if((fp=fopen("user.txt","r+"))==NULL)
	{
		printf("\t写入文件出错，按任意键返回!");
		getchar();
		exit(0);
	}
	fp=fopen("user.txt","r+");
	fscanf(fp,"%s %s ",user1,word1);
	if(strcmp(user,user1)==0&&strcmp(word,word1)==0)
	{
		printf("\t                    请稍等\n                            ");
		for(i=0;i<2;i++)
		{
			printf("%c ",2);
			Sleep(a);
			a+=50;
			printf("%c ",3);
			Sleep(a);
			a+=50;
			printf("%c ",4);
			Sleep(a);
			a+=50;
			printf("%c ",5);
			Sleep(a);
			a+=50;
			printf("%c ",6);
			Sleep(a);
			a+=50;
		}
		printf("\n");
		printf("\t                    登陆成功!");
		k=1;
		if(k==1)
		{
			system("cls");
			menu();//主菜单
		}
	}
	else
	{
		printf("\t                    请稍等\n                            ");
		for(i=0;i<2;i++)
		{
			printf("%c ",2);
			Sleep(a);
			a+=50;
			printf("%c ",3);
			Sleep(a);
			a+=50;
			printf("%c ",4);
			Sleep(a);
			a+=50;
			printf("%c ",5);
			Sleep(a);
			a+=50;
			printf("%c ",6);
			Sleep(a);
			a+=50;
		}
		printf("\n");
		printf("\t                       信息错误!登录失败!\n");
		printf("\t                       ");
		system("pause");
		system("cls");
	}
}
void login()//注册
{
	FILE *fp;
	char user[40]={'0'};
	char word[40]={'0'};
	char word1[40]={'0'};
	int i=0,j;
	int a=100;
	printf("\t-------------------------------------------------------------\n");
	printf("\t                    用户注册界面\n");
	printf("\t-------------------------------------------------------------\n");
	printf("\t                    用户名:");
	fflush(stdin);
	gets(user);
	printf("\t                    密码：");
	fflush(stdin);
	while(i<=40)
	{
		fflush(stdin);
		word[i]=getch();
		fflush(stdin);
		putchar('*');
		fflush(stdin);
		if(word[i]==13)
			break;
		i++;
	}
	printf("\n");
	printf("\t                    确认密码：");
	fflush(stdin);
	i=0;
	while(i<=40)
	{
		fflush(stdin);
		word1[i]=getch();
		fflush(stdin);
		putchar('*');
		fflush(stdin);
		if(word1[i]==13)
			break;
		i++;
	}
	printf("\n");
	i=strlen(user);
	j=strlen(word);
	if(i>20)
		printf("                                    \t请输入用户名在1~20位之内!\n");
	if(j>20)
		printf("                  \t请输入密码在1~20位之内!\n");
	else
		printf("\t                    请稍等\n                            ");
	for(i=0;i<8;i++)  
	{	
		printf("--> ");
		Sleep(a);
		a+=50;
	}
	if(strcmp(word,word1)==0&&i>0&&j>0)
	{
		printf("\n\t                    注册成功!");
		if((fp=fopen("user.txt","w+"))==NULL)
		{
			printf("\t写入文件出错，按任意键返回！");
			getchar();
			exit(0);
		}
		fp=fopen("user.txt","a+");
		fprintf(fp,"%s %s",user,word);
		fclose(fp);
		system("pause");
		system("cls");
	}
	else
	{
		printf("\n\t                    密码错误!请重新输入!\n");
		printf("\t                     ");
		system("pause");
		system("cls");
	}
}









void menu()
{
    struct student *p=NULL;
	FILE *fp;
    char choice;
	char k[10];
	int i,j=0;
    do
    {
        printf("\n");
        printf("\t-------------------------------------------------------------\n");
        printf("\t                  欢迎使用学生管理系统\n");
        printf("\t-------------------------------------------------------------\n");
        printf("\t                     1-成绩录入模块\n");
        printf("\t                     --------------\n");
        printf("\t                     2-成绩查询模块\n");
        printf("\t                     --------------\n");
        printf("\t                     3-成绩修改模块\n");
        printf("\t                     --------------\n");
        printf("\t                     4-成绩删除模块\n");
        printf("\t                     --------------\n");
        printf("\t                     5-显示所有成绩\n");
        printf("\t                     --------------\n");
        printf("\t                     6-成绩总个数\n");
        printf("\t                     ------------\n");
        printf("\t                     7-成绩统计模块\n");
		printf("\t                     --------------\n");
        printf("\t                     8-追加读写数据\n");
		printf("\t                     --------------\n");
        printf("\t                     9-退出程序\n");
        printf("\t-------------------------------------------------------------\n");
        printf("\t请选择需要的功能(1~9)：");
        fflush(stdin);
        scanf("%s",&k);
		choice=k[0];
		j=strlen(k);
		if(j>1)
		{
			system("cls");
			printf("\t                   输入错误,请重新输入!");
		}
		else
		{
			system("cls");
			switch(choice)
			{
            case '1':gradeinput();break;
            case '2':do
				   {
					   printf("\t=============================================================\n");
					   printf("\t                    *****成绩查询界面*****             \n");
					   printf("\t=============================================================\n"); 
					   printf("\t请选择查询的方式：\n");
					   printf("\t0-直接输出成绩\n");
					   printf("\t1-按姓名进行查询\n");
					   printf("\t2-按学号进行查询\n");
					   printf("\t3-按专业进行查询\n");
					   printf("\t请输入你的选择：");
					   scanf("%d",&i);
					   p=graderefer();
					   if(i==0)
					   {
						   print(p->next);
						   system("cls");
						   break;
					   }
					   else if(i==1)
					   {
						   chooce1(p);break;
					   }
					   else if(i==2)
					   {
						   chooce2(p);break;
					   }
					   else if(i==3)
					   {
						   chooce3(p);break;
					   }
					   else
					   {
						   printf("\t输入错误!从重新输入!\n");
						   printf("\t");
						   system("pause");
						   system("cls");
					   }
				   }while(i!=0&&i!=1&&i!=2&&i!=3);
				   break;
            case '3':p=graderefer();
				grademodification(p);
				print(p->next);
				if((fp=fopen("grademodification.txt","w+"))==NULL)
				{
					printf("\t写入文件出错，按任意键返回！");
					getchar();
					exit(0);
				}
				fp=fopen("grademodification.txt","w+");
				p=p->next;
				for(;p!=NULL;p=p->next)
					fprintf(fp,"%s %s %s %s %d %d %d %.2lf %.2lf %.2lf ",p->profession,p->name,p->number,p->sex,p->birthday.year,p->birthday.month,p->birthday.day,p->score[0],p->score[1],p->score[2]);
				printf("\n");
				printf("\t写入文件成功，按任意键返回！");
				system("pause");
				system("cls");
				fclose(fp);
				break;
            case '4':p=graderefer();
				graderemove(p);
				if(point!=1)
				{
					print(p->next);
					if((fp=fopen("graderemove.txt","w+"))==NULL)
					{
						printf("\t写入文件出错，按任意键返回！");
						getchar();
						exit(0);
					}
					fp=fopen("graderemove.txt","w+");
					p=p->next;
					for(;p!=NULL;p=p->next)
						fprintf(fp,"%s %s %s %s %d %d %d %.2lf %.2lf %.2lf ",p->profession,p->name,p->number,p->sex,p->birthday.year,p->birthday.month,p->birthday.day,p->score[0],p->score[1],p->score[2]);
					printf("\n");
					printf("\t写入文件成功，按任意键返回！");
					system("pause");
					system("cls");
					fclose(fp);
				}
				point=0;
				break;
            case '5':showallgrades();break;
            case '6':p=graderefer();
				gradesum(p);break;
			case '7':p=graderefer();
				result(p);break;
			case '8':addto();break;
            case '9':quit();break;
            default:printf("\t                   输入错误,请重新输入!");menu();
			}
		}
    }while(choice!='9');
}

void addto()
{
	int i;
    int j=1;
    struct student *pHead=NULL;
    struct student *pEnd,*pNew;
    struct student *q;
	struct student *p;
    FILE *fp;
    q=(struct student *)malloc(sizeof(struct student));
    printf("\t=============================================================\n");
    printf("\t                    *****添加学生信息*****             \n");
    printf("\t=============================================================\n");    
    pEnd= pNew =(struct student *)malloc(sizeof(struct student));
    printf("\t请输入学生的姓名：");
    fflush(stdin);
    scanf("%s",pNew->name);
    printf("\t请输入学生的学号：");
    fflush(stdin);
    scanf("%s",pNew->number);
    printf("\t请输入学生的性别：");
    fflush(stdin);  
    scanf("%s",pNew->sex);
    printf("\t请输入学生的出生年月日：");
    fflush(stdin);
    scanf("%d %d %d",&pNew->birthday.year,&pNew->birthday.month,&pNew->birthday.day);
    printf("\t请输入你的专业：");
    fflush(stdin);
    scanf("%s",pNew->profession);
    printf("\t请输入3门课程的信息：\n");
    for(i=0;i<3;i++)
    {
        printf("\t请输入科目的名称：");
        fflush(stdin);
        scanf("%s",pNew->subject[i]);
    }
    for(i=0;i<3;i++)
    {
        fflush(stdin);
        printf("\t请输入第一个学生%s科目的成绩：",pNew->subject[i]);
        scanf("%lf",&pNew->score[i]);
    }
    iCount++;
    fflush(stdin);
	pHead=pNew;
	pHead->next=NULL;
    while (j==1)
    {
        printf("\t=============================================================\n");
        printf("\t请选择以下选项：\n");
        printf("\t0、退出录入成绩\n");
        printf("\t1、继续录入成绩\n");
        printf("\t=============================================================\n");
        printf("\t");
        fflush(stdin);
        scanf("%d",&j);
        if(j!=1&&j!=0)
            while(j!=1&&j!=0)
            {
                printf("\t输入错误，请重新输入！\n");
                printf("\t=============================================================\n");
                printf("\t请选择以下选项：\n");
                printf("\t0、退出录入成绩\n");
                printf("\t1、继续录入成绩\n");
                printf("\t=============================================================\n");
                printf("\t");
                fflush(stdin);
                scanf("%d",&j);
            }
            if(j==0)
                system("cls");
            if(iCount==1)
            {
                pNew->next=NULL;
                pEnd=pNew;
                pHead=pNew;
            }
            else 
            {
                pNew->next=NULL;
                pEnd->next=pNew;
                pEnd=pNew;
            }
            fflush(stdin);
            if(j==1)
            {
                iCount++;
                pNew=(struct student *)malloc(sizeof(struct student));
                printf("\t请输入第%d个学生的姓名:",iCount);
                scanf("%s",pNew->name);
                printf("\t请输入第%d个学生的学号:",iCount);
                scanf("%s",pNew->number);
                printf("\t请输入第%d学生的性别：",iCount);
                scanf("%s",&pNew->sex);
                printf("\t请输入第%d学生的出生年月日：",iCount);
                fflush(stdin);
                scanf("%d%d%d",&pNew->birthday.year,&pNew->birthday.month,&pNew->birthday.day);
                printf("\t请输入你的专业：");
				fflush(stdin);
				scanf("%s",pNew->profession);
				for(i=0;i<3;i++)
                {
                    printf("\t请输入%s科目的成绩：",pHead->subject[i]);
                    fflush(stdin);
                    scanf("%lf",&pNew->score[i]);
                }
				
            }
    }
    q->next=pHead;
    printf("\t请输入要保存的文件名:\n");
    printf("\t");
    fflush(stdin);
    gets(filename);
    if((fp=fopen(filename,"a+"))==NULL)
    {
        printf("\t写入文件出错，按任意键返回！");
        getchar();
        exit(0);
    }
    fp=fopen(filename,"a+");
    for(p=q->next;p!=NULL;p=p->next)
        fprintf(fp,"%s %s %s %s %d %d %d %.2lf %.2lf %.2lf ",p->profession,p->name,p->number,p->sex,p->birthday.year,p->birthday.month,p->birthday.day,p->score[0],p->score[1],p->score[2]);
	printf("\n");
    printf("\t写入文件成功，按任意键返回！");
    system("pause");
    system("cls");
    fclose(fp);
}

struct student *result(struct student *pHead)
{
	int i,j=0,k=0;
	int cn[3][11]={0};
	int m,n;
	double sum[3]={0};
	struct student *p=pHead,*q;
	printf("\t-------------------------------------------------------------\n");
	printf("\t               成绩统计模块\n");
	printf("\t-------------------------------------------------------------\n");
	q=p->next;
	if(k==0)
	{
		printf("\t       平均分\t最高分\t最低分\n");
		k++;
	}
	for(;p->next!=NULL;p=p->next)
	{
		p->next->average[j]=0;
		p->next->max[j]=p->next->score[0];
		p->next->min[j]=p->next->score[0];
		for(i=0;i<3;i++)
		{
		(p->next->average[j])+=p->next->score[i];
		if(p->next->max[j]<p->next->score[i])
			p->next->max[j]=p->next->score[i];
		if(p->next->min[j]>p->next->score[i])
			p->next->min[j]=p->next->score[i];
		}
		p->next->average[j]=p->next->average[j]/3;
		printf("\t%s\t%.2lf\t",p->next->name,p->next->average[j]);
		printf("%.2lf\t",p->next->max[j]);
		printf("%.2lf\n",p->next->min[j]);
		j++;
	}
    for(i=0;i<3;i++)
	{
		for(p=pHead;p->next!=NULL;p=p->next)
		{
			m=p->next->score[i]/10;
			cn[i][m]++;
		}
	}
	for(i=0;i<3;i++)
	{
		for(n=0;n<=5;n++)
		{
			sum[i]+=cn[i][n];
		}
	}
	printf("\t\t0-19,10-19,20-29,30-39,40-49,50-59,60-69,70-79,80-89,90-99,100\n");
	for(n=0;n<3;n++)
	{
		for(i=0;i<11;i++)
		{
			if(i%11==0)
			{
				printf("\t科目%d",n+1);
				printf("\t");
			}
			printf("%-6d",cn[n][i]);
		}
		printf("\n\t\t及格率：%.2f%%\n",((j-sum[n])/j*100));
	}
	printf("\t");
	system("pause");
	system("cls");
	return pHead;
}


void chooce1(struct student *pHead)//姓名查询
{
	int j=0;
	char b[20];
	struct student *pNew=pHead;
	printf("\t请输入需要查询的姓名:");
	fflush(stdin);
	gets(b);
	for(;pNew!=NULL;pNew=pNew->next)
	{
		if(strcmp(pNew->name,b)==0)
		{
			if(j==0)
            {
                printf("\t\t专业\t姓名\t学号\t\t性别\t出 生 年 月\t\t科目1\t科目2\t科目3\n");
                j++;
            }
            printf("\t%s\t%s\t%s\t%s\t%d-%d-%d\t\t%.2lf\t%.2lf\t%.2lf\n",pNew->profession,pNew->name,pNew->number,pNew->sex,pNew->birthday.year,pNew->birthday.month,pNew->birthday.day,pNew->score[0],pNew->score[1],pNew->score[2]);
		}
	}
	printf("\t");
	system("pause");
	system("cls");
}
void chooce2(struct student *pHead)
{
	int j=0;
	char b[20];
	struct student *pNew=pHead;
	printf("\t请输入需要查询的学号:");
	fflush(stdin);
	gets(b);
	for(;pNew!=NULL;pNew=pNew->next)
	{
		if(strcmp(pNew->number,b)==0)
		{
			if(j==0)
            {
                printf("\t专业\t\t姓名\t学号\t\t性别\t出 生 年 月\t\t科目1\t科目2\t科目3\n");
                j++;
            }
            printf("\t%s\t%s\t%s\t%s\t%d-%d-%d\t\t%.2lf\t%.2lf\t%.2lf\n",pNew->profession,pNew->name,pNew->number,pNew->sex,pNew->birthday.year,pNew->birthday.month,pNew->birthday.day,pNew->score[0],pNew->score[1],pNew->score[2]);
		}
	}
	printf("\t");
	system("pause");
	system("cls");
}
void chooce3(struct student *pHead)
{
	int j=0;
	char b[20];
	struct student *pNew=pHead;
	printf("\t请输入需要查询的专业:");
	fflush(stdin);
	gets(b);
	for(;pNew!=NULL;pNew=pNew->next)
	{
		if(strcmp(pNew->profession,b)==0)
		{
			if(j==0)
            {
                printf("\t专业\t\t姓名\t学号\t\t性别\t出 生 年 月\t\t科目1\t科目2\t科目3\n");
                j++;
            }
            printf("\t%s\t%s\t%s\t%s\t%d-%d-%d\t\t%.2lf\t%.2lf\t%.2lf\n",pNew->profession,pNew->name,pNew->number,pNew->sex,pNew->birthday.year,pNew->birthday.month,pNew->birthday.day,pNew->score[0],pNew->score[1],pNew->score[2]);
		}
	}
	printf("\t");
	system("pause");
	system("cls");
}

struct student *creadlink()
{
    struct student *pHead;
    pHead=(struct student *)malloc(sizeof(struct student));
    pHead->next=NULL;
    return(pHead);
}

struct student *graderefer()
{
    FILE *fp;
    int j=0;
    struct student *pNew,*pHead,*pEnd;
    if((fp=fopen("1.txt","r"))==NULL)
    {
        printf("\t写入文件出错，按任意键返回！");
        getchar();
        exit(0);
    }
    else
    {
        while(!fscanf(fp,"姓名:%s\t",pEnd->name))
        {
            pNew=(struct student *)malloc(sizeof(struct student));
			pNew->next=NULL;
            fscanf(fp,"%s %s %s %s %d %d %d %lf %lf %lf ",pNew->profession,pNew->name,pNew->number,pNew->sex,&pNew->birthday.year,&pNew->birthday.month,&pNew->birthday.day,&pNew->score[0],&pNew->score[1],&pNew->score[2]);
			if(j==0)
			{
				pHead=pEnd=pNew;
				j++;
			}
			else
				pEnd=pEnd->next=pNew;
		}
    }
	pNew=(struct student *)malloc(sizeof(struct student));
	pNew->next=pHead;
    fclose(fp);
	return pNew;
}
struct student *grademodification(struct student *pHead)
{
	struct student *p,*q=pHead;
	char a[20];
	int m=0,n=0,t=0,x;
	int i,j,k=0;
	int b=0,c=0;
	printf("\t=============================================================\n");
	printf("\t                    *****信息修改界面*****             \n");
	printf("\t=============================================================\n"); 
	printf("\t请输入你需要查找的信息：");
	fflush(stdin);
	gets(a);
	for(p=pHead->next;p!=NULL;p=p->next)
	{
		if(strcmp(p->profession,a)==0)
		{
			printf("\t0-专业信息为：\n");
			if(t==0)
			{
				printf("\t专业\t\t姓名\t学号\t\t性别\t出 生 年 月\t\t科目1\t科目2\t科目3\n");
				t++;
			}
			printf("\t%s\t%s\t%s\t%s\t%d-%d-%d\t\t%.2lf\t%.2lf\t%.2lf\n",p->profession,p->name,p->number,p->sex,p->birthday.year,p->birthday.month,p->birthday.day,p->score[0],p->score[1],p->score[2]);
			k++;
		}
		if(strcmp(p->name,a)==0)
		{
			printf("\t1-姓名信息为：\n");
			if(m==0)
			{
				printf("\t专业\t\t姓名\t学号\t\t性别\t出 生 年 月\t\t科目1\t科目2\t科目3\n");
				m++;
			}
			printf("\t%s\t%s\t%s\t%s\t%d-%d-%d\t\t%.2lf\t%.2lf\t%.2lf\n",p->profession,p->name,p->number,p->sex,p->birthday.year,p->birthday.month,p->birthday.day,p->score[0],p->score[1],p->score[2]);
		    b++;
		}
		if(strcmp(p->number,a)==0)
		{
			printf("\t2-学号信息为：\n");
			if(n==0)
			{
				printf("\t专业\t\t姓名\t学号\t\t性别\t出 生 年 月\t\t科目1\t科目2\t科目3\n");
				n++;
			}
			printf("\t%s\t%s\t%s\t%s\t%d-%d-%d\t\t%.2lf\t%.2lf\t%.2lf\n",p->profession,p->name,p->number,p->sex,p->birthday.year,p->birthday.month,p->birthday.day,p->score[0],p->score[1],p->score[2]);
		    c++;
		}
	}
	printf("\t请选择需要修改的信息：\n");
	printf("\t修改的信息类别为：");
	scanf("%d",&i);
	printf("\t请选择是否修改该学生全部信息：\n");
	printf("\t0-修改该学生全部信息：\n");
	printf("\t1-修改该学生该项信息：\n");
	printf("\t请输入你的选择：");
	scanf("%d",&j);
	if(i!=0&&i!=1&&i!=2||j!=0&&j!=1)
		printf("\t输入错误！请重新输入！\n");
	if(m==0&&n==0&&t==0)
	{
		printf("\t输入信息不存在！请重新输入！\n");
		point=1;
		printf("\t");
		system("pause");
		system("cls");
	}
	if(i!=0&&i!=1&&i!=2||j!=0&&j!=1)
	{
		printf("\t");
		system("pause");
		system("cls");
	}
	if(j==0&&i==0&&(m!=0||n!=0||t!=0))
	{
		for(x=0;x<k;x++)
		{
			for(q,p=pHead->next;q->next!=NULL;p=p->next,q=q->next)
			{
				if(i==0&&strcmp(p->profession,a)==0)
				{
					printf("\t请输入需修改学生的专业：");
					fflush(stdin);
					scanf("%s",p->profession);
					printf("\t请输入需修改学生的姓名:");
					scanf("%s",p->name);
					printf("\t请输入需修改学生的学号:");
					scanf("%s",p->number);
					printf("\t请输入需修改学生的性别：");
					scanf("%s",&p->sex);
					printf("\t请输入需修改学生的出生年月日：");
					fflush(stdin);
					scanf("%d%d%d",&p->birthday.year,&p->birthday.month,&p->birthday.day);
					for(i=0;i<3;i++)
					{
						printf("\t请输入需修改学生科目的成绩：");
						fflush(stdin);
						scanf("%lf",&p->score[i]);
					}
				}
			}
		}
	}
	else if(j==0&&i==1&&(m!=0||n!=0||t!=0))
	{
		for(x=0;x<b;x++)
		{
			for(q,p=pHead->next;q->next!=NULL;p=p->next,q=q->next)
			{
				if(i==1&&strcmp(p->name,a)==0)
				{
					printf("\t请输入需修改学生的专业：");
					fflush(stdin);
					scanf("%s",p->profession);
					printf("\t请输入需修改学生的姓名:");
					scanf("%s",p->name);
					printf("\t请输入需修改学生的学号:");
					scanf("%s",p->number);
					printf("\t请输入需修改学生的性别：");
					scanf("%s",&p->sex);
					printf("\t请输入需修改学生的出生年月日：");
					fflush(stdin);
					scanf("%d%d%d",&p->birthday.year,&p->birthday.month,&p->birthday.day);
					for(i=0;i<3;i++)
					{
						printf("\t请输入需修改学生科目的成绩：");
						fflush(stdin);
						scanf("%lf",&p->score[i]);
					}
				}
			}
		}
	}
	else if(j==0&&i==2&&(m!=0||n!=0||t!=0))
	{
		for(x=0;x<c;x++)
		{
			for(q,p=pHead->next;q->next!=NULL;p=p->next,q=q->next)
			{
				if(i==2&&strcmp(p->number,a)==0)
				{
					printf("\t请输入需修改学生的专业：");
					fflush(stdin);
					scanf("%s",p->profession);
					printf("\t请输入需修改学生的姓名:");
					scanf("%s",p->name);
					printf("\t请输入需修改学生的学号:");
					scanf("%s",p->number);
					printf("\t请输入需修改学生的性别：");
					scanf("%s",&p->sex);
					printf("\t请输入需修改学生的出生年月日：");
					fflush(stdin);
					scanf("%d%d%d",&p->birthday.year,&p->birthday.month,&p->birthday.day);
					for(i=0;i<3;i++)
					{
						printf("\t请输入需修改学生科目的成绩：");
						fflush(stdin);
						scanf("%lf",&p->score[i]);
					}
				}
			}
		}
	}
	else if(j==1&&i==0&&(m!=0||n!=0||t!=0))
	{
		for(x=0;x<k;x++)
		{
			for(q,p=pHead->next;q->next!=NULL;p=p->next,q=q->next)
			{
				if(i==0&&strcmp(p->profession,a)==0)
				{
					printf("\t请输入需修改学生的专业：");
					fflush(stdin);
					scanf("%s",p->profession);
				}
			}
		}
	}
	else if(j==1&&i==1&&(m!=0||n!=0||t!=0))
	{
		for(x=0;x<b;x++)
		{
			for(q,p=pHead->next;q->next!=NULL;p=p->next,q=q->next)
			{
				if(i==1&&strcmp(p->name,a)==0)
				{	
					printf("\t请输入需修改学生的姓名:");
					fflush(stdin);
					scanf("%s",p->name);
				}
			}
		}
	}
	else if(j==1&&i==2&&(m!=0||n!=0||t!=0))
	{
		for(x=0;x<c;x++)
		{
			for(q,p=pHead->next;q->next!=NULL;p=p->next,q=q->next)
			{
				if(i==2&&strcmp(p->number,a)==0)
				{
					printf("\t请输入需修改学生的学号:");
					fflush(stdin);
					scanf("%s",p->number);
				}
			}
		}
	}
	return p;
}
struct student *graderemove(struct student *pHead)
{
	struct student *p,*q=pHead;
	char a[20],b[10];
	int i,j,k=0;
	int m=0,n=0;
	do
	{
		printf("\t=============================================================\n");
		printf("\t                    *****信息删除界面*****             \n");
		printf("\t=============================================================\n");    
		printf("\t请输入你需要删除的信息：");
		fflush(stdin);
		gets(a);
		for(p=pHead->next;p!=NULL;p=p->next)
		{
			if(strcmp(p->name,a)==0)
			{
				printf("\t0-姓名信息为：\n");
				if(m==0)
				{
					printf("\t专业\t\t姓名\t学号\t性别\t\t出 生 年 月\t\t科目1\t科目2\t科目3\n");
					m++;
				}
				printf("\t%s\t%s\t%s\t%s\t%d-%d-%d\t\t%.2lf\t%.2lf\t%.2lf\n",p->profession,p->name,p->number,p->sex,p->birthday.year,p->birthday.month,p->birthday.day,p->score[0],p->score[1],p->score[2]);
			    k++;
			}
			if(strcmp(p->number,a)==0)
			{
				printf("\t1-学号信息为：\n");
				if(n==0)
				{
					printf("\t专业\t\t姓名\t学号\t\t性别\t出 生 年 月\t\t科目1\t科目2\t科目3\n");
					n++;
				}
				printf("\t%s\t%s\t%s\t%s\t%d-%d-%d\t\t%.2lf\t%.2lf\t%.2lf\n",p->profession,p->name,p->number,p->sex,p->birthday.year,p->birthday.month,p->birthday.day,p->score[0],p->score[1],p->score[2]);
			}
		}
		printf("\t请选择是否删除该学生全部信息：\n");
		printf("\t0-删除该学生全部信息：\n");
		printf("\t1-删除该学生某项信息：\n");
		printf("\t请输入你的选择：");
		scanf("%d",&j);
		if(j==1)
		{
		printf("\t请选择需要删除的信息种类：\n");
		printf("\t0-姓名：\n");
		printf("\t1-学号：\n");
		printf("\t2-专业：\n");
		printf("\t3-性别：\n");
		printf("\t请输入你的选择：");
		scanf("%d",&i);
		}   
		else
		{
			printf("\t请选择需要删除的信息种类：\n");
			if(m==1)
				printf("\t0-确定：\n");
			if(n==1)
				printf("\t1-学号：\n");
			printf("\t请输入你的选择：");
			scanf("%d",&i);
		}
		if(i!=0&&i!=1&&i!=2&&i!=3&&i!=4&&i!=5&&i!=6&&i!=7||j!=0&&j!=1)
			printf("\t输入错误！请重新输入！\n");
		if(m==0&&n==0)
		{
			printf("\t输入信息不存在！请重新输入！\n");
			point=1;
			printf("\t");
			system("pause");
			system("cls");
		}
		if(i!=0&&i!=1&&i!=2&&i!=3&&i!=4&&i!=5&&i!=6&&i!=7&&i!=8||j!=0&&j!=1)
		{
			printf("\t");
			system("pause");
			system("cls");
		}
		if(j==0&&i==0&&(m!=0||n!=0))
		{
			for(q,p=pHead->next;q->next!=NULL;p=p->next,q=q->next)
			{
				if(i==0&&strcmp(p->name,a)==0)
				{
					q->next=p->next;
					free(p);
					printf("\t删除该学生全部数据成功！\n");
					return q;
				}
			}
		}
		else if(j==0&&i==1&&(m!=0||n!=0))
		{
			for(q,p=pHead->next;q->next!=NULL;p=p->next,q=q->next)
			{
				if(i==1&&strcmp(p->number,a)==0)
				{
					q->next=p->next;
					free(p);
					printf("\t删除该学生全部数据成功！\n");
					return q;
				}
			}
		}
		else if(j==1&&i==0&&(m!=0||n!=0))
		{
			for(q,p=pHead->next;q->next!=NULL;p=p->next,q=q->next)
			{
				if(i==0&&strcmp(p->name,a)==0)
				{
					strcpy(b,"    ");
					strcpy(p->name,b);
					printf("\t删除该学生该姓名项数据成功！\n");
					return q;
				}
			}
		}
		else if(j==1&&i==1&&(m!=0||n!=0))
		{
			for(q,p=pHead->next;q->next!=NULL;p=p->next,q=q->next)
			{
				if(i==1&&strcmp(p->number,a)==0)
				{
					strcpy(b,"    ");
					strcpy(p->number,b);
					printf("\t删除该学生该项学号数据成功！\n");
					return q;
				}
			}
		}
		else if(j==1&&i==2&&(m!=0||n!=0))
		{
			for(q,p=pHead->next;q->next!=NULL;p=p->next,q=q->next)
			{
				if(i==2&&(strcmp(p->number,a)==0||(strcmp(p->name,a)==0)))
				{
					strcpy(b,"    ");
					strcpy(p->profession,b);
					printf("\t删除该学生该专业项数据成功！\n");
					return q;
				}
			}
		}
		else if(j==1&&i==3&&(m!=0||n!=0))
		{
			for(q,p=pHead->next;q->next!=NULL;p=p->next,q=q->next)
			{
				if(i==3&&(strcmp(p->number,a)==0||(strcmp(p->name,a)==0)))
				{
					strcpy(b,"    ");
					strcpy(p->sex,b);
					printf("\t删除该学生该性别项数据成功！\n");
					return q;
				}
			}
		}
	}while(i!=0&&i!=1&&i!=2&&i!=3&&i!=4&&i!=5&&i!=6&&i!=7&&i!=8||j!=0&&j!=1);
	return q;
}

void sort(struct student *pHead)
{
	struct student *p=pHead,*q;
	struct student *max,*min,*t,*h,*m;
	int i,j=0,k;
	h=NULL;
	m=p;
	do
	{
		printf("\t=============================================================\n");
		printf("\t                    *****输出学生信息*****             \n");
		printf("\t=============================================================\n");
		printf("\t请选择输出的方式：\n");
		printf("\t0-按姓名输出：\n");
		printf("\t1-按学号输出：\n");
		printf("\t2-按专业输出：\n");
		printf("\t请输入你的选择:");
		scanf("%d",&k);
		printf("\t请选择输出学号的方式：\n");
		printf("\t0-直接输出：\n");
		printf("\t1-从大到小输出:\n");
		printf("\t2-从小到大输出:\n");
		printf("\t请输入你的选择:");
		scanf("%d",&i);
		if((k!=0&&k!=1&&k!=2)||(i!=0&&i!=1&&i!=2))
			printf("\t输入错误！请重新输入！\n");
		if(k==1)
		{
			if(i==1)
			{
				while(m->next)
				{
					
					for(max=m,q=m->next;q->next;q=q->next)
					{
						if(strcmp(q->next->number,max->next->number)>0)
						{
							max=q;
						}
					}
					q=max->next;
					max->next=q->next;
					q->next=NULL;
					if(h)
						t=t->next=q;
					else
						h=t=q;
				}
			}
			else if(i==2)
			{
				while(m->next)
				{
					
					for(min=m,q=m->next;q->next;q=q->next)
					{
						if(strcmp(q->next->number,min->next->number)<0)
						{
							min=q;
						}
					}
					q=min->next;
					min->next=q->next;
					q->next=NULL;
					if(h)
						t=t->next=q;
					else
						h=t=q;
				}
			}
			else if(i==0)
			{
				print(pHead->next);
			}
		}
		else if(k==0)
		{
			if(i==1)
			{
				while(m->next)
				{
					
					for(max=m,q=m->next;q->next;q=q->next)
					{
						if(strcmp(q->next->name,max->next->name)>0)
						{
							max=q;
						}
					}
					q=max->next;
					max->next=q->next;
					q->next=NULL;
					if(h)
						t=t->next=q;
					else
						h=t=q;
				}
			}
			else if(i==2)
			{
				while(m->next)
				{
					
					for(min=m,q=m->next;q->next;q=q->next)
					{
						if(strcmp(q->next->name,min->next->name)<0)
						{
							min=q;
						}
					}
					q=min->next;
					min->next=q->next;
					q->next=NULL;
					if(h)
						t=t->next=q;
					else
						h=t=q;
				}
			}
			else if(i==0)
			{
				print(pHead->next);
			}
		}
		else if(k==2)
		{
			if(i==1)
			{
				while(m->next)
				{
					
					for(max=m,q=m->next;q->next;q=q->next)
					{
						if(strcmp(q->next->profession,max->next->profession)>0)
						{
							max=q;
						}
					}
					q=max->next;
					max->next=q->next;
					q->next=NULL;
					if(h)
						t=t->next=q;
					else
						h=t=q;
				}
			}
			else if(i==2)
			{
				while(m->next)
				{
					
					for(min=m,q=m->next;q->next;q=q->next)
					{
						if(strcmp(q->next->profession,min->next->profession)<0)
						{
							min=q;
						}
					}
					q=min->next;
					min->next=q->next;
					q->next=NULL;
					if(h)
						t=t->next=q;
					else
						h=t=q;
				}
			}
			else if(i==0)
			{
				print(pHead->next);
			}
		}
		t=h;
		while(t!=NULL)
		{
			if(j==0)
			{
				printf("\t专业\t\t姓名\t学号\t\t性别\t出 生 年 月\t\t科目1\t科目2\t科目3\n");
				j++;
			}
			printf("\t%s\t%s\t%s\t%s\t%d-%d-%d\t\t%.2lf\t%.2lf\t%.2lf\n",t->profession,t->name,t->number,t->sex,t->birthday.year,t->birthday.month,t->birthday.day,t->score[0],t->score[1],t->score[2]);
			t=t->next;
		}
		if(i!=0)
		{
			printf("\t");
			system("pause");
			system("cls");
		}
		if(i==0&&(k!=0&&k!=1&&k!=2))
		{
			printf("\t");
			system("pause");
			system("cls");
		}
	}while((k!=0&&k!=1&&k!=2)||(i!=0&&i!=1&&i!=2));
}
struct student *showallgrades()
{
	struct student *p;
	p=graderefer();
	sort(p);
	system("cls");
	return p;
}
void gradesum(struct student *pHead)
{
	struct student *p=pHead;
	int Index=0;
	printf("\t=============================================================\n");
    printf("\t                    *****学生人数统计界面*****             \n");
    printf("\t=============================================================\n"); 
	while(p->next!=NULL)
	{
		Index++;
		p=p->next;
	}
	printf("\t成绩总个数为:%d\n",Index);
	printf("\t");
    system("pause");
    system("cls");

}
void quit()
{
    printf("\n\n\n\n\n\n\n\n");
    printf("\t                       程序结束！\n");
    printf("\t                       感谢您的使用！\n");
	printf("\t                      ");
    exit(0);
}
