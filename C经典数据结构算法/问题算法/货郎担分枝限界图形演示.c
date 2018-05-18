/*
* File: tsp.c
* Description: �����ɵ�����ķ�֦�޽��㷨ͼ����ʾ
*          Branch-and-bound algorithm to solve the
*            travelling salesman problem. CG demo.
* Use:    tcc tsp graphics.lib
* Created: 2001/11/29 - 2001/12/01
* Author: Justin Hou [mailto:justin_hou@hotmail.com]
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

#define  MAX_CITIES  15                                /* ���е���Ŀ      */
#define  INFINITY    9999                              /* ��ʾ�����      */
#define  I          INFINITY                          /* ��ʾ�����      */

typedef struct _POINT {                                /* �����Ľṹ    */
        int x;
        int y;
} POINT;

typedef struct _EDGE {                                /* ����ߵĽṹ    */
        int head;
        int tail;
} EDGE;

typedef struct _PATH {                                /* ����·���ṹ    */
        EDGE edge[MAX_CITIES];
        int  edgesNumber;
} PATH;

typedef struct _MATRIX {                              /* ���廨�Ѿ���ṹ */
        int distance[MAX_CITIES][MAX_CITIES];
        int citiesNumber;
} MATRIX;

typedef struct _NODE {                                /* ���������      */
        int bound;                                    /* ���Ļ����½�  */
        MATRIX matrix;                                /* ��ǰ���Ѿ���    */
        PATH path;                                    /* �Ѿ�ѡ���ı�    */
} NODE;

int  minDist = INFINITY;
int  GraphDriver;
int  GraphMode;
int  ErrorCode;
POINT city[MAX_CITIES] = {
        {459, 333}, {345, 234}, {362, 245}, {332, 183},
        {323, 343}, {630, 345}, {154, 263}, {213, 112},
        {432, 254}, {534, 223}, {334, 333}, {432, 234},
        { 23, 442}, {600, 400}, {500, 300}
};

int    Simplify(MATRIX *);                    /* ��Լ���󲢷��ع�Լ����  */
int    MatrixSize(MATRIX, PATH);              /* ����������            */
EDGE    SelectBestEdge(MATRIX);                /* ��������ʵķ�֦��      */
MATRIX  InitMatrix(void);                      /* ��ʼ�����þ�������      */
MATRIX  LeftNode(MATRIX, EDGE);                /* ������֦�����þ���    */
MATRIX  RightNode(MATRIX, EDGE, PATH);        /* ������֦�����þ���    */
PATH    AddEdge(EDGE, PATH);                  /* ������ӵ�·��������    */
PATH    BABA(NODE *);                          /* ��֦���ݺ��� B-and-B Ar. */
PATH    MendPath(PATH, MATRIX);                /* �޲�û����ɵ�·��      */
void    ShowMatrix(MATRIX);                    /* �ı���ʾ���þ��� ������  */
void    ShowPath(PATH);                        /* �ı���ʾ·��            */
void    DrawPath(PATH);                        /* ͼ����ʾ·��            */

void main()
{
        PATH path;
        NODE root;
        GraphDriver = DETECT;
        initgraph( &GraphDriver, &GraphMode, "" );
        ErrorCode = graphresult();
        if( ErrorCode != grOk ) {
                printf(" Graphics System Error: %s\n",
                      grapherrormsg(ErrorCode));
                exit(1);
        }

        /* ��ʼ�����ݣ���Լ����������� */
        root.matrix = InitMatrix();
        root.bound = Simplify(&(root.matrix));
(root.path).edgesNumber = 0;

        /* ��������ѭ�������շ������·�� */
        path = BABA(&root);

        /* ��ʾ��� */
        DrawPath(path);
        ShowPath(path);
        printf("\nminDist:%d\n", minDist);

        getch();
        closegraph();
}

/* ��ʼ������ */
MATRIX InitMatrix()
{
        int row, col, n;
        double dx, dy;
        MATRIX c;

        n = MAX_CITIES; /* �д��������ݶ�ȡ��ʽ */
        c.citiesNumber = n;
        for (row = 0; row < n; row++) {
                putpixel(city[row].x, city[row].y, 5);
                for (col = 0; col < n; col++) {
                        dx = (double)(city[row].x - city[col].x);
                        dy = (double)(city[row].y - city[col].y);
                        /* ���������� */
                        c.distance[row][col] = (int)sqrt(dx * dx + dy * dy);
                        if (row == col)
                                c.distance[row][col] = INFINITY;
                }
        }
        return c;
}
/*
* �㷨������������Branch-And-Bound Algorithm Search
*            root �ǵ�ǰ�ĸ���㣬�ѹ�Լ����������
*/
PATH BABA(NODE* root)
{
        static PATH minPath;
        EDGE selectedEdge;
        NODE *left, *right;

        /* �����ǰ�����СΪ2��˵������������û��ѡ�����������߱ض�ֻ����һ
        * ����ϣ����ܹ��������·��������ʵ������·���Ѿ�ȷ����
        */
        if (MatrixSize(root->matrix, root->path) == 2) {
                if (root->bound < minDist) {
                        minDist = root->bound;
                        minPath = MendPath(root->path, root->matrix);
                        free(root);
                        return (minPath);
                }
        }
        /* �������½羡�����ԭ��ѡ��֦�� */
        setcolor(7);
        selectedEdge = SelectBestEdge(root->matrix);
        line(city[selectedEdge.head].x, city[selectedEdge.head].y,
                city[selectedEdge.tail].x, city[selectedEdge.tail].y);
        putpixel(city[selectedEdge.head].x, city[selectedEdge.head].y, MAGENTA);
        putpixel(city[selectedEdge.tail].x, city[selectedEdge.tail].y, MAGENTA);

        /*
        * �������ҷ�֦���
        */
        right = (NODE *)malloc(sizeof(NODE));
        if (right == NULL) {
                fprintf(stderr,"Error malloc branch.\n");
                exit(-1);
        }
        /* ʹ��֦���վ��ԭ�����λ�ã���ʡ�ռ� */
        left = root;
        /* ��ʼ�����ҷ�֦��� */
        right->matrix = RightNode(root->matrix, selectedEdge, root->path);
        right->bound =        root->bound + Simplify(&(right->matrix));
        right->path = AddEdge(selectedEdge, root->path);

        left->matrix = LeftNode(left->matrix, selectedEdge);
        left->bound = left->bound + Simplify(&(left->matrix));

        /* ����ҽ���½�С�ڵ�ǰ��Ѵ𰸣�������֦���� */
        if (right->bound < minDist) {
                BABA(right);
        }
        /* ����ɾ�����������ܲ�������·�ߵ���֦ */
        else {
                free(right);
        }

        setcolor(BLACK);;
        line(city[selectedEdge.head].x, city[selectedEdge.head].y,
                city[selectedEdge.tail].x, city[selectedEdge.tail].y);
        putpixel(city[selectedEdge.head].x, city[selectedEdge.head].y, MAGENTA);
        putpixel(city[selectedEdge.tail].x, city[selectedEdge.tail].y, MAGENTA);

        /* ����ҽ���½�С�ڵ�ǰ��Ѵ𰸣�������֦���� */
        if (left->bound < minDist) {
                BABA(left);
        }
        /*
        *  ����������������ɾ��������'Null pointer assignment'����
        * ��Null pointer assingnment'����ָ����ֶ�ɾ�����������������
        *  ��main()ִ����Ϻ��ͷſռ�ʱ�Ҳ������ݵ�ָ�롣
        */
        else if ((left->path).edgesNumber != 0){
                free(left);
        }

        gotoxy(1, 1);
        printf("Current minDist: %d  ", minDist);
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

/* �������ѡ edge ��Ϊ��֦�ߣ���֦( ���� edge )�½������ */
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

/* ɾ����ѡ��֦��( left ) */
MATRIX LeftNode(MATRIX c, EDGE edge)
{
        c.distance[edge.head][edge.tail] = INFINITY;
        return c;
}

/* ɾ�����кͻ�·��( right ) */
MATRIX        RightNode(MATRIX c, EDGE edge, PATH path)
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
* ���˼�����±ߣ� ��ǰ���·�߼����л����ܰ���һЩ�Ѿ�ѡ���ıߣ� ��Щ�߹���
* һ������·���� Ϊ�˲����ɻ�·�� ����ʹ���а����±ߵ�·��ͷβ������������
* �����������ͷβ�����ıߣ��Ա�������·�ߵĳ���������
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

/* �ı���ʽ��ʾ·�� */
void ShowPath(PATH path)
{
        int i;
        EDGE edge;
        int n = path.edgesNumber;

        printf("\nThe path is:\n");
        for (i = 0; i < n; i++) {
                edge = path.edge[i];
                printf("(%d,%d)", edge.head + 1, edge.tail + 1);
        }
}

/* ͼ�η�ʽ��ʾ·�� */
void DrawPath(PATH path)
{
        int i;
        POINT a, b;
        int n = path.edgesNumber;

        for (i = 0; i < n; i++) {
                a.x = city[(path.edge[i]).head].x;
                a.y = city[(path.edge[i]).head].y;
                b.x = city[(path.edge[i]).tail].x;
                b.y = city[(path.edge[i]).tail].y;
                line(a.x, a.y, b.x, b.y);
                setcolor(MAGENTA);
                circle(a.x, a.y, 5);
                circle(b.x, b.y, 5);
                setcolor(BLUE);
        }
}


/* �ı���ʽ��ʾ���Ѿ��󣬵����� */
void ShowMatrix(MATRIX c)
{
        int row, col;
        int n =  c.citiesNumber;

        for (row = 0; row < n; row++) {
                for (col = 0; col < n; col++) {
                        if (c.distance[row][col] != INFINITY) {
                                printf("%4d", c.distance[row][col]);
                        }
                        else {
                                printf("  -");
                        }
                }
                printf("\n");
        }
}