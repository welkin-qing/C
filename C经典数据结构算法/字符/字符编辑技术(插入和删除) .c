#include<string.h>
#include<ctype.h>

/*���뺯�� ccode��������ַ� anystring��������ַ��� spos���뵽�ַ�����λ��*/
void cinsert(char ccode,char *anystring,int spos)
{
    int p;  
    p=strlen(anystring);  /*�ַ����ĳ���*/
    spos=spos<0?0:spos;  /*���뷶Χ*/
    spos=spos>=p?p:spos;
    for(;p>=spos;p--)
        anystring[p+1]=anystring[p]; /*������������Ǹ�Ԫ�ؿ�ʼ���ϼ�*/
    anystring[spos]=ccode;  /*������ַ�*/
}

/*ɾ������ anystring��ɾ�����ַ��� sposɾ���ڼ����ַ�*/
void cdelete(char *anystring,int spos)
{
    int p;
    p=strlen(anystring);  /*�ַ����ĳ���*/
    if(p>0&&spos>=0&&spos<=p){
        while(spos<p)
        {
            anystring[spos]=anystring[spos+1];
            spos++;
        }
    }
}
