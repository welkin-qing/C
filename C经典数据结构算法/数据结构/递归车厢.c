/**********�ݹ����Ϊ�ǵݹ���ʵ�� ����********/
#include<stdio.h> 

#define MAX 4 

int stack[MAX],p=-1; 

struct 
{ 
  int num; 
  int sign; 
}train[MAX]; 

void sub() 
{ 
  int inc; 
  if(p==MAX-1) 
    { 
      for(inc=0;inc<=p;inc++)
        printf("%3d",stack[inc]); 
      printf("\n"); 
    }
  else 
    {  
      for(inc=0;inc<MAX;inc++) 
        if(train[inc].sign==0) 
          { 
            train[inc].sign=1; 
            stack[++p]=train[inc].num; /*��ջ*/
            sub();                     /*�ݹ�*/
            train[inc].sign=0; 
            p--;                       /*��ջ*/ 
          } 
    } 
} 

main() 
{ 
  int temp; 
  for(temp=0;temp<MAX;temp++) 
    { 
      train[temp].num=temp+1; 
      train[temp].sign=0; 
    } 
  printf("The result is:\n"); 
  sub(); 
} 

