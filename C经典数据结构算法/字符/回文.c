/*���ģ����ľ�������������һ�����ַ�����
���磺"radar","able was i ere i saw elba"��"a man a plan a canal panama"(������Կո񣩡�
���д�ݹ麯��testPalindrome,�������е��ַ���Ϊ����ʱ����true�����򷵻�false��
���������ַ����еĿո�ͱ����š� */

#include <stdio.h>
/*	  �ַ���   һ����  �ܸ���*/
int charf(char d[],int k,  int i)
{
  if(d[k]==d[i-k]&&k==0)
    return(1);
  else if(d[k]==d[i-k])
    charf(d,k-1,i);    /*�ݹ����*/
  else
    return(0);
}

main()
{
  int i=0,n=0;
  char a,b[20];
  while ((a=getchar())!='\n')
    {
      b[i]=a;
      i++;
    }
  if(i%2==0)
    n=charf(b,(i/2),i-1);
  else
    n=charf(b,(i/2-1),i-1);
  if(n==0) 
    printf("���ǻ���"); 
  else
    printf("�ǻ���");
  getch();
}