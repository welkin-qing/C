#include "stdio.h" 
float z[4][4],*y=z;   /*����һ��ȫ�ֶ�ά�����������N-1������ʽ,��ΪA�İ���������|A|ʱ�����С������˶����float����int*/ 

int js(int *p,int n)               /*��������ʽ�ĺ���*/ 
{int k=0,i,s2=0,s1=0,j,s,t; 
printf("\n"); 
for(j=0;j<n;j++) 
  { k=j;t=1; 
   for(i=1;i<=n;i++) 
{ t=t*p[k]; 
 if ((k+1)%n==0) k=k+1; 
 else  k=k+n+1; 
} 
   s1=s1+t; 
  } 
for(j=0;j<n;j++) 
   { k=j;t=1; 
     for(i=1;i<=n;i++) 
{ t=t*p[k]; 
  if (k%n==0) k=k+(2*n-1); 
  else k=k+(n-1); 
} 
    s2=s2+t; 
   } 
s=s1-s2; 
return s; 
} 

void n_1(int b[][4])      /*�ѳ���i��j�к��N-1�׾����ÿ��Ԫ�ظ���һά����d[]�ĺ���*/ 
{int i,j,e,f,l,m,d[9],*q='\0'; 
int js(int *p,int n); 
printf("\n"); 
for(i=0;i<4;i++) 
   {l=i; 
    for(j=0;j<4;j++) 
{ m=j;q=d; 
 for (e=0;e<4;e++) 
    { if(e==l) continue; 
      for(f=0;f<4;f++) 
 { if(f==m) continue; 
   *q=b[e][f]; 
   q++; 
 } 
    } 
                        /*ÿ�õ�һ��һά����d[]��ֵ�������JS()����,�õ�����i��j�к��N-1�׾��������ʽ��ֵ,Ҳ��������ʽM[j]*/ 
          *(y++)=js(d,3); /*��������ʽ��ֵ�����ȫ�ֶ�ά����z[]��*/ 
} 
   } 
} 


prt(int *p,int n) /*�����ӡ����*/ 
{int i; 
for(i=0;i<n*n;i++) 
    {if(i%n==0) printf("\n"); 
     printf("%4d",p); 
    } 
} 

main() 
{int a[4][4]={1,2,3,4,5,6,7,8,9,9,11,12,13,14,15,16}; 
int m=4,r,i,j,ch; 
 
printf("The old juzhen is:\n"); 
prt(*a,m); 
r=js(*a,m); 
printf("\nThe old juzhen hanglieshi is:|A|==%d",r); 
printf("\nPress Enter continue......"); /*������Ļ*/ 
ch=getchar(); 
if (r==0) printf("Because |A|==0,the juzhen have no nijuzhen!"); 
else 
    {n_1(a);  /*����n_1()����*/ 

     for(i=0;i<m;i++)     /*���������ʽ*/ 
          for(j=0;j<m;j++) 
              if((i+j)%2!=0 && z[i][j]!=0) z[i][j]=-z[i][j]; 
     printf("Because |A|!=0,the juzhen have nijuzhen!\n"); 
     printf("The bansuijuzhen A* is:\n");  /*��ӡ�������A* ,i,j�Ե�����ת��*/ 
     for(i=0;i<m;i++) 
         {for(j=0;j<m;j++) 
               if ((i+j)%2==0) printf("%4.0f\t",z[j][i]); 
               else 
           printf("%4.0f\t",z[i][j]); 
          printf("\n"); 
         } 
     printf("\nThe nijuzhen is:(*A)/|A|\n"); 
     for(i=0;i<m;i++)    /*��ӡA�������*/ 
          {for(j=0;j<m;j++) 
if ((i+j)%2==0)  printf("%.3f\t",z[i][j]/r); 
               else 
    printf("%.3f\t",z[j][i]/r); 
           printf("\n"); 
          } 
    } 


}