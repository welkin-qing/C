#include <stdio.h>

//--------------------------------------------------------
// ��ӡ���˶���
//--------------------------------------------------------
int MoveIt(int x,int Source,int Target)
{
    printf("Move %d From %d to %d\n",x,Source,Target);
    return 0;
}

//--------------------------------------------------------
// �� 4 �������ƶ�����
// n �����Ӹ�������Ŵ�1 �� n
// First ��Դ���Ӻ�
// Second Third ������������
// Fourth ��Ŀ����
//--------------------------------------------------------
int MoveHanoi(int n,int First,int Second,int Third,int Fourth)
{
    if (n<1) return 0;                  // ���û�����Ӿͷ���
    if (n==1)                            // ���ֻ��һ������
    {
        MoveIt(n,First,Fourth);          // ��ֱ�Ӵ�Դ�����Ƶ�Ŀ��������
        return 0;
    }
    if (n==2)                            // �������������
    {
        MoveIt(n-1,First,Second);        // ���������Ƭ�Ƶ�һ����������
        MoveIt(n,First,Fourth);          // ���������Ƭ�Ƶ�Ŀ������
        MoveIt(n-1,Second,Fourth);      // �ٰѵ� 1 Ƭ�ӹ������Ƶ�Ŀ������
return 0;
    }
    if (n==3)                            // ����� 3 Ƭ����
    {
        MoveIt(n-2,First,Second);        // ����С�������Ƶ�һ����������
        MoveIt(n-1,First,Third);        // ���м������Ƶ���һ��������
        MoveIt(n,First,Fourth);          // �����������Ƶ�Ŀ������
        MoveIt(n-1,Third,Fourth);        // ���м������Ƶ�Ŀ������
        MoveIt(n-2,Second,Fourth);      // ����С�������Ƶ�Ŀ������
        return 0;
    }
                                        // �ݹ�ذ����� n-2 �����Ƶ�һ����������
                                        // ����������������
    MoveHanoi(n-2,First,Third,Fourth,Second);
    MoveIt(n-1,First,Third);            // �ѵ����� 2 �������Ƶ���һ����������
    MoveIt(n,First,Fourth);              // ������µ������Ƶ�Ŀ������
    MoveIt(n-1,Third,Fourth);            // �ѵ����� 2 �������Ƶ�Ŀ������
                                        // �ݹ�ذ� n-2 �����Ӵӹ��������Ƶ�Ŀ������
    MoveHanoi(n-2,Second,First,Third,Fourth);
    return 0;
}

int main()
{
    MoveHanoi(4,1,2,3,4);
    return 0;
}
