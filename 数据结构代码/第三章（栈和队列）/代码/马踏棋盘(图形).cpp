//想法:创建两个链栈,一个储存下一步可以选择的路,另一个储存按照其中一种情况马的行进轨迹,每次如果失败，就将路线出栈一次，取栈顶元素,再次判断,如果成功，就打印出马的移动路线，如果全部失败，则此道路不通，不能实现马踏棋盘，请用户选择新的开始坐标
//现在依然存在的问题:判断下一个格子是否已经踏过
//可优化的地方:用getTop函数来代替全局的一维数组
#include <graphics.h>
//是TC的针对DOS下的一个C语言图形库，如果要用的话应该用TC的编译器来编译，VC++环境有其它的针对windows的图形库
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define N 20


typedef struct location {
	int x;
	int y;
}LOC;//记录马的当前位置

typedef struct node {
	LOC loc;//当前坐标
        int num;//储存现在已经踏完的格子数              //存储方向！ 
	struct node * pNext;
}NODE,*PNODE;

typedef struct stack {
	struct node * top;//栈顶指针
	struct node * bottom;//栈底指针
}STACK,*PSTACK;


void init(); 				//初始化栈 
void push(LOC loc);			//进栈 
void pop();					// 出栈,注意要判空
int empty();				//判空栈 
void trave();				//输出马的行走路线
void clear();				//置空栈 
PNODE GetTop();				//取栈顶元素
//LOC check(int t,int * psize);	//判断坐标是否合理 
LOC check();
int  check1(LOC n);
void jiemian();

STACK sp;
PSTACK s = &sp;//s表示马的行进路径,全局变量必须在定义的同时初始化，否则会报错
LOC size[64];//存储马的坐标
int f = 0,k,size1[64] = {0};          
int  curpos=0;       //总共走了多少步。 
int qipanjud[8][8] = {{0}};




int main(void) {


    LOC loc,n;//坐标
	int flag,i,j;
    char a[N];
	flag = 1;
	jiemian();
    MOUSEMSG m;

	while(1) {
		fflush(stdin);

		//InputBox(s1,10 ,"请输入起始位置:");
        //sscanf(s1,s2,"%d,%d",&loc.x,&loc.y);
        settextcolor(BLACK);
        settextstyle(50, 0, _T("宋体"));
        RECT r = {0, 0, 640, 640};
	    drawtext("按任意键开始游戏", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		getch();
        clearrectangle(0,0,640,640);
        closegraph();
        jiemian();
		getchar();
		FlushMouseMsgBuffer();
        m = GetMouseMsg();
		
		//printf("请输入马在棋盘的起始位置:");
		//scanf("(%d,%d)",&loc.x,&loc.y);
		for(i = 1;i < 9;i++) {
			for(j = 1;j < 9;j++) {
			if(m.x > 80*(i-1) &&m.x < 80*i&&m.y >80*(j-1)&&m.y < 80*j) {
			loc.x = i;
			loc.y = j;
			break;
			}else 
				continue;
			}
		}
		//printf("%d",loc.x);
		//getchar();
		if(loc.x > 8||loc.y > 8||loc.x < 1||loc.y < 1) {      
			printf("\n输入坐标在棋盘外,请重新输入!\n");
		}
		else
			break;
	}
		init();
		size[f] = loc;				//记录已经走过的坐标	
	    qipanjud[loc.x][loc.y]=1;   //已经走过增加棋盘标识 
        settextcolor(BLACK);
        settextstyle(40, 0, _T("宋体"));
		RECT r = {0+(size[f].x-1)*80,0+(size[f].y-1)*80,80+size[f].x*80,80+size[f].y*80};
		//drawtext(_T("Hello World"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		setfillcolor(DARKGRAY);
		fillrectangle(0+(size[f].x-1)*80,0+(size[f].y-1)*80,size[f].x*80,size[f].y*80);
		//drawtext("size[f].x", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//sscanf(size[f].x,size[f].y,"%c,%c",&a,&b);
        sprintf(a, "%d", curpos+1);
		printf("%s",a);
        outtextxy(80*size[f].x-40,80*size[f].y-40,a);
	    curpos++;          			//记录已经走了一步 
		push(loc);					//入栈	
		s->top->num = 0;    		//开始方向偏向为 0 
	
	while(1) {//走迷宫
	    n = check();
//	    printf("\n%d,%d  ****\n",n.x,n.y);
//		printf("\n%d\n  ",size1[f]);
        if((n.x != size[f].x||n.y != size[f].y)) {
		f++;
		size[f] = n;
		printf("入栈:(%d,%d)     第：%d\n",size[f].x,size[f].y,curpos+1);
		settextcolor(BLACK);
		settextstyle(40, 0, _T("宋体"));
		RECT r = {0+(size[f].x-1)*80,0+(size[f].y-1)*80,80+size[f].x*80,80+size[f].y*80};
		setfillcolor(DARKGRAY);
		fillrectangle(0+(size[f].x-1)*80,0+(size[f].y-1)*80,size[f].x*80,size[f].y*80);
        sprintf(a, "%d", curpos+1);
		//printf("%s",a);
		
        outtextxy(80*size[f].x-40,80*size[f].y-40,a);
       
		push(size[f]);
       // getch();
		Sleep(500);
		qipanjud[size[f].x][size[f].y]=1; 
//		flag++;
		curpos++;
//		s->top->num = flag;
		}
		else {
//			pop(size[f]);
		//	while(s->top->num==0){
		printf("出栈：%d,%d,%d  ,第：%d\n",s->top->loc.x,s->top->loc.y,s->top->num,curpos-1);
        settextcolor(BLACK);
		settextstyle(40, 0, _T("宋体"));
		RECT r = {0+(size[f].x-1)*80,0+(size[f].y-1)*80,80+size[f].x*80,80+size[f].y*80};
		setfillcolor(WHITE);
		fillrectangle(0+(size[f].x-1)*80,0+(size[f].y-1)*80,size[f].x*80,size[f].y*80);
        sprintf(a, "%d", 0);
		//printf("%s",a);
        outtextxy(80*size[f].x-40,80*size[f].y-40,a);
		qipanjud[s->top->loc.x][s->top->loc.y]=0;
		pop();
			//	getch();
        Sleep(500);
///				printf("当前：%d,%d,%d",s->top->loc.x,s->top->loc.y,s->top->num);
		f--;
//				size1[f]++;
//				flag--;
		curpos--;
				
		}
		//if(curpos == 61)    getchar();
		
		if(curpos == 64)
			break;
		
	}
	printf("马的行走路线是:");
	trave();
	getch();
    settextcolor(BLACK);
    settextstyle(50, 0, _T("宋体"));
	drawtext("游戏结束,按任意键退出", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    getch();
    clearrectangle(0,0,640,640);
    closegraph();
	return 0;
}
void jiemian() {
	int i;
	initgraph(640, 640);
	setbkcolor(0xFFFFFF);
    cleardevice();
    setlinecolor(BLACK);
	for(i = 1;i < 9 ;i++) {
       	line(0,80*i,640,80*i);
	}
	for(i = 1;i < 9;i++) {
        line(80*i,0,80*i,640);
	}
}


void init() {//初始化栈,将栈顶指针和栈底指针指向同一个节点
	s->top = (PNODE)malloc(sizeof(NODE));
	if(s->top == NULL) {
		printf("error!!!\n");
		exit(1);
	}
	s->bottom = s->top;
	s->top->pNext = NULL;
}

void push(LOC loc) {//进栈操作
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL) {
		printf("error!!!\n");
		exit(1);
	}
	pNew->pNext = s->top;
	s->top = pNew;
	pNew->loc = loc;
	pNew->num=0;
}


int empty() {
	if(s->top == s->bottom)
		return 1;
	else 
		return 0;
}

void pop() {//出栈,注意要判空
	PNODE p;
	if(!empty()) {
        p = s->top;
	s->top = s->top->pNext;
	free(p);
	p = NULL;
	}
}

void trave() {//输出马的行走路线
/*
	PNODE p;
	p = s->top;
	printf("\n"); 
	while(p != s->bottom) {
		printf("(%d,%d)   ",p->loc.x,p->loc.y);
		p = p->pNext;
	}
	printf("\n");
*/
	int i=0;
	while(i<64)
	{
		if(i%8==0)	printf("\n");
		printf("(%d,%d)   ",size[i].x,size[i].y);
		i++;
	}

}
void clear() {//置空栈
	PNODE p,q;
	p = s->top;
    q = p->pNext;
	while(p != s->bottom) {
		free(p);
		p = q;
		q = q->pNext;
	}
	s->top = s->bottom;
}

PNODE GetTop() {//取栈顶元素
	return s->top;
}


/*
LOC check(int t,int * psize) {//返回合理坐标
	LOC n;
	int i,p;
    int Htry1[8] = {-2,-1,1,2,2,1,-1,-2};
	int Htry2[8] = {1,2,2,1,-1,-2,-2,-1};
	for(i = *psize;i < 8;i++) { 

		//printf("%d---------%d   %d",t,size[t].x,size[t].y);
		n.x = size[t].x + Htry1[i];
		n.y = size[t].y + Htry2[i];
		printf("(%d,%d)",n.x,n.y);
		
//		printf("\n%d\n",s->top->num);
//		getchar();getchar();getchar();getchar();
		p=s->top->num;    //方向标识 
	    if(n.x > 7||n.x < 0||n.y > 7||n.x < 0) {//如果坐标不正确，就用原来的坐标的坐标值赋值
		    continue;
		}
	    else{ 	 
	    	s->top->num++;
 			break;
        }
	}
	*psize = i;
	return n;
}
*/


LOC check()
{
	LOC n;
//	printf("p=s->top->num   %d\n",s->top->num);
	int i,p=s->top->num;
    int Htry1[8] = {-2,-1,1,2,2,1,-1,-2};
	int Htry2[8] = {1,2,2,1,-1,-2,-2,-1};
	for(i = p ;i < 8;i++) { 

		//printf("%d---------%d   %d",t,size[t].x,size[t].y);
		n.x = s->top->loc.x + Htry1[i];
		n.y = s->top->loc.y + Htry2[i];
	//	printf("(%d,%d)",n.x,n.y);
		//if(n.x > 7||n.x < 0||n.y > 7||n.y < 0||check1(n))
		if(n.x > 8||n.x < 1||n.y > 8||n.y < 1||check1(n))
		{//如果坐标不正确，就用原来的坐标的坐标值赋值
///			printf("**********************************88\n");
		//	s->top->num++;
		    continue;
		}
	    else{
			if(s->top->num==8)		
			{
			    s->top->num=0;//	s->top->num==0;	//这里是否有问题
				return s->top->loc;	
			}
			if(p!=0)	{
				p--;
				continue; 	 
		    }
			s->top->num++;
///			printf("jud :    %d\n",s->top->num);
 			break;
        }
	}	
	
//	getchar();getchar();getchar();
	if(!check1(n)&&i!=8)
	{
///		printf("(%d,%d)   ##########\n",n.x,n.y);	
		return n;
	}
	else 
		return s->top->loc;	
}


int  check1(LOC n)  //检测此处是否已经走过 
{
	if(qipanjud[n.x][n.y]==1)
		return 1;
	return 0;		
}


