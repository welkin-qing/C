/*�Ҳ�֪�������������ʲ����ʣ������Լ��ڰ������˸ɻ���
�Ҳ����ܸ���˵�ú�ϸ��ѧϰ���Ķ������Լ��ģ��ѵ����Լ�
Ҳ���������𣿺ú�Ŭ����*/

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct f                             //���ݽṹ
{
	double data;
	struct f *next;
};

main() 
{ 
	int n;
	scanf("%d",&n);
	fun(n);
} 

fun(n)
{
	double y=0.00,x=1.00;           //������˫����ʵ������������ɸ��������
	struct f *head,*cthis,*a;
	int number,i,j=0;
	do{	
		a=(struct f*)malloc(sizeof(struct f));
		if(head==NULL)
			head=a;
		else
		{
			cthis=head;
			cthis=cthis->next;
		}
		cthis=a;
		cthis->data=j;        //���ﶨ��洦�ڸ��������������
		                      //�������(int)rand()�����������j
		number=cthis->data;
		for(i=0;i<j;i++)
			x=x*n;
		y+=number*x;       
		j++;
	}while(j<n);
	printf("%.0lf",y);
}