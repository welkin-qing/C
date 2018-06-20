#include<iostream>
#include<math.h>
using namespace std;
class point{
	private:
		int x,y;
	public:
		point(int a,int b)
		{
			x=a;
			y=b;
		}
		int putx()
		{
			return(x);
		}
		int puty()
		{
			return(y);
		 } 
};
double Distance(point &a,point &b)
{
	return(sqrt(pow(a.putx()-b.putx(),2)+pow(a.puty()-b.puty(),2)));
}
int main()
{
	int x1,y1;
	int x2,y2;
	cin>>x1>>y1>>x2>>y2;
	point a(x1,y1);
	point b(x2,y2);
	printf("%.2lf",Distance(a,b));
	return 0;
} 
/*
#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

class Point
{
	int x,y;
	public:
		Point(int a,int b)
		{
			x=a;
			y=b;
		}
		int putx()
		{
			return x;
		}
		int puty()
		{
			return y;
		}
};
double Distance(Point &a,Point &b)
{
	
	return sqrt(pow(a.putx()-b.putx(),2)+pow(a.puty()-b.puty(),2));
}
int main()
{
	int x1,y1;
	int x2,y2;
	cin>>x1>>y1>>x2>>y2;
	Point a(x1,y1);
	Point b(x2,y2);
	printf("%.2lf",Distance(a,b));
	return 0;
}

*/
