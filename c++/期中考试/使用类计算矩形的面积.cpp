#include <iostream>
using namespace std;

class Rectangle {
public:
    void setLength(int l);//���þ��εĳ���
    void setWidth(int w); //���þ��εĿ��
    int getArea();        //���㲢���ؾ��ε����
private:
    int length, width;    //���εĳ��ȺͿ��	
};

int main()
{
    Rectangle r;
    int len, w;
    cin >> len >> w;
    r.setLength(len);
    r.setWidth(w);
    cout << r.getArea() << "\n";

    return 0;
}
void Rectangle :: setLength(int length1)
{
	length=length1;
}
void Rectangle :: setWidth(int width1) 
{
	width=width1;
}
int Rectangle :: getArea()
{
	return(width*length);
}
