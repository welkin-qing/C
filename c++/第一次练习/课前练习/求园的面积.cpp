//1.5
//Êä³öÑùÀı:
//7.06858
#include <iostream>
using namespace std;
const double PI=3.1415926;
class Circle
{
protected:
   double radius;
public: 
   Circle(double r)
   {
      radius=r;
   }
   double getArea(){
      return PI*radius*radius;
   }
};

int main() 
{
   double r;
   cin>>r;
   Circle Cy1(r) ;
   cout<<Cy1.getArea()<<endl;
   return 0;
}

