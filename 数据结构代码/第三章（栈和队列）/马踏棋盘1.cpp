#include<stdio.h> 
#include<math.h>
#define X 8
#define Y 8
int chess[X][Y];
//找到基于(x,y)位置的下一个可走的位置?
int next(int *x,int *y,int step){
switch(step){
case 0:
if( *y+2<=Y-1 && *x-1>=0 && chess[*x-1][*y+2] == 0 ){
*x-=1;
*y+=2;
return 1;
}
break;
case 1:
if( *y+2<=Y-1 && *x+1<=X-1 && chess[*x+1][*y+2]==0 ){
*x+=1;
*y+=2;
return 1;
}
break;
case 2:
if( *y+1<=Y-1 && *x+2<=X-1 && chess[*x+2][*y+1]==0){
*y+=1;
*x+=2;
return 1;
}
break;
case 3:
if( *y-1>=0 && *x+2<=X-1 && chess[*x+2][*y-1]==0){
*y-=1;
*x+=2;
return 1;
}
break;
case 4:
if( *y-2>=0 && *x+1<=X-1 && chess[*x+1][*y-2]==0){
*y-=2;
*x+=1;
return 1;
}
break;
case 5:
if( *y-2>=0&&*x-1>=0&& chess[*x-1][*y-2]==0){
*y-=2;
*x-=1;
return 1;
}
break;
case 6:
if( *y-1>=0&&*x-2>=0&&chess[*x-2][*y-1]==0){
*y-=1;
*x-=2;
return 1;
}
break;
case 7:
if( *y+1<=Y-1&&*x-2>=0&&chess[*x-2][*y+1]==0){
*y+=1;
*x-=2;
return 1;
}
break;
default:
break;
}
return 0;
}
//打印输出棋盘?
void print()
{
    int i,j;
    for(i=0;i<X;i++)
    for(j=0;j<Y;j++)
  {
   printf("%2d ",chess[i][j]);
  }
   printf("\n");
}

int horse(int x,int y,int tag){
int x1=x;int y1=y;
int flag =0,count=0;
chess[x][y]=tag;
if(tag==X*Y){
print();
return 1;
}
flag = next(&x1,&y1,count);
while(!flag && count<=7){
count++;
flag=next(&x1,&y1,count);
}
while(flag){
if(horse(x1,y1,tag+1)){
return 1;
}
x1 = x;
y1 = y;
count++;
flag=next(&x1,&y1,count);
while(!flag && count<=7){
count++;
flag=next(&x1,&y1,count);
}
}
if(!flag){
chess[x][y]=0;//回溯?
}
return 0;
}
int main(){
int i,j;
for(i=0;i<X;i++)
for(j=0;j<Y;j++)
chess[i][j]=0;
}


clock_t begin,end;
begin=clock();
if(!horse(2,0,1)){
printf("马踏棋盘失败！\n");
}
end = clock();
printf("共计用时:%lf\n",(double)(end-begin)/CLOCKS_PER_SEC);

return 0;
} 



