#include<stdio.h>
#define r 64
#define m2 8
#define n2 10
int m=m2-2,n=n2-2;
typedef struct
{
	int x,y;    //��������
	int pre;
}sqtype;

sqtype sq[r];
struct moved
{
	int x, y;  //����������ȡֵ-1��0��1
}move[8];

int maze[m2][n2];

int PATH(int maze[][n2])  //���Թ�maze��·��
{
	int i,j,k,v,front,rear,x,y;
	int mark[m2][n2];
	for(i=0;i<m2;i++)
		for(j=0;j<n2;j++)
			mark[i ][j]=0;
	printf("Please Input move array\n");
	for(i=0;i<8;i++)
	{
		scanf("%d,%d",&move[i ].x,&move[i ].y);
	sq[1].x=1;
	sq[1].y=1;
	sq[1].pre=0;
	front=1;
	rear=1;
	mark[1][1]=1;   //�������Ե����
	while(front<=rear)
	{
		x=sq[front].x;
		y=sq[front].y;    //(x,y)Ϊ������
		for(v=0;v<8;v++)  //����(x,y)��8������(i,j)�Ƿ���Ե���
		{
			i=x+move[v].x;
			j=y+move[v].y;
			if((maze[i ][j]==0)&&(mark[i ][j]==0))//(i,j)Ϊ���Ե���㣬�������
			{
				rear++;
				sq[rear].pre=front;
				mark[i ][j]=1; //���(i,j)�Ѿ������
			}
			if((i==m)&&(j==n))    //�������
			{
				printf("THE PATH: \n");
				k=rear;
				do
				{
					printf("(%d %d)<-",sq[k].x,sq[k].y);
					k=sq[k].pre;//��ǰһ��
				}while(k!=0);//k=0���Ѿ�����
				for(i=1;i<19;i++)
					printf("%3d",i);
				printf("\n");
				for(i=1;i<19;i++)
					printf("%3d",sq[i ].x);
				printf("\n");
				for(i=1;i<19;i++)
					printf("%3d",sq[i ].y);
				printf("\n");
				for(i=1;i<19;i++)
					printf("%3d",sq[i ].pre);
				printf("\n");
				return(1);      //�ɹ�����
			}
		}
		front++;   //���ӣ�front ָ���µĳ�����
	} 
	}
     //�ӿգ�ѭ������
	printf("There is no path! \n");
	return(0);   //�Թ�û��·������
}

main()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		maze[0][i ]=1;
		maze[7][i ]=1;
	}
	for(i=0;i<8;i++)
	{
		maze[i ][0]=1;
		maze[i ][9]=1;
	}
	/*for(i=1;i<7;i++)
		for(j=1;j<9;j++)
		{
			printf("%d %d",i,j);
			scanf("%d",&maze[i ][j]);
		}*/	
	maze[1][1]=0;maze[1][2]=1;maze[1][3]=0;maze[1][4]=1;maze[1][5]=1;maze[1][6]=0;maze[1][7]=1;maze[1][8]=1;
    maze[2][1]=1;maze[2][2]=0;maze[2][3]=0;maze[2][4]=1;maze[2][5]=1;maze[2][6]=0;maze[2][7]=1;maze[2][8]=0;
	maze[3][1]=0;maze[3][2]=1;maze[3][3]=1;maze[3][4]=0;maze[3][5]=0;maze[3][6]=1;maze[3][7]=1;maze[3][8]=1;
	maze[4][1]=1;maze[4][2]=0;maze[4][3]=0;maze[4][4]=1;maze[4][5]=1;maze[4][6]=0;maze[3][7]=0;maze[4][8]=1;
	maze[5][1]=1;maze[5][2]=1;maze[5][3]=0;maze[5][4]=0;maze[5][5]=1;maze[5][6]=1;maze[5][7]=0;maze[5][8]=1;
	maze[6][1]=0;maze[6][2]=1;maze[6][3]=1;maze[6][4]=1;maze[6][5]=0;maze[6][6]=0;maze[6][7]=0;maze[6][8]=0;

	printf("\n");
	for(i=0;i<8;i++)
	{
		for(j=0;j<10;j++)
			printf("%d",maze[i ][j]);
		printf("\n");
	}
	PATH(maze);
}