/********
ʹ�ù�basic���Ե����Ѷ�֪��,basic����һ����Ҫ�Ĺ���,����ʱ������.����������������кͶ��¼��Ĵ����첽����.ͨ������ʱ������.�����ڹ涨��ʱ����������Զ�ִ��ĳ���ӳ���.�ӳ������н������ֻص�������Ķϵ㴦����ִ��.basic�����ṩ���й�ʱ����������.����ֱ�ӵ�ӵ�C����û�������Ĺ���,Ϊ����ʵ����������,��������˼����Ӻ����԰���ʵ��.

    on_timer(t,p):    �趨��ʱʱ����Ϊt(����Ϊ��λ).���涨���¼������Ӻ�������ڵ�.t����
                      ����,p��ָ���Ӻ�����ָ��.
    timer_on():      ������ʱ����ʼ��ʱ.�Ժ�ÿ��t��,ָ��p��ָ����Ӻ�������һ��.
    timer_off():    �رն�ʱ��.

�������Ӻ����嵥.
***************/
/*timer ģ��Դ�����嵥*/

#include<dos.h>

#define Sizeprogram 375
void interrupt (*oldtimer)();
void interrupt newtimer();
static struct SREGS seg;
unsigned intsp,intss;
unsigned myss,stack;
unsigned vseg;
int running=0;
int m1,m2,m3=0;
int (*sub_ptr)();
void on_timer();
void timer_on();
void timer_off();

void on_timer(t,pp)
int t;
int (*pp)();
{
    sub_ptr=pp;
    m1=t;
    segread(&seg);
    stack=(Sizeprogram-(seg.ds-seg.cs))*16-300;
    myss=_SS;
    oldtimer=getvect(0x1c);
}

void timer_on()
{
    m2=0;
    m3=1;
    setvect(0x1c,newtimer);
}
void timer_off()
{
    m3=0;
    setvect(0x1c,oldtimer);
}
void interrupt newtimer()
{
    (*oldtimer)();
    if(running==0)
        running=1;
        disable();
        intsp=_SP;
        intss=_SS;
        _SP=stack;
        _SS=myss;
        enable();
        if(m3==1){
            if(m2==m1*18){
            m2=0;
	    (*sb_ptr)();
            }
            m2+=1;
        }
        disable();
        _SP=intsp;
        _SS=intss;
        enable();
        running=0;
    }
}