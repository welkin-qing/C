#include<iostream>
#include <math.h>
using namespace std ;
class Point{
    public:
    Point(int _x ,int _y):x(_x),y(_y){}
    double Distance(Point &temp){
        return sqrt((x-temp.x)*(x-temp.x) + (y-temp.y)*(y-temp.y));
    }
    private:
    int x ; 
    int y ;
};
int main(void){
    int temp1_x ,temp1_y ,temp2_x ,temp2_y  ;
    cin >>  temp1_x >> temp1_y >> temp2_x >> temp2_y  ;
    Point  p1(temp1_x ,temp1_y);
    Point  p2(temp2_x ,temp2_y);
    printf("%.2lf\n",p1.Distance(p2));
}