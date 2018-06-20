#include<iostream>
using namespace std;

class Complex {
public:
    Complex(double realPart = 0, double imgPart = 0) {
        this->realPart = realPart;
        this->imgPart = imgPart;
    }
    Complex& operator+(Complex& com);
    void Show() {
        cout << realPart << " " << imgPart << endl;
    }
private:
    double realPart, imgPart;
};
int main() {
    int r1, i1;			//��1�����������ʵ�����鲿
    int r2, i2;			//��1�����������ʵ�����鲿
    cin >> r1 >> i1;
    cin >> r2 >> i2;
    Complex c1(r1, i1);	//�����1����������c1
    Complex c2(r2, i2);	//�����2����������c2
    c1 = c1 + c2;
    c1.Show();

    return 0;
}
/* ��Ĵ��뽫��Ƕ������ */
Complex& Complex::operator+(Complex& com)
{
	this->realPart=this->realPart+com.realPart;
	this->imgPart=this->imgPart+com.imgPart;
	return *this;
}
