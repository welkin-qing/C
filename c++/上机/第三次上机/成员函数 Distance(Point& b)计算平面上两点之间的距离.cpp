#include <iostream> 
#include <math.h> 
using namespace std;
class Point 
{  
	public:       
		Point(double xi, double yi) {X=xi; Y=yi; }       
		double GetX() {return X;}       
		double GetY() {return Y;}       
		double Distance(Point& b);       
	private:           
		double X, Y; 
}; 
double Point::Distance(Point& b) {       
	double dx=X-b.X;       
	double dy=Y-b.Y;       
	return sqrt(dx*dx+dy*dy); 
}
 int main() 
 {  
 	Point p1(3.0, 5.0), p2(4.0, 6.0);     
 	double d=p1.Distance(p2);     
 	cout<<"The distance is "<<d<<endl;     
 	return 0;
} 
