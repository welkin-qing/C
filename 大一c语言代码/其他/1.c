/*#include<stdio.h>
#include<math.h>
#define N 20
void create(int a[][20],int w,int max);
main()
{
     int w,m,n,i,j,max,mina,y2,y1,x2,x1;
     int b[N][N];
     scanf("%d%d%d",&w,&m,&n);
	 max=(m>n)?  m:n; 
     create(b,w,max);
     for(i=0;i<=max/w;)
	  {
	       for(j=0;j<w;)
		   {
		        if(b[i][j]!=m)
					j++;
				else if(b[i][j]==m)
					break;
		   }
		   if(b[i][j]==m) 
		   {
			   
			   break;
		   }
		   else i++;
	  }
     x1=i;
	 y1=j;
     for(i=0;i<=max/w;)
	  {
	       for(j=0;j<w;)
		   {
		        if(b[i][j]!=n)
					j++;
				else if(b[i][j]==n)
				{
					break;
				}
		   }
		   if(b[i][j]==n)   break;
		   else i++;
	  }
     x2=i;
	 y2=j;
	 mina=abs(x2-x1)+abs(y2-y1);
	 printf("%d",mina);
}
void create(int a[][20],int w,int max)
{
     int i=0,j=0,count=1;
	 while(j<=max/w)
	 {
		for(i=0;i<w;i++)
		{
		 a[j][i]=count;
		 count++;
		}
		j++;
		for(i=w-1;i>=0;i--)
		{
		     a[j][i]=count;
			 count++;
		}
		j++;
	 }
}*/
#include "stdio.h" 
 int main() 
 { 
 int num=0;
 int a[100]; 
 int i=0; 
 int m=0;
 int yushu; 
 char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
 printf("请输入一个十进制整数："); 
scanf("%d",&num); 
 while(num>0) 
 { 
 yushu=num%16; 
 a[i++]=yushu; 
 num=num/16; 

 } 
 printf("转化为十六进制的数为："); 
 for(i=i-1;i>=0;i--)//倒序输出 
 { 
m=a[i];
 printf("%c",hex[m]); 

 } 
 printf("\n"); 
 }

