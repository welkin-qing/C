/*
* File: tsp.c
* Description: �����ɵ�����ķ�֦�޽��㷨
*              Branch-and-bound algorithm to solve
*                  the travelling salesman problem.
* Created: 2001/11/29
* Author: Justin Hou [mailto:justin_hou@hotmail.com]
*        C.S.Department of Tongji University
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE (1)
#define FALSE (0)

#define MAX_CITIES (10)
#define INFINITY  (999)
#define I INFINITY

typedef int bool;

/* ����߽ṹ */
typedef struct _EDGE {
int head;
int tail;
} EDGE;

/* ����·���ṹ */
typedef struct _PATH {
EDGE edge[MAX_CITIES];
int  edgesNumber;
} PATH;

/* ���廨�Ѿ���ṹ */
typedef struct _MATRIX {
int distance[MAX_CITIES][MAX_CITIES];
int citiesNumber;
} MATRIX;

/* ��������� */
typedef struct _NODE {
int bound; /* ��Ӧ�ڱ����Ļ����½� */
MATRIX matrix; /* ��ǰ���Ѿ��� */
PATH path; /* �Ѿ�ѡ���ı� */
struct _NODE* left; /* ��֦ */
struct _NODE* right; /* ��֦ */
} NODE;

int Simplify(MATRIX*);
EDGE SelectBestEdge(MATRIX);
MATRIX LeftNode(MATRIX, EDGE);
MATRIX RightNode(MATRIX, EDGE, PATH);
PATH AddEdge(EDGE, PATH);
PATH BABA(NODE);
PATH MendPath(PATH, MATRIX);
int MatrixSize(MATRIX, PATH);
void ShowMatrix(MATRIX);
void ShowPath(PATH, MATRIX);

main()
{
PATH path;
NODE root = {
0, /* �����½� */
{{{I, 1, 2, 7, 5}, /* ���Ѿ��� */
  {1, I, 4, 4, 3},
  {2, 4, I, 1, 2},
  {7, 4, 1, I, 3},
  {5, 3, 2, 3, I}}, 5}, /* ������Ŀ */
{{0}, 0}, /* ��������·�� */
NULL, NULL /* ��֦����֦ */
};

/* ��Լ����������� */
root.bound += Simplify(&root.matrix);
/* ��������ѭ�� */
path = BABA(root);
ShowPath(path, root.matrix);

}

/*
* �㷨������������Branch-And-Bound Algorithm Search
*            root �ǵ�ǰ�ĸ���㣬�ѹ�Լ����������
*/
PATH BABA(NODE root)
{
int i;
static int minDist = INFINITY;
static PATH minPath;
EDGE selectedEdge;
NODE *left, *right;

puts("Current Root:\n------------");
ShowMatrix(root.matrix);
printf("Root Bound:%d\n", root.bound);

/* �����ǰ�����СΪ2��˵������������û��ѡ�����������߱ض�ֻ����һ����ϣ�
* ���ܹ��������·��������ʵ������·���Ѿ�ȷ����
*/
if (MatrixSize(root.matrix, root.path) == 2) {
if (root.bound < minDist) {
minDist = root.bound;
minPath = MendPath(root.path, root.matrix);
getch();
return (minPath);
}
}
/* �������½羡�����ԭ��ѡ��֦�� */
selectedEdge = SelectBestEdge(root.matrix);
printf("Selected Edge:(%d, %d)\n", selectedEdge.head + 1, selectedEdge.tail + 1);

/* �������ҷ�֦��� */
left = (NODE *)malloc(sizeof(NODE));
right = (NODE *)malloc(sizeof(NODE));
if (left == NULL || right == NULL) {
fprintf(stderr,"Error malloc.\n");
exit(-1);
}
/* ��ʼ�����ҷ�֦��� */
left->bound = root.bound; /* �̳и������½� */
left->matrix = LeftNode(root.matrix, selectedEdge); /* ɾ����֦�� */
left->path = root.path; /* �̳и�����·����û�������±� */
left->left = NULL;
left->right = NULL;

right->bound = root.bound;
right->matrix = RightNode(root.matrix, selectedEdge, root.path);/* ɾ�����кͻ�·�� */
right->path = AddEdge(selectedEdge, root.path); /* ������ѡ�� */
right->left = NULL;
right->right = NULL;

/* ��Լ���ҷ�֦��� */
left->bound += Simplify(&left->matrix);
right->bound += Simplify(&right->matrix);

/* ���ӵ��� */
root.left = left;
root.right = right;

/* ��ʾ�������� */
puts("Right Branch:\n------------");
ShowMatrix(right->matrix);
puts("Left Branch:\n-----------");
ShowMatrix(left->matrix);

/* ����ҽ���½�С�ڵ�ǰ��Ѵ𰸣�������֦���� */
if (right->bound < minDist) {
BABA(*right);
}
/* ������������Ϊ����֦�Ѿ������ܲ�������·�� */
else {
printf("Current minDist is %d, ", minDist);
printf("Right Branch's Bound(= %d).\n", right->bound);
printf("This branch is dead.\n");
}

/* ����ҽ���½�С�ڵ�ǰ��Ѵ𰸣�������֦���� */
if (left->bound < minDist) {
BABA(*left);
}
/* ������������Ϊ����֦�Ѿ������ܲ�������·�� */
else {
printf("Current minDist is %d, ", minDist);
printf("Left Branch's Bound(= %d).\n", left->bound);
printf("This branch is dead.\n");
}

printf("The best answer now is %d\n", minDist);
return (minPath);
}

/* �޲�·�� */
PATH MendPath(PATH path, MATRIX c)
{
int row, col;
EDGE edge;
int n = c.citiesNumber;

for (row = 0; row < n; row++) {
edge.head = row;
for (col = 0; col < n; col++) {
edge.tail = col;
if (c.distance[row][col] == 0) {
path = AddEdge(edge, path);
}
}
}
return path;

}

/* ��Լ���þ��󣬷��ط��þ���Ĺ�Լ���� */
int Simplify(MATRIX* c)
{
int row, col, min_dist, h;
int n = c->citiesNumber;

h = 0;
/* �й�Լ */
for (row = 0; row < n; row++) {
/* �ҳ�������С��Ԫ�� */
min_dist = INFINITY;
for (col = 0; col < n; col++) {
if (c->distance[row][col] < min_dist) {
min_dist = c->distance[row][col];
}
}
/* �������Ԫ�ض������˵�������Ѿ���ɾ�� */
if (min_dist == INFINITY) continue;
/* ����ÿԪ�ؼ�ȥ��СԪ�� */
for (col = 0; col < n; col++) {
if (c->distance[row][col] != INFINITY) {
c->distance[row][col] -= min_dist;
}
}
/* �����Լ���� */
h += min_dist;
}

/* �й�Լ */
for (col = 0; col < n; col++) {
/* �ҳ�������С��Ԫ�� */
min_dist = INFINITY;
for (row = 0; row < n; row++) {
if (c->distance[row][col] < min_dist) {
min_dist = c->distance[row][col];
}
}
/* �������Ԫ�ض������˵�������Ѿ���ɾ�� */
if (min_dist == INFINITY) continue;
/* ����Ԫ�ؼ�ȥ��СԪ�� */
for (row = 0; row < n; row++) {
if (c->distance[row][col] != INFINITY) {
c->distance[row][col] -= min_dist;
}
}
/* �����Լ���� */
h += min_dist;
}
return (h);
}

/* �������л���Ϊ��ı�������ʵģ�ʹ��֦�½���� */
EDGE SelectBestEdge(MATRIX c)
{
int row, col;
int n = c.citiesNumber;
int maxD;
EDGE best, edge;

/* ���ú������� */
int D(MATRIX, EDGE);

maxD = 0;
for (row = 0; row < n; row++) {
for (col = 0; col < n; col++) {
edge.head = row;
edge.tail = col;
if (!c.distance[row][col] && maxD < D(c, edge)) {
maxD = D(c, edge);
best = edge;
}
}
}
return (best);
}

/* �������ѡ edge ��Ϊ��֦�ߣ���֦������ edge���½������ */
int D(MATRIX c, EDGE edge)
{
int row, col, dRow, dCol;
int n = c.citiesNumber;

dRow = INFINITY;
for (col = 0; col < n; col++) {
if (dRow < c.distance[edge.head][col] && col != edge.tail) {
dRow = c.distance[edge.head][col];
}
}
dCol = INFINITY;
for (row = 0; row < n; row++) {
if (dCol < c.distance[row][edge.tail] && row != edge.head) {
dCol = c.distance[row][edge.tail];
}
}
return (dRow + dCol);
}

/* ɾ����ѡ��֦�� */
MATRIX LeftNode(MATRIX c, EDGE edge)
{
c.distance[edge.head][edge.tail] = INFINITY;
return c;
}

/* ɾ�����кͻ�·�ߺ�ľ��� */
MATRIX RightNode(MATRIX c, EDGE edge, PATH path)
{
int row, col;
int n = c.citiesNumber;
EDGE loopEdge;

/* ��������Ҫ�����·�ߺ��� */
EDGE LoopEdge(PATH, EDGE);

for (col = 0; col < n; col++)
c.distance[edge.head][col] = INFINITY;
for (row = 0; row < n; row++)
c.distance[row][edge.tail] = INFINITY;

loopEdge = LoopEdge(path, edge);
c.distance[loopEdge.head][loopEdge.tail] = INFINITY;

return (c);
}

/* �����·�ߵĺ���
* ���˼�����±ߣ� ��ǰ���·�߼����л����ܰ���һЩ�Ѿ�ѡ���ıߣ� ��Щ�߹���һ����
* ����·���� Ϊ�˲����ɻ�·�� ����ʹ���а����±ߵ�·��ͷβ�����������������������
* ͷβ�����ıߣ��Ա�������·�ߵĳ���������
*/
EDGE LoopEdge(PATH path, EDGE edge)
{
int i, j;
EDGE loopEdge;

/* ��С�Ļ�·�� */
loopEdge.head = edge.tail;
loopEdge.tail = edge.head;

/* Ѱ�һ�·�ߵ�ͷ�˵㣬�������±ߵ�·����β�˵� */
for (i = 0; i < path.edgesNumber; i++) {
for (j = 0; j < path.edgesNumber; j++) {
if (loopEdge.head == path.edge[j].head) {
/* �����·�� */
loopEdge.head = path.edge[j].tail;
break;
}
}
}
/* Ѱ�һ�·�ߵ�β�˵㣬�������±ߵ�·����ͷ�˵� */
for (i = 0; i < path.edgesNumber; i++) {
for (j = 0; j < path.edgesNumber; j++) {
if (loopEdge.tail == path.edge[j].tail) {
/* �����·�� */
loopEdge.tail = path.edge[j].head;
break;
}
}
}

return (loopEdge);
}

/* ���±߼��뵽·���� */
PATH AddEdge(EDGE edge, PATH path)
{
path.edge[path.edgesNumber++] = edge;
return path;
}


/* ���㻨�Ѿ���ǰ���� */
int MatrixSize(MATRIX c, PATH path)
{
return (c.citiesNumber - path.edgesNumber);
}

/* ��ʾ·�� */
void ShowPath(PATH path, MATRIX c)
{
int i, dist;
EDGE edge;
int n = path.edgesNumber;

dist = 0;
printf("\nThe path is: ");
for (i = 0; i < n; i++) {
edge = path.edge[i];
printf("(%d, %d) ", edge.head + 1, edge.tail + 1);
dist += c.distance[edge.head][edge.tail];
}
/* printf("[Total Cost: %d]\n", dist); */
}

/* ��ʾ���Ѿ��� */
void ShowMatrix(MATRIX c)
{
int row, col;
int n =  c.citiesNumber;

for (row = 0; row < n; row++) {
for (col = 0; col < n; col++) {
if (c.distance[row][col] != INFINITY) {
printf("%3d", c.distance[row][col]);
}
else {
printf("  -");
}
}
putchar('\n');
}
getch();
}