#include<iostream.h> 
#include<math.h>  
#include<SquareRectangle.h> 
int main() 
{ 
	Square  Squa1(100); //���� Square::Square(int)��ʼ�� 
	Rectangle Rect(200,300);//���� Rectangle::Rectangle(int,int)��ʼ �� 
	//�Ƚ������������ 
	cout<<"������ Squa1(100)�����Ϊ��"<<Squa1.GetArea()<<endl; 
	//��̬���࣬���Ϊ��10000 
	cout<<"������ Squa1(100)�����Ϊ��"<<objGetArea(&Squa1)<<endl; //�Ƚ������������ 
	cout<<"���� Rect(200,300) �����Ϊ��:"<<Rect.GetArea()<<endl; //��̬���࣬���Ϊ 60000 
	cout<<"���� Rect(200,300) �����Ϊ��:"<<objGetArea(&Rect)<<endl; //��̬���࣬���Ϊ 60000 return 0; 
} 

