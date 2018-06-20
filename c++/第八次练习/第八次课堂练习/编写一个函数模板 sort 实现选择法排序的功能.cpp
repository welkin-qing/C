#include<iostream>
using namespace std;
//你提交的代码将被嵌入到这里
template<class T> void Mysort(T a[],int n)
{
	T temp;
	int i,j,k;
	for( i=0;i<n;i++)
	{
		k=i;
		for( j=i+1;j<n;j++)
			if(a[j]<a[k]) k=j;
			if(i!=k) 
			{
				temp=a[i];
				a[i]=a[k];
				a[k]=temp;
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
