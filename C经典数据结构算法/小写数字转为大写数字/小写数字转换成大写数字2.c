/***  ����: 123.45    �������Ҽ�۷�ʰ�������顱 ***/


#include <stdio.h>  /*��׼�����������*/
#include <string.h>  /*�ַ�������*/
#include <stdlib.h>  

void ConvertN(int n,char* &p,bool IsSequece=true);  /*��������ConvertN*/
bool ConvertSegment(int number,int n,char* &p,bool IsLastZiero); /*��������ConvertSegment*/
bool ChangeNumber(double dbNumber,char* lpszvalues);  /*��������ChangeNumber*/

void main() 
{ 
 double db=-1200008.9876; 
 printf("%lf\n",db); 
 char buf[100]; 
 if(ChangeNumber(db,buf)) 
   printf("%s\n",buf); 

 db=1000000.98; 
 printf("%lf\n",db); 
 if(ChangeNumber(db,buf)) 
   printf("%s\n",buf); 

 db=10000008.0987; 
 printf("%lf\n",db); 
 if(ChangeNumber(db,buf)) 
   printf("%s\n",buf); 

 db=10200408.09007; 
 printf("%lf\n",db); 
 if(ChangeNumber(db,buf)) 
   printf("%s\n",buf); 

 db=10020400.007; 
 printf("%lf\n",db); 
 if(ChangeNumber(db,buf)) 
   printf("%s\n",buf); 
} 

void ConvertN(int n,char* &p,bool IsSequece/*=true*/) 
/*���庯��ConvertN
 "С��λת��" ������n(0<=n<=9)ת�������ĺ����p,IsSequece���ƴ��˳�� */
{ 
 if(n<0 || n>9)   
 { 
   printf("Error:���鳬��!\n");   /*����������޾��������*/
   exit(0);    /*��������*/
 } 

 char num[]="��Ҽ��������½��ƾ�"; 
 if(IsSequece)                         /*���IsSequeceΪ���˳����*/
 { 
   *p++=num[2*n]; 			/*��Ϊ������˫�ֽڵ����ԣ��ڰѰ���������ת��ʱ����0��Ӧ������˫�ֽڣ�ռ�����0��1��λ�ã��������Դ�����*/
   *p++=num[2*n+1]; 
 } 
 else                                  /*���IsSequeceΪ�Ǽ�������*/
 { 
   *p++=num[2*n+1]; 
   *p++=num[2*n]; 
 } 
} 

bool ConvertSegment(int number,int n,char* &p,bool IsLastZiero) 
/*���庯�� ConvertSegment
 "����λת��" ��numberת�������ĺ�������ַ�ָ��p 
numberΪĳ���������ֵĵ�n��(�ɵ�λ����λ�Ӹ�λ��ʼÿ4λΪһ��,n��0��ʼ) */
{ 
 char num1[]="  ʰ��Ǫ"; 
 char num2[]="��������"; 

 if(number==0) 
 { 
   if(n==0) 
   { 
     *p++=num2[2*n+1]; 
     *p++=num2[2*n]; 
   } 
   return IsLastZiero; 
 } 

 if(IsLastZiero) 
 { 
   ConvertN(0,p,false); 
 } 

 *p++=num2[2*n+1]; 
 *p++=num2[2*n]; 

 bool flag=true;                      /* ǰ���Ƿ����� */
 for(int i=0;number!=0 && i<4;i++) 
 { 
   int m; 
   m=number%10; 
   if(m==0 && !flag) 
   { 
     flag=true; 
     ConvertN(0,p,false); 
   } 
   else if(m!=0) 
   { 
     flag=false; 
     if(i==0) 
     { 
       ConvertN(m,p,false); 
     } 
     else 
     { 
       *p++=num1[2*i+1]; 
       *p++=num1[2*i]; 
       ConvertN(m,p,false); 
     } 
   } 
   number/=10; 
 } 

 if(i>=4) 
   return false; 
 else 
   return true; 

} 

bool ChangeNumber(double dbNumber,char* lpszvalues)  
{ 
 /*���庯�� ChangeNumber	
   �����������8λ��С���������6λ */
 if(dbNumber<0.0000001 && -dbNumber<0.0000001)                    //��λ̫С 
 { 
   strcmp(lpszvalues,"��"); 
   return true; 
 } 
 if(dbNumber>100000000L || -dbNumber>100000000L)                  //��λ̫�� 
   return false; 

 /* ��ʼ���� */
 char buf1[50],buf2[50],*p1=buf1,*p2=buf2; /* ������������ֺ�С�����ֻ����� */
 /* p1������ָ�� p2��С��ָ�� */
 double c=dbNumber; 
 c=c>0?c:-c; 
 /*ȡ�ô�ʵ�����������ֺ�С�����ֲ�������,long�ĳ���ֱ���������������ֵĳ���, 
   ���ǹ���������������ֱ������ʵ������,�������԰쵽! 
   ������ʵ�����ȵ�Ӱ��,��ʱ�ᵼ��С�����ֵĻ���! 
   �������ָ��!!! 
 */ 
 unsigned long a=(unsigned long)c;         /*��������*/
 double b=c-a;                             /*С������*/
 /*printf("%lu\n",a); 
   printf("%lf\n",b); 
   printf("%lf\n",c);*/
  
 /* ����С������ */
 for(int i=0;i<6;i++) 
 { 
   b*=10;  		/*��С�����λ��ǰ��һλȡ������*/
   int n=int(b); 	
   ConvertN(n,p2);    /*ת�����ַ���ֵ*/
   b-=n;      /*��ȥ�������ֵ���ȡ����һλС��,�����Ϊ����*/
 } 
 *p2='\0';

 /* ������������ */
 int count=0; 
 bool flag=false; 
 while(a!=0) 
 { 
   int buf=a%10000; 
   flag=ConvertSegment(buf,count++,p1,flag); 
   a/=10000; 
 } 

 /*�Ƿ��и��� */
 char *p=lpszvalues; 
 if(dbNumber<0) 
 { 
   strcpy(p,"��"); 
   p+=2; 
 } 

 /* �����������ֺ�С������ */
 p1--; 
 while(p1>=buf1) 
   *p++=*p1--; 
 *p='\0'; 
 strcat(lpszvalues,buf2); 

 return true; 
} 
