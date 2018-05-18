/*
* File: shortest.c
* Description: �������������·�� Dijkstra �㷨
*              Shortest Path Dijkstra Algorithm
* Created: 2001/11/25
* Author: Justin Hou [mailto:justin_hou@hotmail.com]
*/

#include <stdio.h>
#define true  1
#define false 0
#define I  9999                                /* �����        */
#define N  20                                  /* ���ж������Ŀ */

int cost[N][N] = {
    {0,3,I,I,I,1,I,I,I,I,I,I,I,I,I,I,I,I,I,I},
    {3,0,5,I,I,I,6,I,I,I,I,I,I,I,I,I,I,I,I,I},
    {I,5,0,4,I,I,I,1,I,I,I,I,I,I,I,I,I,I,I,I},
    {I,I,4,0,2,I,I,I,6,I,I,I,I,I,I,I,I,I,I,I},
    {I,I,I,2,0,I,I,I,I,7,I,I,I,I,I,I,I,I,I,I},
    {1,I,I,I,I,0,1,I,I,I,2,I,I,I,I,I,I,I,I,I},
    {I,6,I,I,I,1,0,6,I,I,I,7,I,I,I,I,I,I,I,I},
    {I,I,1,I,I,I,6,0,2,I,I,I,3,I,I,I,I,I,I,I},
    {I,I,I,6,I,I,I,2,0,8,I,I,I,4,I,I,I,I,I,I},
    {I,I,I,I,7,I,I,I,8,0,I,I,I,I,5,I,I,I,I,I},
    {I,I,I,I,I,2,I,I,I,I,0,4,I,I,I,3,I,I,I,I},
    {I,I,I,I,I,I,7,I,I,I,4,0,3,I,I,I,4,I,I,I},
    {I,I,I,I,I,I,I,3,I,I,I,3,0,3,I,I,I,5,I,I},
    {I,I,I,I,I,I,I,I,4,I,I,I,3,0,7,I,I,I,2,I},
    {I,I,I,I,I,I,I,I,I,5,I,I,I,7,0,I,I,I,I,3},
    {I,I,I,I,I,I,I,I,I,I,3,I,I,I,I,0,5,I,I,I},
    {I,I,I,I,I,I,I,I,I,I,I,4,I,I,I,5,0,8,I,I},
    {I,I,I,I,I,I,I,I,I,I,I,I,5,I,I,I,8,0,6,I},
    {I,I,I,I,I,I,I,I,I,I,I,I,I,2,I,I,I,6,0,4},
    {I,I,I,I,I,I,I,I,I,I,I,I,I,I,3,I,I,I,4,0}
};
int dist[N];                                          /* �洢��ǰ���·������ */
int v0 = 'A' - 65;                                    /* ��ʼ���� A          */

void main()
{
    int final[N], i, v, w, min;

    /* ��ʼ�����·���������ݣ��������ݶ������������� */
    for (v = 0; v < N; v++) {
    final[v] = false;
        dist[v] = cost[v0][v];
    }

    /* ����ѡv0��v0�ľ���һ����̣��������� */
    final[v0] = true;

    /* Ѱ������ N-1 ����� */
    for (i = 0; i < N-1; i++) {
        min = I;                                      /* ��ʼ��̳��������  */
        
        /* Ѱ����̵ı� */
        for (w = 0; w < N; w++) {
            if (!final[w] && dist[w] < min) {
                min = dist[w];
                v = w;
        }
        }
        final[v] = true;                              /* �����±�          */

        for (w = 0; w < N; w++) {                      /* ���� dist[] ����  */
            if (!final[w] && dist[v] + cost[v][w] < dist[w]) {
                dist[w] = dist[v] + cost[v][w];
            }
        }
    }

    for (i = 0; i < N; i++) {                          /* ��ʾ��������      */
        printf("%c->%c: %2d\t", v0 + 65, i + 65, dist[i]);
    }
}