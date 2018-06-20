#include<iostream>
using namespace std;
class Rectangle{
	private:
		double width;
		double height;
	public:
		void set(double width1,double height1);
		double getArea( );
};
void Rectangle::set(double width1,double height1){
	width=width1;
	height=height1;
}
double Rectangle::getArea()
{
	return(width*height);
}
int main()
{    
    double m,n;
    cin>>m;
    cin>>n;
    Rectangle a;
    a.set(m,n);
    cout<<a.getArea()<<endl;
    return 0;
} 
