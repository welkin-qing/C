�������������,�ܽ�����һ���ַ����еĲ����ɾ��һ���ַ�,����Ȥ�Ŀ��Բο�һ��.

  

#include<string.h>
#include<ctype.h>

void cinsert(char ccode,char *anystring,int spos)
{
    int p;
    p=strlen(anystring);
    spos=spos<0?0:spos;
    spos=spos>=p?p:spos;
    for(;p>=spos;p--)
        anystring[p+1]=anystring[p];
    anystring[spos]=ccode;
}

void cdelete(char *anystring,int spos)
{
    int p;
    p=strlen(anystring);
    if(p>0&&spos>=0&&spos<=p){
        while(spos<p){
            anystring[spos]=anystring[spos+1];
            spos++;
        }
    }
}

