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
static int num() { return count; } //静态成员函数仅能访问静态成员函数 
}; 
int circle::count=0;//静态数据成员为所有对象共有 
int main()
{
   circle a(3),b(4),c(5);
   cout<<c.num()<<endl;
}

