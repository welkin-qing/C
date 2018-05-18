/*
* File:        longest.c
* Desciption:  ��̬�滮�㷨����������·�ߺ����·��
* Created:    2001/12/2
* Author:      Justin Hou [mailto:justin_hou@hotmail.com]
*
*/
#include <stdio.h>
#define  N  7                                              /* ������Ŀ    */
#define  I  999                                            /* ��ʾ�����  */

int graph[N][N] = {                                        /* ͼ���ڽӾ��� */
        {I, 4, 5, 8, I, I, I},
        {I, I, I, 6, 6, I, I},
        {I, I, I, 5, I, 7, I},
        {I, I, I, I, 8, 9, 9},
        {I, I, I, I, I, I, 5},
        {I, I, I, I, I, I, 4},
        {I, I, I, I, I, I, I}
};
int List[N];                                                /* ����������� */

int TopologicalOrder();                                    /* ���������� */

void main()                                                /* �� �� ��    */
{
        int i, j, k, l;
        int ee[N], el[N];                                  /* ���̾��� */
        int path_e[N][N], path_l[N][N], n_e[N], n_l[N];    /* ��¼·������ */

        /* ��ʼ������ */
        for (i = 0; i < N; i++) {
                n_e[i] = 0;                      /* �� i �����·�ߵĽ���� */
                n_l[i] = 0;                      /* �� i ���·�ߵĽ���� */
                ee[i] = I;
                el[i] = 0;
        }
        ee[0] = el[0] = 0;                                  /* ��ʼ��ͷ��� */
        path_e[0][0] = 0;
        path_l[0][0] = 0;
        n_e[0] = 1;
        n_l[0] = 1;

        /* �������� */
        if (!TopologicalOrder())
                return;

        /* ������������,���ö�̬�滮��������·�������·�� */
        for (i = 0; i < N; i++) {

                /* ��ȡ�������е�Ԫ�� */
                k = List[i];
                /* ��������ָ�򶥵���������� */
                for (j = 0; j < N; j++) {

                        /* Ѱ��ָ��Ķ��� */
                        if (graph[k][j] != I) {

                                /* �����·������ */
                                if (graph[k][j] + ee[k] < ee[j]) {

                                        /* �������·������ */
                                        ee[j] = graph[k][j] + ee[k];
                                        /* �������·�� */
                                        for (l = 0; l < n_e[k]; l++) {
                                                path_e[j][l] = path_e[k][l];
                                        }
                                        path_e[j][l] = j;
                                        n_e[j] = l + 1;
                                }

                                /* �����·������ */
                                if (graph[k][j] + el[k] > el[j]) {

                                        /* �����·������ */
                                        el[j] = graph[k][j] + el[k];
                                        /* �����·�� */
                                        for (l = 0; l < n_l[k]; l++) {
                                                path_l[j][l] = path_l[k][l];
                                        }
                                        path_l[j][l] = j;
                                        n_l[j] = l + 1;
                                }
                        }
                }
        }

        /* ����������Ļ */
        for (i = 0; i < N; i++) {
                printf("shortest(%d): %2d    Path: ", i + 1, ee[i]);
                for (j = 0; j < n_e[i]; j++) {
                        printf("%d ", path_e[i][j] + 1);
                }
                printf("\n");        
                printf("longest (%d): %2d    Path: ", i + 1, el[i]);
                for (j = 0; j < n_l[i]; j++) {
                        printf("%d ", path_l[i][j] + 1);
                }
                printf("\n");
        }
}

int TopologicalOrder()
{
        int i, j, top, count;
        int indegree[N], Stack[N];

        top = 0;                                            /* ջ����־    */
        for (i = 0; i < N; i++) {
                indegree[i] = 0;                            /* ��ʼ�����  */
                for (j = 0; j < N; j++) {
                        if (graph[j][i] != I) {            /* ����ͨ      */
                                indegree[i]++;              /* �������1    */
                        }
                }
                if (!indegree[i]){                          /* �����Ϊ��  */
                        Stack[top++] = i;                  /* ��ջ        */
                }
        }
        count = 0;                                          /* ���������  */
        while (top != 0) {
                i = Stack[--top];
                List[count++] = i;
                for (j = 0; j < N; j++) {
                        if (graph[i][j] != I) {            /* ����ͨ      */
                                if (!(--indegree[j])) {    /* �������Ϊ�� */
                                        Stack[top++] = j;  /* ��ջ        */
                                }
                        }
                }/* for */
        }/* while */

        return (count < N) ? 0 : 1;
}
