#include <iostream>
using namespace std;
// ���ύ�Ĵ��뽫Ƕ�뵽����
template <class T>
T Min(T *p, int len)
{
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
