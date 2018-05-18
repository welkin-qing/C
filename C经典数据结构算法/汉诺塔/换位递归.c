#include <stdio.h>

void move(char x,char y) 
{printf("%c-->%c\n",x,y);} 
void hanoi (int n,char one ,char two,char three) 
{
if(n==1) move (one ,three); 
else 
{
hanoi (n-1,one,three,two); 
move(one,three); 
hanoi(n-1,two,one,three); 
} 
} 
main() 
{int m; 
printf("input the number of diskes:"); 
scanf("%d",&m); 
printf("the step to moving %3d diskes:\n",m); 
hanoi(m,'A','B','C'); 
} 
/*����������£� 
input the number of diskes:3 �س� 
the step to moving 3 diskes: 
A-->C 
A-->B 
C-->B 
A-->C 
B-->A 
B-->C 
A-->C 

����˵hanoi(n-1,one,three,two);�ǰѡ�one���ϵ�n-1������two�����ƣ�����move(one,three);Ȼ����hanoi(n-1,two,one,three)���ѡ�two���ϵ�n-1������three�����ƣ�
           |h(2,1,3,2)|h(1,1,2,3)=>move(1,3)   <-----1------ 
           |          |  move(1,2)             <-----2------ 
           |          |h(1,3,1,2)=>move(3,2)   <-----3------ 
           |move(1,3)                          <-----4------ 
           | 
h(3,1,2,3) |          |h(1,2,3,1)=>move(2,1)   <-----5------ 
           |h(2,2,1,3)|move(2,3)               <-----6------- 
           |          |h(1,1,2,3)=>move(1,3)       <-----7------ 
           | 
*/ 

