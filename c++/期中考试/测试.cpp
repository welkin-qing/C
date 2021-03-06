/*
1.命名空间应用于-避免各个不同函数、变量等的名称冲突
2.cout 是由I/O 流库预定义的-对象
3.重载函数在调用时选择的依据中，错误的是-函数的类型
4.对定义重载函数的下列要求中，（要求函数的返回值不同）是错误的。
5.关于new运算符的下列描述中，（使用它创建对象数组时必须指定初始值）是错误的。
6.关于delete运算符的下列描述中，（对一个指针可以使用多次该运算符；）是错误的。
7.一个函数功能不太复杂，但要求被频繁调用，选用（内联函数 ）
8.重载函数在调用时选择的依据中，错误的是（函数的类型）
9.在（函数代码少、频繁调用 ）情况下适宜采用inline定义内联函数。
10.下面说法正确的是（内联函数在编译时是将该函数的目标代码插入每个调用该函数的地方）
11.对定义重载函数的下列要求中，（要求函数的返回值不同 ）是错误的。
12.命名空间应用于-避免各个不同函数、变量等的名称冲突。
13.如果在函数中定义的局部变量与命名空间中的变量同名时，（命名空间中的变量）被隐藏。
14.如果程序中使用了using命令同时引用了多个命名空间，并且命名空间中存在相同的函数，将出现-编译错误
15.要说明标识符是属于哪个命名空间时，需要在标识符和命名空间名字之间加上-：：
16.如果默认参数的函数声明为“ void fun(int a,int b=1,char c='a',float d=3.2);”， 则下面调用写法正确的是（fun(2,3); ）
17.在下列关键字中,用以说明类中公有成员的是（ public）
18.有关类和对象的说法下列不正确的有（ 一个类只能有一个对象）
19.类成员的默认访问属性是-private
20.在面向对象的软件系统中，不同类对象之间的通信的一种构造称为-消息
21.下列函数中，（ 析构函数）不能重载。
22.下列对重载函数的描述中，（重载函数中不允许使用默认参数 ）是错误的。
23.设A为自定义类，现有普通函数int fun(A& x)。则在该函数被调用]时-无需初始化形参x
24.所有类都应该有-构造函数和析构函数
25.析构函数可以返回-不可返回任何值
26.有关类和对象的说法下列不正确的有（一个类只能有一个对象 ）
27.以下哪一个不是正确的成员访问属性-hidden
28.类成员的默认访问属性是-private
29.在面向对象的软件系统中，不同类对象之间的通信的一种构造称为-消息
30.在下列关键字中,用以说明类中公有成员的是（ public）。
31.在面向对象系统中，对象是基本的运行时实体，它 -把属性和行为封装为一个整体
32.在面向对象系统中，对象的属性是-和其他对象相互区分的特性
33.一个类的每个实例共享的变量是-静态变量 
34.静态成员函数没有-this指针
35.下面对静态数据成员的描述中，正确的是-静态数据成员是类的所有对象共享的数据
36.下列关于this指针的叙述中，正确的是-类的非静态成员函数才有this指针
37.给定声明圆X〔10〕，下列哪一个陈述是错误的？- X包含十个int值的数组。
38.下面对静态数据成员的描述中，正确的是-静态数据成员是类的所有对象共享的数据
39.下列有关继承和派生的叙述中，正确的是-如果基类没有默认构造函数，派生类就应当定义带形参的构造函数
40.下列关于派生类构造函数和析构函数的说法中，错误的是-在销毁派生类对象时，先调用基类的析构函数，再调用派生类的析构函数
41.建立派生类对象时, 3种构造函数分别是a(基类的构造函数)、b(成员对象的构造函数)、c(派生类的构造函数)，这3种构造函数的调用顺序为-abc
42.关于函数模板，描述错误的是-函数模板必须由程序员实例化为可执行的函数模板
43.建立类模板对象的实例化过程为-(模板类-对象)
44.下列对重载函数的描述中，（ 重载函数中不允许使用默认参数）是错误的。
45.已知类A是类B的友元，类B是类C的友元，则-类A的成员函数可以访问类B的对象的任何成员
46.下列关于类的继承描述中，(一个基类可以有多个派生类，一个派生类可以有多个基类。 )是正确的。
47.（ 继承）不是面向对象程序设计的主要特征。 
48.在C++语言中设置虚基类的目的是（ 解决多继承造成的二义性问题）
49.对于常数据成员，下面描述正确的是-常数据成员必须被初始化，并且不能更新
50.在面向对象的软件系统中，不同类对象之间的通信的一种构造称为-消息
51.如果在函数中定义的局部变量与命名空间中的变量同名时，（命名空间中的变量）被隐藏。
52.如果程序中使用了using命令同时引用了多个命名空间，并且命名空间中存在相同的函数，将出现-编译错误
53.对象之间的相互作用和通信是通过消息。（要执行的函数的内部结构 ）不是消息的组成部分。
54.与单个对象相关联的函数称为-类函数
55.一个类的私有成员-只能被该类的成员函数和友元函数访问
56.以下关于C++语言中继承的叙述中，错误的是（继承仅仅允许单继承，即不允许一个子类有多个父类 ）
57.下列关于类的继承描述中，( 一个基类可以有多个派生类，一个派生类可以有多个基类)是正确的。
判断
1.使用提取符(<<)可以输出各种基本数据类型的变量的值，也可以输出指针值 对
2.预定义的插入符从键盘上接收数据是不带缓冲区的 错
3.cin流通常连接到显示屏幕 错
4.函数的参数个数和类型都相同，只是返回值不同，这不是重载函数 对 
5.函数调用中的参数类型必须与函数原型参数列表中相应参数的类型相匹配。 对
6.在C++语言中引入内联函数（inline function）的主要目的是降低空间复杂度，即缩短目标代码长度。错
7.重载函数可以带有默认值参数，但是要注意二义性。对
8.常量成员函数不能更改对象中的数据字段。 对
9.在protected保护继承中，对于垂直访问等同于公有继承，对于水平访问等同于私有继承。对
10.可以通过下标随机访问向量vector中的元素。对
11.当向量对象的内存用完之后，就会产生越界错误。错
12.面向对象程序设计的继承性鼓励程序员重用被实践验证的高质量软件。 对
13.C++程序中，类的构造函数名与类名相同。对
14.
*/
/*1.计算圆的面积 
#include<iostream>
#define PI 3.1415926
using namespace std;
int main()
{
	double r;
	double sum;
	cin>>r;
	sum=r*r*PI;
	cout<<sum<<endl;
 }
 */
/*2
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
*/
/*计算平均值
#include<iostream>
using namespace std;
int main()
{
   int k,i=0,m=0;
   cin>>k;
   getchar();
   while(1)
   {
   int b=0,sum=0;
   while(1){
   cin>>i;
   m=i;
        b++;
        if(b<=k)
        {
        	sum+=i;
		}
		if((i=getchar())!=' ')break; 
    }
    if(m!=100){
   	if(b<=k)
   	cout<<sum/b<<'\n';
   	else
   	cout<<sum/k<<'\n';
   }
   if(m==100) break;
   }	
 } 
*/
/*最大值函数重载
#include<iostream>
using namespace std;
int myMax(int m,int n,int q){
	if(m>n&&m>q) return(m);
	if(n>m&&n>q) return(n);
	if(q>m&&q>n) return(q);
}
double myMax(double m,double n){
	if(m>n) return(m);
	else return(n); 
}
int main(){
	cout<<myMax(3,4)<<endl;
	cout<<myMax(3,4,5)<<endl;
	cout<<myMax(4.3,3.4)<<endl;
}
*/
/*计算三角形面积
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double m,n,p;
	double area,sum;
	cin>>m>>n>>p;
	sum=(m+n+p)/2;
	if(m+n>p&&m+p>n&&p+n>m){
		area=sqrt(sum*(sum-m)*(sum-n)*(sum-p));
		cout<<area<<endl;
	}else{
		cout<<"no"<<endl;
	}
}
*/
/*正五边形的面积
#include<iostream>
#include<math.h>
using namespace std;
double line(double n);
long double area(double n);
int main()
{
	double n;
	cin>>n;
	cout<<line(n)<<endl;
	cout<<area(n)<<endl;
 } 
double line(double n)
{
	return(5*n);
}
long double area(double n)
{
	return(n*n*sqrt(25+10*sqrt(5))/4); 
}
*/
/*长方形或长方体面积计算器（函数重载）
#include<iostream>
#include<string>
using namespace std;
int area(int,int);
int area(int,int,int);
int main()
{
    int i, repeat, c, x, y, z;
    cin>>repeat;
    for(i=0;i<repeat;i++){
        cin>>c;
        if(c==2){
            cin>>x>>y;
            cout<<area(x,y)<<endl;
        }
        if(c==3){
            cin>>x>>y>>z;
            cout<<area(x,y,z)<<endl;
        }
    }
    return 0;
}
int area(int x,int y){
	return(x*y);
}
int area(int x,int y,int z)
{
	int squ;
	squ=2*(x*y+y*z+z*x);
	return(squ);
}
*/
/*求最大值和最小值
#include <iostream>
using namespace std;
void f(int a[],int n,int &max,int &min)
{
	max=min=a[0];
	for(int i=1;i<10;i++)
	{
		if(max<a[i]) max=a[i];
		if(min>a[i]) min=a[i];
	}
}
int main( )
{
  int a[10];
  int max,min,i;
  for(i=0;i<10;i++){
     cin>>a[i];
  }
  f(a,10,max,min);
  cout<<"Max: "<<max<<endl;
  cout<<"Min: "<<min<<endl;
  return 0;
}
*/
/*set一个名为Rectangle的矩形类
#include <iostream>
using namespace std;
class Rectangle{
	private:
		double width;
		double height;
	public:
		void set(double w,double h)
		{
			width=w;
			height=h;
		}
		double getArea()
		{
			return(width*height);
		}
		double getPerimeter()
		{
			return(2*(width+height));
		}
};
int main()
{    
    double m,n;
    cin>>m;
    cin>>n;
    Rectangle a;
    a.set(m,n);
    cout<<a.getArea()<<endl;
    cout<<a.getPerimeter()<<endl;
    return 0;
}
*/
/*set一个三角形Triangle类
#include <iostream> 
using namespace std;  
class Triangle{
	private:
		double width;
		double height;
	public:
		Triangle(double w,double h)
		{
			width=w;
			height=h;
		}
		double getArea()
		{
			return(width*height/2);
		}
};
int main( )
{
  double w,h;
  cin>>w>>h;
  Triangle t(w,h);
  cout<<"The area of the Triangle is: "<<t.getArea( )<<endl;
}
*/
/*定义一个日期类Date，计算并输出该日是该年的第几天
#include<iostream>
using namespace std;

class Date
{
	int years,mouths,days;
	public:
		Date(int year,int mouth,int day)
		{
			years=year;
			mouths=mouth;
			days=day;
		}
		void date()
		{
			int sum=0;
 			for(int i=0;i<mouths;i++)
 			{
 				if(i==1) sum+=31;
 				else if(i==2)
 				{
 					if(judge()==1) sum+=29;
 					else sum+=28;
		 		}
		 		if(i==3) sum+=31;
				 if(i==4) sum+=30;
				 if(i==5) sum+=31;
				 if(i==6) sum+=30;
				 if(i==7) sum+=31;
				 if(i==8) sum+=31;
				 if(i==9) sum+=30;
				 if(i==10) sum+=31;
				 if(i==11) sum+=30;
				 if(i==12) sum+=31;
	 }
	 sum+=days;
	 cout<<sum;
		}
		int judge()
		{
			if((years%4==0&&years%100!=0)||(years%400==0))
			return 1;
			else
			return 0;
		}
 }; 
 
 int main()
 {
 	int year,mouth,day;
 	cin>>year>>mouth>>day;
 	Date date1(year,mouth,day);
 	date1.date(); 
  } 
 */
/*定义一个名为Stock的股票类
#include <iostream>
using namespace std;
class Stock
{
	public:
	string symbol;
	string name;
	double previousClosingPrice;
    double currentPrice;
   void set(string s1,string s2)
   {
   	//symbol=new char[strlen(s1)+1];
   	symbol=s1;
   	name=s2;
   }
  double  changePercent()
   {
   return((currentPrice-previousClosingPrice)/previousClosingPrice);
   }
};
int main( ) {
    char s1[10],n1[20];
    cin>>s1>>n1;
    Stock stock;
    stock.set(s1, n1);
    // 输入前一日收盘价
    cin>>stock.previousClosingPrice;

    // 输入当前成交价
    cin>>stock.currentPrice;

    // 显示股票信息
    cout<<stock.name<<" price changed: " <<(stock.changePercent() * 100)<<"%";
    return 0;
  }
*/
/*友元函数学生类
#include<iostream>
#include<string>
using namespace std;
class student{
	private:
		string num;
		double score;
	public:
		void set(string n,double s)
		{
			num=n;
			score=s;
		}
	friend double average(student *p,int count);
}stu[100];
double average(student *p,int count)
{
	double sum;
	double aver;
	for(int i=0;i<count;i++)
	{
		sum=sum+p[i].score;
	}
	aver=sum/count;
	return(aver);
}
int main()
{
	string num;
	int score;
	int k=0;
	while(1){
		cin>>num;
		if(num=="0") break;
		cin>>score;
		stu[k].set(num,score);
		k++;
	}
	cout<<average(stu,k);
	return 0;
}
*/
/*
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
} */
/*求两点间的距离
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
/*复数类的操作
#include <iostream>
#include <cmath>
using namespace std;
class Complex
{
private:
	double real,image;
	static int count;
public:
	Complex(double real1,double image1)
	{   real=real1;
		image=image1;
		count++;
	}
	void rev(double &real1,double &image1);
	friend void sum(Complex& c1,Complex& c2);
	friend void sum1(Complex& c1,Complex& c2);
	void print(double r2,double i2) ;
	static int getcount(){return count;}
	
};

void Complex::rev(double &real,double &image)
{
		real=-real;
	 image=-image;
}

void sum(Complex& c1,Complex& c2)
{
//	double dreal=c1.real+c2.real;
//	double dimage=c1.image+c2.image;
	cout<<"("<<c1.real+c2.real<<","<<c1.image+c2.image<<")"<<endl;	
}
void sum1(Complex& c1,Complex& c2)
{
  c2.rev(c2.real,c2.image);
	cout<<"("<<c1.real+c2.real<<","<<c1.image+c2.image<<")";	
}

void Complex::print(double r2,double i2){
	cout<<"("<<r2<<","<<i2<<")"<<endl;
}

int Complex::count=0;
int main()
{ double real1,image1,real2,image2;
cin>>real1>>image1>>real2>>image2;
	Complex c1(real1,image1);
	Complex c2(real2,image2);
	cout<<Complex::getcount()<<endl;
	sum(c1,c2);
	sum1(c1,c2);
	return 0;
	
	
}

*/
/*字符串替换
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a,b,c,m;
	int i,j;
	getline(cin,a);
	while(1){
		getline(cin,m);
		if(m.compare("end")==0)  break;
		a=a+'\n';
		a=a+m;
	}
	a=a;
	getline(cin,b);
	getline(cin,c);
	i=a.find(b);
	while(i!=string::npos)  //npos==-1表示不存在 
	{
		a.replace(i,b.length(),c);
		i=a.find(b,i+1);
	}
	cout<<a;
	return 0;
} 
*/
/*求解给定字符串的前缀
#include<iostream>
using namespace std;
int main()
{
	string s1,s2;
	while(cin>>s1>>s2){
		int flag=0;
		for(int i=0;i<s1.length();i++)
		{
			if(s1.compare(0,i,s2,0,i)==0)
			{
				flag=i;
			}
		}
		if(flag>0) cout<<"The common prefix is "<<s1.assign(s1,0,flag)<<endl;
		else cout<<"No common prefix\n";
	}
	return 0;
		
} 
*/
/*学号解析
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	string s1(s,0,4);
	string s2(s,4,2);
	string s3(s,6,2);
	cout<<"year:"<<s1<<endl;
    cout<<"department:"<<s2<<endl;
    cout<<"class:"<<s3<<endl;
	return 0;	
} 
*/
/*分离目录路径和文件名
#include<iostream>
#include<string>
using namespace std;
void filename(const string & str){
	int found=str.find_last_of("/\\");
	cout<<str.substr(0,found)<<endl;
	cout<<str.substr(found+1)<<endl; 
}
int main()
{
	string str1;
	getline(cin,str1);
	filename(str1);
	return 0;
}
*/
/*验证手机号码
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int i,n;
	char str1[50];
	gets(str1);
	n=strlen(str1);
	if(n!=11)
	{
		cout<<"No!";
		return 0;
	}else{
		for(i=0;i<n;i++)
		{
			if((str1[i]<'0')||(str1[i]>'9'))
			{
				cout<<"No";
				return 0;
			}
		} 
	}
	if(str1[0]!='1')
	{
		cout<<"No";
		return 0;
	 }
	 else cout<<"Yes";
	 return 0;
	 
}
*/
/*从shape类派生出一个直角三角形类RTriangle
#include<iostream>
using namespace std;
#include <iostream>
#include <cmath> 
using namespace std;

class shape {// 抽象类
public:
 virtual double getArea()=0;// 求面积
 virtual double getPerimeter()=0; // 求周长
};
class RTriangle:shape{
	private:
		double w,h;
	public:
		RTriangle(double w1,double h1)
		{
			w=w1;
			h=h1;
		 }
		 double getArea(){
		 	return(w*h/2);
		}
		double getPerimeter(){
			return(w+h+sqrt(w*w+h*h));
		}
};
int main()
{
  double a,b;
  cin>>a>>b;
  RTriangle t(a,b);
  cout<<t.getArea()<<endl;
  cout<<t.getPerimeter()<<endl;	
}
*/
/*从shape类派生出一个圆形类Circle
#include <iostream>
#define PI 3.1415926 
using namespace std;

class shape {
public:
  double getArea(){ return -1; };// 求面积
  double getPerimeter(){ return -1;  }; // 求周长
};

class Circle:shape{
	private:
		double r;
	public:
		Circle(double r1)
		{
			r=r1;
		}
		double getArea()
		{
			return(r*r*PI);
		 }
		 double getPerimeter()
		 {
		 	return(PI*r*2);
		  } 
};

int main() {
  double r;
  cin>>r;
  Circle c(r);
  cout<<c.getArea()<<endl;
  cout<<c.getPerimeter()<<endl;
  return 0;
}
*/
/*计算圆柱体的表面积（函数名隐藏）
#include <iostream>
using namespace std;
const double PI=3.1415926;
class Circle{
protected:
   double radius;
public: 
   Circle(double r){
      radius=r;
   }
   double getArea(){
      return PI*radius*radius;
   }
};
class Cylinder :public Circle{
         double height;             
	public:
		Cylinder(double r1,double h1):Circle(r1)
		{
			height=h1;
		}
		double getArea()
		{
			return PI*radius*radius*height;
		}
};
int main() 
{
   double r,h;
   cin>>r>>h;
   Cylinder Cy1(r,h) ;
   cout<<Cy1.getArea()<<endl;
   return 0;
}
*/
/*从shape类派生出一个正六边形类RHexagon
#include <iostream>
#include <cmath> 
using namespace std;

class shape {// 抽象类
public:
 virtual double getArea()=0;// 求面积
 virtual double getPerimeter()=0; // 求周长
};
class RHexagon:shape{
	private:
		double l;
	public:
		RHexagon(double l1)
		{
			l=l1;
		}
		double getArea()
		{
	    	return(6*pow(3,0.5)/4*l*l); 
		}
		double getPerimeter(){
			return(6*l);
		}
}; 
int main()
{
  double s;
  cin>>s;
  RHexagon p(s);
  cout<<p.getArea()<<endl;
  cout<<p.getPerimeter()<<endl;	
}
*/
/*求平面几何形状的面积（圆形和矩形）C++
#include <iostream>
using namespace std;
class Shape{
public:
    double area ( ){ return -1; }
}; 
class Circle : public Shape{
	private:
		double r;
	public:
		Circle (double r1)
		{
			r=r1;
		}
		double area()
		{
			return(3.14*r*r);
		}
};
class Rectangle : public Shape{
	private:
		double w,h;
	public:
		Rectangle (double w1,double h1)
		{
			w=w1;
			h=h1;
		}
		double area()
		{
			return(h*w);
		}
};
int main()
{
    double r,h,w;
    cin>>r>>h>>w;
    Circle c(r); Rectangle rect(h,w);

    cout<<"The area of the Circle is "<<c.area( )<<endl;
    cout<<"The area of the Rectangle is "<<rect.area( )<<endl;

    return 0;
}
*/
/* Max函数模板
#include <iostream>
#include <string>
using namespace std;
int Max(int a,int b)
{
	return (a>b)?a:b;
}
char Max(char a,char b)
{
	return (a>b)?a:b;
}
string Max(string a,string b)
{
	return (a>b)?a:b;
}

 int main( )
{
  int m,n;
  char c,d;
  string s1,s2;
  cin>>m>>n;
  cin>>c>>d;
  cin>>s1>>s2;
  cout<<Max(m,n)<<endl;
  cout<<Max(c,d)<<endl;
  cout<<Max(s1,s2)<<endl;
    return 0 ;
}
*/
/*创建函数模板实现求数组中的最小元素
#include <iostream>
using namespace std;
template <class T>
T Min(T *p,int len){
	int i;
	T m=p[0];
	for(i=0;i<len;i++)
	{
		if(m>p[i])
		m=p[i];
	}
	return m;
}
int main( )
{
    int n,m,*pn,i=0;
    cin>>n;
    pn=new int[n];
    do{
        cin>>pn[i];
        i++;
    }while(i<n);

    double *pd;
    i=0;
    cin>>m;
    pd=new double[m];
    do{
        cin>>pd[i];
        i++;
    }while(i<m);

    cout<<Min(pn,n)<<endl;
    cout<<Min(pd,m)<<endl;
    delete [ ] pn;
    delete [ ] pd;
    return 0;
}
*/
/*函数模板Swap,实现两个变量交换
#include <iostream>
using namespace std;
//你提交的代码将被嵌入到这里
template<typename T> void Swap(T &a,T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}
int main()
{
 int i,j;
 char m,n;
 cin>>i>>j;
 cin>>m>>n;
 Swap(i,j);
 Swap(m,n);
 cout<<i<<' '<<j<<'\n';
 cout<<m <<' '<<n<<endl;
 return 0;
}
*/
/*函数模板 sort 实现选择法排序的功能
#include<iostream>
using namespace std;
template<typename T>void Mysort(T a[],int n){
	T temp;
	int i,j,k;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[k]) k=j;
			if(i!=k){
				temp=a[i];
				a[i]=a[k];
				a[k]=temp;
			}
		}
	}
}
int main()
{
    int m,n,a[20],i,j;
    float b[20];
    cin>>m;         
    for(i=0;i<m;i++)
        cin>>a[i];
    cin>>n;
    for(j=0;j<n;j++)
        cin>>b[j];
    Mysort(a,m); 
    Mysort(b,n);
    for(i=0;i<m;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    for(j=0;j<n;j++)
        cout<<b[j]<<' ';
    cout<<endl;   
    return 0;   
}
*/
/*人名地名排序
#include<iostream>
#include<string.h>
#include<list>
using namespace std;
int main()
{
	list<string>lis;
	int i,n;
	string s;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s;
		lis.push_back(s);
	 }
	 lis.sort();
	 list<string>::iterator p=lis.begin();
	 while(p!=lis.end())
	 {
	 	cout<<*p<<endl;
	 	p++;
	  } 
	  return 0;
}
*/
/*对字符串进行排序输出
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int i,j,k;
	char t;
	string a;
	getline(cin,a);
	k=a.length();
	for(i=1;i<k;i++)
	{
		for(j=1;j<=(k-i);j++)
		if(a[j]<a[j-1])
		{
			t=a[j];
			a[j]=a[j-1];
			a[j-1]=t;
		}
	}
	cout<<a<<endl;
	return 0; 
}


*/
/*查找成绩并折算后输出
#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<string,int>tex;
	string s,s1;
	int f;
	while(1)
	{
		cin>>s;
		if(s=="noname")
		break;
		cin>>f;
		tex.insert(pair<string,int>(s,f));
		
	}
	cin>>s1;
	map<string,int>::iterator p;
	p=tex.find(s1); 
    if(p!=tex.end() )
	{
		cout<<p->second*0.21<<endl;
		
	}
	else
	cout<<"Not found.";
	return 0;
}
*/
/* 电话号码同步
#include<iostream>
#include<string>
#include<set>
#include <algorithm>
using namespace std;
int main()
{
	set<string> tex;
	string s;
	while(1)
	{
		getline(cin,s);
		tex.insert(s);
		if(s=="end")
		break;
	}
	while(1)
	{
		getline(cin,s);
		tex.insert(s);
		if(s=="end")
		break;
	}
	set<string>::iterator p=tex.begin() ;
	while(p!=tex.end()&&*p!="end")
	{
	
//		cout<<*p<<endl;
//		p++;
//		if(*p!="end")
//		{
			cout<<*p<<endl;
			p++;
			//	}		
	}
	return 0;
}
*/
/*使用类计算矩形的面积
#include <iostream>
using namespace std;

class Rectangle {
public:
    void setLength(int l);//设置矩形的长度
    void setWidth(int w); //设置矩形的宽度
    int getArea();        //计算并返回矩形的面积
private:
    int length, width;    //矩形的长度和宽度	
};

int main()
{
    Rectangle r;
    int len, w;
    cin >> len >> w;
    r.setLength(len);
    r.setWidth(w);
    cout << r.getArea() << "\n";

    return 0;
}
void Rectangle :: setLength(int length1)
{
	length=length1;
}
void Rectangle :: setWidth(int width1) 
{
	width=width1;
}
int Rectangle :: getArea()
{
	return(width*length);
}
*/
/*有序数组（类模板）
#include <iostream>
using namespace std;

template <class T>
class MyArray
{
	private:
		T *data;
		int size;
	public:
		MyArray(int size)
		{
			int i;
			this->size=size;
			data=new T[size];
			for(i=0;i<size;i++)
				cin>>data[i];
		}
		void sort()
		{
			int i,j;
			T t;
			for(i=0;i<size-1;i++)
				for(j=i+1;j<size;j++)
					if(data[i]>data[j])
					{
						t=data[i];
						data[i]=data[j];
						data[j]=t;		
					}
		}
		void display()
		{
			int i;
			for(i=0;i<size;i++)
			{
				cout<<data[i];
				if(i+1<size)
					cout<<" ";				
			}

			cout<<endl;
		}
		bool check();
		~MyArray();
};
template<class T>
MyArray<T>::~MyArray(){ delete[] data;}

template<class T>
bool MyArray<T>::check(){
    int i;
    for(i=0;i<size-1;i++)
        if(data[i]>data[i+1]) { cout<<"ERROR!"<<endl;return false;}
    return true;
}
int main( )
{
    MyArray<int> *pI;
    MyArray<float> *pF;
    MyArray<char> *pC;
    int ty, size;
    cin>>ty;
    while(ty>0){
        cin>>size;
        switch(ty){
            case 1: pI = new MyArray<int>(size);   pI->sort(); pI->check(); pI->display(); delete pI; break;
            case 2: pF = new MyArray<float>(size); pF->sort(); pF->check(); pF->display(); delete pF; break;
            case 3: pC = new MyArray<char>(size);  pC->sort(); pC->check(); pC->display(); delete pC; break;
        }
        cin>>ty;
    }
    return 0;
}
*/
/*抽象类shape类派生出一个正五边形类
#include <iostream>
#include <cmath> 
using namespace std;

class shape {// 抽象类
public:
 virtual double getArea()=0;// 求面积
 virtual double getPerimeter()=0; // 求周长
};
class RPentagon : public shape{
	private:
		double line;
	public:
		 RPentagon(double s)
		{
			line=s;
		}
		double getArea(){
			return(line*line*sqrt(25+10*sqrt(5))/4);
		}
		double getPerimeter(){
			return(5*line);
		}
};
int main()
{
  double s;
  cin>>s;
  RPentagon p(s);
  cout<<p.getArea()<<endl;
  cout<<p.getPerimeter()<<endl;	
}
*/
/*找出足球赛对阵方
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{


    map<string,string> m;

	string s;
	m.insert(pair<string,string>("Australian","Spain"));
	m.insert(pair<string,string>("Spain","Australian"));
	m.insert(pair<string,string>("Holland","Chile"));
	m.insert(pair<string,string>("Chile","Holland"));
	m.insert(pair<string,string>("Cameroon","Brazil"));
	m.insert(pair<string,string>("Brazil","Cameroon"));
    m.insert(pair<string,string>("Croatia","Mexico"));
	m.insert(pair<string,string>("Mexico","Croatia"));
	map<string,string>::iterator p;
   
    cin>>s;
     p=m.find(s);
	 if(p!=m.end())
	 {
	    cout<<s<<" team's rival is "<<p->second<<'.'<<endl;
	   
	 }
	 else
     cout<<s<<"'s team has no match today."<<endl;
	 return 0;
}   	 
    
*/
/*学生成绩cpp计算
#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;

class Person{
public:
    Person();
    Person(string p_name, int p_age);
    void display(){cout << name << ":" << age << endl;}
protected:
    string name;
    int age;
};
Person::Person(){};
Person::Person(string p_name, int p_age){};
class student: public Person{
public:
    student():Person(){}
    student(string name1, int ID1, int age1, float a, float b): Person(name1, age1){
        name = name1;
        ID = ID1;
        age = age1;
        cpp_score = a;
        cpp_count = b;
        cpp_grate = a*0.9 + b*2;
    }
    void print(){
        cout<< ID << " " << name << " " << fixed << setprecision(1) <<cpp_grate<<endl;
    }
private:
    int ID;
    float cpp_score;
    float cpp_count;
    float cpp_grate;
};

int main()
{
    int ID1,age1, i = 0;
    float a,b;
    string s;
    student ss[100];
    cin >> s;

    while(s != "0")
    {

        cin >> ID1 >> age1 >> a >> b;
        // *q = new char('g');

        ss[i] = student (s, ID1, age1, a, b);
        ++i;
        cin>>s;
    }
    int t = i;
    for(i = 0; i < t; i++)
    {
        ss[i].print();
    }
    return 0;
}

*/
/*查找成绩并折算后输出
#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<string,int>tex;
	string s,s1;
	int f;
	while(1)
	{
		cin>>s;
		if(s=="noname")
		break;
		cin>>f;
		tex.insert(pair<string,int>(s,f));
		
	}
	cin>>s1;
	map<string,int>::iterator p;
	p=tex.find(s1); 
    if(p!=tex.end() )
	{
		cout<<p->second*0.21<<endl;
		
	}
	else
	cout<<"Not found.";
	return 0;
}
*/
/*字符串进行排序输出
#include<iostream>
#include<string>
using namespace  std;
int main()
{
     int i,j,k;
     char t;
	 string   a;
     getline(cin,a);
     k=a.length() ;
     for(i=1;i<k;i++)
     for(j=1;j<=(k-i);j++)
     {
     	if(a[j]<a[j-1])
        {
	t=a[j];
	a[j]=a[j-1];
	a[j-1]=t;
        
		}
     	
	 }
	 cout<<a<<endl;
	 return 0;
 }

*/
/*电话号码同步
#include<iostream>
#include<string>
#include<set>
#include <algorithm>
using namespace std;
int main()
{
	set<string> tex;
	string s;
	while(1)
	{
		getline(cin,s);
		tex.insert(s);
		if(s=="end")
		break;
	}
	while(1)
	{
		getline(cin,s);
		tex.insert(s);
		if(s=="end")
		break;
	}
	set<string>::iterator p=tex.begin() ;
	while(p!=tex.end()&&*p!="end")
	{
	
//		cout<<*p<<endl;
//		p++;
//		if(*p!="end")
//		{
			cout<<*p<<endl;
			p++;
			//	}		
	}
	return 0;
}
*/
/*学生考试平均成绩的友元函数
#include<iostream>
#include<string>
using namespace std;
class student
{
	private:
		string num;
		double score;
	public:
			void set(string num1,double score1)
			{
				num=num1;
				score=score1;
			}
	friend double average(student *p,int count);
		
		
}stu[100];
double average(student *p,int count)
{
		double ave;
		double  sum=0;
		int i;
		for(i=0;i<count;i++)
		{
				sum=sum+p[i].score;
				
		}
		ave=sum/count;
		return ave;
		
}
int main()
{
	string num;
	double score;
	int k=0;
	while(1)
	{
		cin>>num;
		if(num=="0")
		break;
		cin>>score;
		stu[k].set(num,score);
		k++;
	}
	cout<<average(stu,k);
	return 0;
}
*/
/*集合相似度
#include<cstdio>
#include<set>
#include<cstdlib>
using namespace std;
const int maxn = 55;
set<int> s[maxn];
int n;
int main() {
    while(~scanf("%d", &n)) {
        int cnt;
        for(int i = 0; i < n; i++) {
            if(!s[i].empty())s[i].clear();
            scanf("%d", &cnt);
            int x;
            for(int j = 0; j < cnt; j++) {
                scanf("%d", &x);
                s[i].insert(x);
            }
        }
        scanf("%d", &cnt);
        int u,v;
        for(int i = 0; i < cnt; i++) {
            scanf("%d%d", &u, &v);
            u--,v--;
            int same = 0;
            int size_s1 = s[u].size();
            int size_s2 = s[v].size();
            set<int>::iterator it;
            for(it = s[u].begin(); it != s[u].end(); it++) {
                if(s[v].find(*it) != s[v].end()) {
                    same++;
                }
            }
            int nc = same;
            int nt = size_s1+size_s2-same;
            double ans = (nc*1.0)/(nt*1.0)*100;
            printf("%.2lf%%\n", ans);
        }
    }
    return 0;
}
*/
/*狗的继承
#include <iostream>
//#include <cmath> 
using namespace std;
class shape{
	public:
		virtual double getAge()=0;
}; 
class Animal:public shape{
	private:
		double age;
	public:
		Animal(double age1)
		{
			age=age1;
		}
		double getAge()
		{
			return(age);
		 } 
}; 
class shape1{
	public:
		virtual double showInfor()=0;
};
class Dog:public shape1{
	private:
		double age;
		string color;
	public:
		Dog(double age1,string color1)
		{
			age=age1;
			color=color1;
		}
		double showInfor(){
			cout<<"age:"<<age;
			cout<<'\n';
			cout<<"color:"<<color;
		}
};

int main(){
	Animal ani(5);
	cout<<"age of ani:"<<ani.getAge()<<endl;
	Dog dog(5,"black");
	cout<<"infor of dog:"<<endl;
	dog.showInfor();
}
*/
/*复数类的操作
#include <iostream>
#include <cmath>
using namespace std;
class Complex
{
private:
	double real,image;
	static int count;
public:
	Complex(double real1,double image1)
	{   real=real1;
		image=image1;
		count++;
	}
	void rev(double &real1,double &image1);
	friend void sum(Complex& c1,Complex& c2);
	friend void sum1(Complex& c1,Complex& c2);
	void print(double r2,double i2) ;
	static int getcount(){return count;}
	
};

void Complex::rev(double &real,double &image)
{
		real=-real;
	 image=-image;
}

void sum(Complex& c1,Complex& c2)
{
//	double dreal=c1.real+c2.real;
//	double dimage=c1.image+c2.image;
	cout<<"("<<c1.real+c2.real<<","<<c1.image+c2.image<<")"<<endl;	
}
void sum1(Complex& c1,Complex& c2)
{
  c2.rev(c2.real,c2.image);
	cout<<"("<<c1.real+c2.real<<","<<c1.image+c2.image<<")";	
}

void Complex::print(double r2,double i2){
	cout<<"("<<r2<<","<<i2<<")"<<endl;
}

int Complex::count=0;
int main()
{ double real1,image1,real2,image2;
cin>>real1>>image1>>real2>>image2;
	Complex c1(real1,image1);
	Complex c2(real2,image2);
	cout<<Complex::getcount()<<endl;
	sum(c1,c2);
	sum1(c1,c2);
	return 0;
	
	
}

*/
//姓名排序
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string a;
	vector<string> s;
	while(1){
		getline(cin,a);
		if(a =="end")
		break;
		s.push_back(a);
	}
	sort(s.begin(),s.end());
	vector<string>::iterator p=s.begin();
	while(p!=s.end())
	{
		cout<<*p<<' ';
		p++;
	}
	cout<<endl;
	return 0;
} 

