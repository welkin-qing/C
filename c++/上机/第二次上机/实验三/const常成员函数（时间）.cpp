#include<iostream>
#include<cstring>
using namespace std;
class Date {  
	int d, m, y; 
public:
	Date(int y1,int m1,int d1)
		{
			y=y1;
			m=m1;
			d=d1;
		}  
	int day( ) const { 
		return d; 
	}  
	int month( ) const {
	 	return m; 
	 }  
	int year( ) const;  // ... 
}; 
	 // const �Ǻ���ԭ�͵�һ����ɲ��֣�����ں������岿��ҲҪ�� const �ؼ��֡� 
inline int Date::year( ) const {
	return y; 
} 
int main()
{
	Date date(2018,3,21);
	cout<<"Get year month and day: "<<endl;
	cout<<"Year: "<<date.year()<<" month: "<<date.month()<<" day: "<<date.day();
}
