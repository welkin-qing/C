#include <stdio.h>  

void main()
{
   char strg[40],*there,one,two;
   int *pt,list[100],index;

   strcpy(strg,"This is a character string.");

   one = strg[0];                    /* one �� two����ͬ�� */
   two = *strg;
   printf("��һ������� %c %c\n",one,two);

   one = strg[8];                   
   two = *(strg+8);
   printf("�ڶ�������� %c %c\n",one,two);

   there = strg+10;           /* strg+10 ��ͬ�� strg[10] */
   printf("����������� %c\n",strg[10]);
   printf("����������� %c\n",*there);

   for (index = 0;index < 100;index++)
      list[index] = index + 100;
   pt = list + 27;
   printf("����������� %d\n",list[27]);
   printf("����������� %d\n",*pt);
}
