#include <iostream>
using namespace std;
//���ύ�Ĵ��뽫��Ƕ�뵽����
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
