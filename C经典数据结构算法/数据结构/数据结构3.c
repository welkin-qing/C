#include <stdio.h>

void main()
{
   struct  childrec/*����ṹ��*/
   {
     char initial;  /* ��������ĸ   */
     int age;       /* ����         */
     int grade;     /* ���Գɼ�     */
   }boy,girl;

   boy.initial = 'R';
   boy.age = 15;
   boy.grade = 75;

   girl.age = boy.age - 1;  /* Ů�����к�Сһ�� */
   girl.grade = 82;
   girl.initial = 'H';

   printf(" girl:  %c is %d years old and got a grade of %d\n",
            girl.initial, girl.age, girl.grade);

   printf("  boy:  %c is %d years old and got a grade of %d\n",
           boy.initial, boy.age, boy.grade);
}
