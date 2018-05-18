/*
* File: queen.c
* Description: �� N �ʺ���������㷨
* Created: 2001/11/12
* Author: Justin Hou [mailto:justin_hou@hotmail.com]
*/
#include <stdio.h>

#define  DelayTime  20000                /* ��ʾ���ʱ��      */
#define  TopX      10                    /* �������Ͻ� x ����  */
#define  TopY      5                    /* �������Ͻ� y ����  */

int N;                                    /* �ʺ�����          */

int a[8], b[15], c[15];
/*
* a[col-1] ��¼�� col �����޻ʺ�, 1 ��ʾ�С�
* b[row+col-2] ��¼���������� row+col-1 ��б��Ϊ 1 ���������޻ʺ�
* c[row-col+7] ��¼���������� row-col+8 ��б��Ϊ -1 ���������޻ʺ�
*/
int Num = 0;
int row;  
void BackTrack (int row)
{
    int col;                                        /* �ֲ����� */
    for (col=1; col<=N; col++)
    {
        if (a[col-1] + b[row+col-2] + c[row-col+N-1] == 0)
        {
            a[col-1] = 1;                          /* �������� */
            b[row+col-2] = 1;
            c[row-col+N-1] = 1;

            gotoxy(col*2 + TopX, row + TopY);      /* ���ʺ�  */
            putch('Q');

            if (row < N)
            {
                BackTrack (row + 1);
            }
            else
            {
                Num++;                              /* �ݹ��յ� */
                gotoxy(40, 9);
                printf("Num: %d ", Num);
                delay(DelayTime);
            }

            a[col-1] = 0;                          /* ������� */
            b[row+col-2] = 0;
            c[row-col+N-1] = 0;

            gotoxy(col*2 + TopX, row + TopY);      /* ���ͼ�� */
putch('.');

        }/* end if */
    }/* end for */
}/* end function BackTrack */

void main()
{
    int i, j;
    clrscr();

    gotoxy(1, 10);                            /* Ҫ���û�����ʺ����� */
    printf("Input the number of queen: ");
    while(N <= 0 || N > 14)
    {
        scanf("%d", &N);
        if(N > 14) printf("Two huge number, input again:");
        if(N <= 0) printf("Can's smaller than 1, again:");
}

clrscr();

    for(i=1; i<=N; i++)                        /*  ������(Chessboard) */
    {
        for(j=1; j<=N; j++)
        {
            gotoxy(i*2 + TopX, j + TopY);
            putch('.');
        }
    }

    BackTrack(1);                                    /* ��ʼ�����㷨 */

    gotoxy(12, 17);                                  /* ��ʾ����� */
    printf ("There are %d kinds of solution.\n", Num);

    getch();
}