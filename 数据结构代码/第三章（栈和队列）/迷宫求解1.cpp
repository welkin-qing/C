#include<stdio.h>  
#include<stdlib.h>  
#define M 50//�����з�Χ  
#define N 50//�����з�Χ  
typedef struct node//����һ���ṹ��洢������Ϣ  
{  
         int x;  //���� 
         int y;  //���� 
         int c;  //���� 
}linkstack; 
int maze[M][N];  //�����ά����
linkstack top[M*N];  //����һ��M*N��ջ 
int m=1;
int run;
int i,j,k;
void array(int width,int height) //�Զ�ά���鶨���Թ����� 
{
	for(int i=0;i<width;i++)
	{
		for(int j=0;j<height;j++)
		{
			scanf("%d",&maze[i][j]);
		}
	}
}
void print_maze(int width,int height)
{
	for(int i=0;i<width;i++)
	{
		for(int j=0;j<height;j++)
		{
			printf("%d",maze[i][j]);
		}
		printf("\n");
	}
}
main()
{
	int wid,hei;
	int k;
	int i;
	int v;
	scanf("%d %d",&wid,&hei);
	array(wid,hei);
	for(i=0;i<wid*hei;i++)
	{
		top[i].c=1;
	}
	  
	print_maze(wid,hei);//�����Թ�
	i=0;
	top[i].x=1;  //�������Ͻ� 
	top[i].y=1;
	maze[1][1]=2;  //����Թ�ֵ
//�������߹���ͳ����ж� 
    run=1;
	do{
		if(top[i].c<5)  //������ֵС��5�����½��� 
		{
			if(top[i].x==(wid-2)&&top[i].y==(hei-1))
			printf("��%d��ͨ·��:\n",m++);
			for(j=0;j<=i;j++)
			{
				printf("(%d,%d,%d)",top[j].x,top[j].y,top[j].c);
			}
			printf("\n");
			for(j=0;j<wid;j++)  //���Թ�ͼ�� 
			{
				for(k=0;k<hei;k++)
				{
					if(maze[j][k]==0)   printf(" ");
					else if(maze[j][k]==2)  printf("0");
					else printf("#");
				}
				printf("\n");
			}
			maze[top[i].x][top[i].y]==0;
			top[i].c=1;
			i--;
			top[i].c+=1;
			continue;
		}
		switch(top[i].c)  
             {   
                                 case 0:  
                 { run=0;  
                if(v==1)  
                     printf("���Թ���ͨ·!");  
                  break;  
                 }  
                case 1:  
                {  if(maze[top[i].x][top[i].y+1]==0)  
                {  i++;  
                       top[i].x=top[i-1].x;  
                       top[i].y=top[i-1].y+1;  
                      maze[top[i].x][top[i].y]=2;  
                   if(maze[wid-2][hei-1]==2) v=0;  
                }  
                       else   top[i].c+=1;  
                 break;  
                }  
                case 2:  
                {if(maze[top[i].x-1][top[i].y]==0)  
                { i++;  
                       top[i].x=top[i-1].x-1;  
                       top[i].y=top[i-1].y;  
                      maze[top[i].x][top[i].y]=2;  
                  
                }  
                       else   top[i].c+=1;  
                  break;  
                }  
                case 3:  
                {  if(maze[top[i].x][top[i].y-1]==0)  
                {  i++;  
                       top[i].x=top[i-1].x;  
                       top[i].y=top[i-1].y-1;  
                      maze[top[i].x][top[i].y]=2;  
   
                }  
                       else   top[i].c+=1;  
                  break;  
                }  
                case 4:  
                {  if(maze[top[i].x+1][top[i].y]==0)  
                {  i++;  
                       top[i].x=top[i-1].x+1;  
                       top[i].y=top[i-1].y;  
                      maze[top[i].x][top[i].y]=2;  
                   
                }  
                       else   top[i].c+=1;  
                  break;  
                }  
          } 
		  //else{
		     if(i==0) return 0;
		     maze[top[i].x][top[i].y]=0; 
	         top[i].c=1;  
		     i--;  
		     top[i].c+=1;
			// } 
	} while(run==1);
	
}

