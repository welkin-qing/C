//�뷨:����������ջ,һ��������һ������ѡ���·,��һ�����水������һ���������н��켣,ÿ�����ʧ�ܣ��ͽ�·�߳�ջһ�Σ�ȡջ��Ԫ��,�ٴ��ж�,����ɹ����ʹ�ӡ������ƶ�·�ߣ����ȫ��ʧ�ܣ���˵�·��ͨ������ʵ����̤���̣����û�ѡ���µĿ�ʼ����
//������Ȼ���ڵ�����:�ж���һ�������Ƿ��Ѿ�̤��
//���Ż��ĵط�:��getTop����������ȫ�ֵ�һά����
#include <graphics.h>
//��TC�����DOS�µ�һ��C����ͼ�ο⣬���Ҫ�õĻ�Ӧ����TC�ı����������룬VC++���������������windows��ͼ�ο�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define N 20


typedef struct location {
	int x;
	int y;
}LOC;//��¼��ĵ�ǰλ��

typedef struct node {
	LOC loc;//��ǰ����
        int num;//���������Ѿ�̤��ĸ�����              //�洢���� 
	struct node * pNext;
}NODE,*PNODE;

typedef struct stack {
	struct node * top;//ջ��ָ��
	struct node * bottom;//ջ��ָ��
}STACK,*PSTACK;


void init(); 				//��ʼ��ջ 
void push(LOC loc);			//��ջ 
void pop();					// ��ջ,ע��Ҫ�п�
int empty();				//�п�ջ 
void trave();				//����������·��
void clear();				//�ÿ�ջ 
PNODE GetTop();				//ȡջ��Ԫ��
//LOC check(int t,int * psize);	//�ж������Ƿ���� 
LOC check();
int  check1(LOC n);
void jiemian();

STACK sp;
PSTACK s = &sp;//s��ʾ����н�·��,ȫ�ֱ��������ڶ����ͬʱ��ʼ��������ᱨ��
LOC size[64];//�洢�������
int f = 0,k,size1[64] = {0};          
int  curpos=0;       //�ܹ����˶��ٲ��� 
int qipanjud[8][8] = {{0}};




int main(void) {


    LOC loc,n;//����
	int flag,i,j;
    char a[N];
	flag = 1;
	jiemian();
    MOUSEMSG m;

	while(1) {
		fflush(stdin);

		//InputBox(s1,10 ,"��������ʼλ��:");
        //sscanf(s1,s2,"%d,%d",&loc.x,&loc.y);
        settextcolor(BLACK);
        settextstyle(50, 0, _T("����"));
        RECT r = {0, 0, 640, 640};
	    drawtext("���������ʼ��Ϸ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		getch();
        clearrectangle(0,0,640,640);
        closegraph();
        jiemian();
		getchar();
		FlushMouseMsgBuffer();
        m = GetMouseMsg();
		
		//printf("�������������̵���ʼλ��:");
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
			printf("\n����������������,����������!\n");
		}
		else
			break;
	}
		init();
		size[f] = loc;				//��¼�Ѿ��߹�������	
	    qipanjud[loc.x][loc.y]=1;   //�Ѿ��߹��������̱�ʶ 
        settextcolor(BLACK);
        settextstyle(40, 0, _T("����"));
		RECT r = {0+(size[f].x-1)*80,0+(size[f].y-1)*80,80+size[f].x*80,80+size[f].y*80};
		//drawtext(_T("Hello World"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		setfillcolor(DARKGRAY);
		fillrectangle(0+(size[f].x-1)*80,0+(size[f].y-1)*80,size[f].x*80,size[f].y*80);
		//drawtext("size[f].x", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//sscanf(size[f].x,size[f].y,"%c,%c",&a,&b);
        sprintf(a, "%d", curpos+1);
		printf("%s",a);
        outtextxy(80*size[f].x-40,80*size[f].y-40,a);
	    curpos++;          			//��¼�Ѿ�����һ�� 
		push(loc);					//��ջ	
		s->top->num = 0;    		//��ʼ����ƫ��Ϊ 0 
	
	while(1) {//���Թ�
	    n = check();
//	    printf("\n%d,%d  ****\n",n.x,n.y);
//		printf("\n%d\n  ",size1[f]);
        if((n.x != size[f].x||n.y != size[f].y)) {
		f++;
		size[f] = n;
		printf("��ջ:(%d,%d)     �ڣ�%d\n",size[f].x,size[f].y,curpos+1);
		settextcolor(BLACK);
		settextstyle(40, 0, _T("����"));
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
		printf("��ջ��%d,%d,%d  ,�ڣ�%d\n",s->top->loc.x,s->top->loc.y,s->top->num,curpos-1);
        settextcolor(BLACK);
		settextstyle(40, 0, _T("����"));
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
///				printf("��ǰ��%d,%d,%d",s->top->loc.x,s->top->loc.y,s->top->num);
		f--;
//				size1[f]++;
//				flag--;
		curpos--;
				
		}
		//if(curpos == 61)    getchar();
		
		if(curpos == 64)
			break;
		
	}
	printf("�������·����:");
	trave();
	getch();
    settextcolor(BLACK);
    settextstyle(50, 0, _T("����"));
	drawtext("��Ϸ����,��������˳�", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
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


void init() {//��ʼ��ջ,��ջ��ָ���ջ��ָ��ָ��ͬһ���ڵ�
	s->top = (PNODE)malloc(sizeof(NODE));
	if(s->top == NULL) {
		printf("error!!!\n");
		exit(1);
	}
	s->bottom = s->top;
	s->top->pNext = NULL;
}

void push(LOC loc) {//��ջ����
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

void pop() {//��ջ,ע��Ҫ�п�
	PNODE p;
	if(!empty()) {
        p = s->top;
	s->top = s->top->pNext;
	free(p);
	p = NULL;
	}
}

void trave() {//����������·��
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
void clear() {//�ÿ�ջ
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

PNODE GetTop() {//ȡջ��Ԫ��
	return s->top;
}


/*
LOC check(int t,int * psize) {//���غ�������
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
		p=s->top->num;    //�����ʶ 
	    if(n.x > 7||n.x < 0||n.y > 7||n.x < 0) {//������겻��ȷ������ԭ�������������ֵ��ֵ
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
		{//������겻��ȷ������ԭ�������������ֵ��ֵ
///			printf("**********************************88\n");
		//	s->top->num++;
		    continue;
		}
	    else{
			if(s->top->num==8)		
			{
			    s->top->num=0;//	s->top->num==0;	//�����Ƿ�������
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


int  check1(LOC n)  //���˴��Ƿ��Ѿ��߹� 
{
	if(qipanjud[n.x][n.y]==1)
		return 1;
	return 0;		
}


