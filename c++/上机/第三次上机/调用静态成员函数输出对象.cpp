#include <iostream>
using namespace std;
class Circle
{ 
	public:
	 	Circle(float r){ 	radius=r;++count;}
 		int printf();
 		~Circle() { --count; }
		static int num(){	return count; } //��̬��Ա����
 	private:
 		float radius;
 		static int count; //��̬���ݳ�Ա
}; 
int Circle::printf()
{
	cout<<"count:"<<count<<endl;
}
int Circle::count=0;
int main()
{
	Circle c1(5);
	Circle::num();
	c1.printf();

	Circle c2(5);
	Circle::num();
	c2.printf();
	
	Circle c3(5);
	Circle::num();
	c3.printf();
	return 0;


}

