#include<iostream> 
#include<math.h> 
using namespace std;
class Square { 
	protected:       
		int edge;  
	public: 
		virtual  double GetArea(); 
		Square(int edg); 
		~Square( ) { } 
}; 
Square::Square(int edg) 
{ 
	edge=edg;  
} 
//�������ε���� 
double Square::GetArea() 
{ 
	double result; 
	result=edge*edge; 
	return result; 
}  
double  objGetArea(Square* base); 
class Rectangle:public Square 
{  
	protected:    
		int  length; //���Ŀ����������� Square �ĳ�Ա�ṩ 
	public: 
		double GetArea();     
		Rectangle(int edg,int leng); 
		~Rectangle(){  } 
}; 
double Rectangle::GetArea()//����ε���� 
{ 
	double result; 
	result=length*edge; 
	return result; 
} 
Rectangle::Rectangle(int edg,int leng):Square(edg) 
{ 
	//���û���Ĺ��캯�� Square(edg)ʹ edge=edg; 
	length=leng; 
} 
double objGetArea(Square* obj) 
{ 
	return obj->GetArea(); 
} 
int main() 
{ 
	Square  Squa1(100); //���� Square::Square(int)��ʼ�� 
	Rectangle Rect(200,300);//���� Rectangle::Rectangle(int,int)��ʼ �� 
	Square *p=&Rect;
	Square *q=&Squa1;
	//�Ƚ������������ 
	cout<<"������ Squa1(100)�����Ϊ��"<<Squa1.GetArea()<<endl; //��̬���࣬���Ϊ��10000 
	cout<<"������ Squa1(100)�����Ϊ��"<<objGetArea(&Squa1)<<endl; //�Ƚ������������ 
	cout<<"������ Squa1(100)�����Ϊ��"<<q->GetArea()<<endl;
	
	cout<<"���� Rect(200,300) �����Ϊ��:"<<Rect.GetArea()<<endl; //��̬���࣬���Ϊ 60000 
	cout<<"���� Rect(200,300) �����Ϊ��:"<<objGetArea(&Rect)<<endl; //��̬���࣬���Ϊ 60000 return 0; 
	cout<<"���� Rect(200,300) �����Ϊ��:"<<p->GetArea()<<endl;
} 
