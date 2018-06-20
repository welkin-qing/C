#include <iostream>
using namespace std;
/* ���ύ�Ĵ��뽫Ƕ�뵽���� */
double hmean(double a, double b) 
{
	if((a+b)==0)
	throw("bad hmean() arguments: a = -b not allowed");
	return(2*a*b/(a+b));
}


int main()
{
    double x, y;
    cin >> x >> y; 
    try {
          cout<<hmean(x,y);
    }
    catch (const char * s)
    {
        cout << s << endl;
    }
    return 0;
}

