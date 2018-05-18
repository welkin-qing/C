/*
* File:        multi.c
* Description:  ����˷���̬�滮
* Created:      10:20 2001-12-3
* Author:      Justin Hou [mailto:justin_hou@hotmail.com]
*
*/

#include <stdio.h>
#define  N  7

int middle[N][N];

void Show(int, int);

void main()
{
        int i, j, l, k;
        unsigned long m[N+1][N+1], min;
        int r[N+1] = {10, 20, 50, 1, 100, 4, 20, 2};                            /* ����ά�� */

        /* ��ʼ�� */
        for (i = 1; i <= N; i++) {
                m[i][i] = 0;
        }
        /* ÿ��������һ */
        for (l = 1; l < N; l++) {

                /* ���ڲ�ֵΪ l ������Ԫ�� */
                for (i = 1; i <= N - l; i++) {
                        j = i + l; 

                        /* ������С��Ϸ�ʽ */
                        min = m[i][i] + m[i+1][j] + r[i-1] * r[i] * r[j];
                        middle[i][j] = i;
                        for (k = i + 1; k < j; k++) {
                                if (min > m[i][k] + m[k+1][j] + r[i-1] * r[k] * r[j]) {
                                        min = m[i][k] + m[k+1][j] + r[i-1] * r[k] * r[j];
                                        middle[i][j] = k;
                                }
                        }
                        m[i][j] = min;
                }
        }
        printf("M = ");
        Show(1, N);
        printf("\nMultiply Count: %d\n", m[1][N]);
}
                        
void Show(int i, int j)
{
        int k, m;

        if (i == j){
                printf("M%d", i);                              /* �����һ���Ǿ������  */
        }
        else {
                m = middle[i][j];                              /* �ָ����������          */
                if (i != m) printf("(");                        /* �����һ����ʾ�Ĳ��Ǿ��� */
                Show(i, m);                                    /* ��ʾ��ߵ�����          */
                if (i != m) printf(")");                        /* �����һ����ʾ�Ĳ��Ǿ��� */
                printf(" x ");                                  /* ��ӡ�˷�����            */
                if (m+1 != j) printf("(");                      /* �����һ����ʾ�Ĳ��Ǿ��� */
                Show(m + 1, j);                                /* ��ʾ�ұߵ�����          */
                if (m+1 != j) printf(")");                      /* �����һ����ʾ�Ĳ��Ǿ��� */
        }

}