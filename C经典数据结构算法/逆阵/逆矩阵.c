#define N 5      /*[ע]���޸�6Ϊ����Ҫ�ľ������*/ 
#include "stdio.h" 
#include "conio.h" 


/*js()�������ڼ�������ʽ,ͨ���ݹ��㷨ʵ��*/ 
int js(s,n) 
int s[][N],n; 
{int z,j,k,r,total=0; 
int b[N][N];/*b[N][N]���ڴ�ţ��ھ���s[N][N]��Ԫ��s[0]������ʽ*/ 
if(n>2) {for(z=0;z<n;z++) 
{for(j=0;j<n-1;j++) 
for(k=0;k<n-1;k++) 
if(k>=z) b[j][k]=s[j+1][k+1]; 
else b[j][k]=s[j+1][k]; 
if(z%2==0) r=s[0][z]*js(b,n-1);  /*�ݹ����*/ 
else  r=(-1)*s[0][z]*js(b,n-1); 
total=total+r; 
} 
} 
else if(n==2) total=s[0][0]*s[1][1]-s[0][1]*s[1][0]; 
return total; 
} 


/*n_1()����������ԭ�����Ԫ�ض�Ӧ������ʽ�����������b[N][N]�У�����Ϊfloat��*/ 
void n_1(s,b,n) 
int s[][N],n; 
float b[][N]; 
{int z,j,k,l,m,g,a[N][N]; 
for(z=0;z<n;z++) 
   {l=z; 
    for(j=0;j<n;j++) 
{ m=j; 
 for (k=0;k<n-1;k++) 
      for(g=0;g<n-1;g++) 
 { if(g>=m&&k<l) a[k][g]=s[k][g+1]; 
   else if(k>=l&&g<m)  a[k][g]=s[k+1][g]; 
   else if(k>=l&&g>=m) a[k][g]=s[k+1][g+1]; 
   else a[k][g]=s[k][g]; 
 } 
         b[z][j]=js(a,n-1); 
} 
   } 
} 



main() 
{int a[N][N]; 
float b[N][N]; 
int r,z,j; 
float temp; 
//clrscr(); 
printf("Input original data:\n"); 
for(z=0;z<N;z++)              /*��������Ҫ�����ݣ�Ϊ��������*/ 
    for(j=0;j<N;j++) 
scanf("%d",&a[z][j]); 
printf("\nPress Enter continue......"); 
getchar(); 
//gotoxy(1,1); 
printf("The original matrix is:\n"); 
for(z=0;z<N;z++)/*��ӡԭ����*/ 
    {for(j=0;j<N;j++) 
 printf("%5d",a[z][j]); 
     printf("\n"); 
    } 
r=js(a,N);                     /*����js()��������ԭ���������ʽֵ*/ 
printf("\nThe original matrix hanglieshi is:|A|==%d\n",r);     
if (r==0) printf("Because |A|==0,the original matrix have no nijuzhen!");  /*�ж�����:��|A|==0����ԭ����������󣬷�֮����������*/ 
else 
    {n_1(a,b,N);                                       /*����n_1()�������õ�ԭ�����Ԫ�ض�Ӧ��"����ʽ",���������b[N][N]��*/ 
     for(z=0;z<N;z++)                                  /*���������ʽ����ʱb[N][N]�д�ŵ�Ϊԭ�����Ԫ�ض�Ӧ��"��������ʽ"*/ 
          for(j=0;j<N;j++) 
              if((z+j)%2!=0 && b[z][j]!=0) b[z][j]=-b[z][j]; 
     for(z=0;z<N;z++)        /*��b[N][N]ת��,��ʱb[N][N]�д�ŵ�Ϊԭ����İ������*/ 
  for(j=z+2;j<N;j++) 
{temp=b[z][j]; 
b[z][j]=b[j][z]; 
b[j][z]=temp; 
} 
     printf("Because |A|!=0,the original matrix have nijuzhen!\n"); 
     printf("The bansuijuzhen A* is:\n"); 
     for(z=0;z<N;z++)/* ��ӡ�������A* */ 
         {for(j=0;j<N;j++) 
              printf("%4.0f\t",b[z][j]); 
          printf("\n"); 
         } 

     for(z=0;z<N;z++)                                  /*������󣬴�ʱb[N][N]�д�ŵ���ԭ����������*/ 
          for(j=0;j<N;j++) 
b[z][j]=b[z][j]/r; 
     printf("\nThe nijuzhen is:(A*)/|A|(|A|=%d)\n",r);  /*��ӡ�����*/ 
     for(z=0;z<N;z++) 
    {for(j=0;j<N;j++) 
printf("%8.3f",b[z][j]); 
   printf("\n"); 
  } 
    } 
}
