#include<stdio.h>
int main(void)
{
  int x = 32;
  unsigned int y = 23;

  x<<=1; //�� (signed int)x<<=2; ��ͬ����Ϊ����������signed
  //(unsigned int)x<<=2;
  //x>>=2;
  //(unsigned int)x>>=2;

  (signed int)y<<=2;
  y<<=2;
  (signed int)y>>=2;
  y>>=2;
  printf("%d %d ",x,y);
  return x+y;
}