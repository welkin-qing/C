#include <stdio.h>

void main()
{
   struct childrec  /* ����ṹ���� childrec */
   {
     char initial;  /* ��������ĸ */
     int age;       /* ����       */
     int grade;     /* ���Գɼ�   */ 
   };

   struct childrec kids[12] = /* ���� childrec �ṹ�����鲢��ʼ�� */
   {
      {'A',16, 80},
      {'B',13, 80},
      {'C',19, 84},
      {'D',19, 89},
      {'E',12, 84},
      {'F',17, 82},
      {'G',16, 90},
      {'H',16, 85},
      {'I',16, 96},
      {'J',17, 91},
      {'K',13, 72},
      {'L',14, 69}
   };

   int index;

   for (index = 0;index < 12;index++)
      printf("%c is %d years old and got a grade of %d\n",
         kids[index].initial, kids[index].age,kids[index].grade);
}
