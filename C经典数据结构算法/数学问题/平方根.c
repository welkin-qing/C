#define Epsilon 1.0E-6  /*���ƽ�ľ���*/ 
#include <stdio.h>
#include <math.h> 

main() 
{
	float num,pre,this; 
 	do 
	{   
 		scanf("%f",&num);/*����Ҫ��ƽ��������*/ 
	}while(num<0); 
	if (num==0) 
 		printf("the root is 0"); 
	else 
	{
		this=1; 
  		do
  		{ 
  			pre=this;
   			this=(pre+num/pre)/2; 
		}while(fabs(pre-this)>Epsilon);/*�ý�ľ��ȣ�����ѭ��������fabs()�������ֵ�ĺ���*/ 
	} 
	printf("the root is %f",this); 
} 