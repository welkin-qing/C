/*�������ܶ�ȡϵͳ��������,�鿴�������.����,�����Mouse is OK,
��֮�����No mouse.*/

/********************read mouse***********************/

#include<stdio.h>/*for function of printf()*/
#include<stdlib.h>/*for function of exit()*/
#include<string.h>/*for function of strcmp()*/


void loadmous(void); /*�鿴��������Ӻ���*/
/*��������ʼ*/
main()
{
    loadmous();
    return 0;
}
/*�Ӻ���*/
void loadmous()
{
    char *p;
    if((p=getenv("MOUSE"))!=NULL){/*����getenv()����,��ȡϵͳ��������*/
        if(!strcmp(p,"YES"))/*�ж��������*/
        printf("Mouse is OK\n");
    }
    else{
	printf("\n No mouse");
	getch();
	exit(1);/*�����˳�����*/
    }
}