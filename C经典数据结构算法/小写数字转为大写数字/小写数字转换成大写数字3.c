#include<stdio.h>
void main()
{
double x,y;
char *ch[]={"��","Ҽ","��","��","��","��","½","��","��","��"};
char *ch1[]={"ʰ","��","Ǫ","��","ʰ","��","Ǫ","��"};
char num[256];
long i,n,j,m,y1;
printf("input:");
scanf("%lf",&x);
n=(long)x;/*����������*/
y=x-n;/*��С������*/
for(i=0;n!=0;i++)
  {
  num[i]=(char)(n%10);
  n/=10;
  }
m=i;
num[i]='.';
for(y=y*10;(long)((y-(long)y)*10);) /*���С��λ��������(��0)ѭ������*/
    y*=10;/*С��ת��Ϊ������0.11111תΪ11111.00...*/
y1=(long)y;
for(i=m+1;y1!=0;i++)
    {num[i]=(char)(y1%10);
      y1=y1/10;}/*ȡ��λ�ϵ�����*/
for(n=0;;n++)
  {
    if(num[n]=='.')
      {
      for(j=n-1;j>=0;j--)/*�ж��Ƿ�����λ,��λ..�������ж��Ƿ���0���ǾͲ������.*/
          {
          if(m<=5)
            if(m==5&&(int)num[j]==0)
              ;
            else
                printf("%s",ch[(int)num[j]]);/*�����дҼ..*/
          else
            if(m%4==0&&(int)num[j]==0)
                  ;
            else
              printf("%s",ch[(int)num[j]]);
          if(m>=2)
            {printf("%s",ch1[m-2]);/*���ʰ��Ǫ..����2λ�����ʰ*/
              m=m--;}
          }
      printf("��");
      break;
      }
  }
  for(i=i-1;num[i]!='.';i--)
    printf("%s",ch[(int)num[i]]);/*���С������*/
}  