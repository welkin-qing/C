#include<iostream>
using namespace std;
// 你提交的代码将嵌入到这里
template <class T>
void Sort(T *p, int len)
{
	int i,j;
	T m=*p;
	T t;
	for(i=0;i<len-1;i++)
	{
		for(j=i;j<len;j++)
		{
			if(p[i]>p[j])
			{
				t=p[i];
				p[i]=p[j];
				p[j]=t;
			}
		}
	}
	for(i=0;i<len;i++)
	{
		cout<<p[i]<<"\t";
	}
	cout<<"\n";
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
    Sort(pn,n);
    Sort(pd,m);
    delete [ ] pn;
    delete [ ] pd;
    return 0;
}
