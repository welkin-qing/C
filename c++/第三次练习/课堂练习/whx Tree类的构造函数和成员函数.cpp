#include <iostream>
using namespace std;

class Tree {
public:
    Tree();//���캯��
    void grow(int years);//������ages����years
    void age();//��ʾ����ages��ֵ
private:
    int ages;//����
};

int main()
{
    Tree tree;
    int years;
    cin >> years;
    tree.grow(years);
    tree.age();

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
void Tree::age()
{
	cout<<ages;
 } 
 
void Tree::grow(int years)
{
	ages+=years;
}
Tree::Tree()
{
	ages=1;
}

