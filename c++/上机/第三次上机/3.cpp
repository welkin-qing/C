#include<iostream>
using namespace std;
class circle 
{ private: 
   float radius; 
   static int count; 
public: 
circle(float r) 
{ radius=r; 
  ++count;} 
~circle() {--count ; } 
static int num() { return count; } //��̬��Ա�������ܷ��ʾ�̬��Ա���� 
}; 
int circle::count=0;//��̬���ݳ�ԱΪ���ж����� 
int main()
{
   circle a(3),b(4),c(5);
   cout<<c.num()<<endl;
}

