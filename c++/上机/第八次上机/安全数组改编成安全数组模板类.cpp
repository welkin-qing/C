#include <iostream>
#include <cstdlib>
using namespace std;
const int SIZE = 3;
class atype {
   int a[SIZE];
public:
  atype( ) {
     register int i;
     for(i=0; i<SIZE; i++) a[i] = i;
  }
   int &operator[](int i);
};
int &atype::operator[](int i)
{
   if(i<0 || i> SIZE-1) {
      cout << "\nIndex value of ";
      cout << i << " is out-of-bounds.\n";
      exit(1);
   }
   return a[i];
}
int main( )
{
   atype ob;
  cout << ob[2];  // ��� 2
   cout << " ";
   ob[2] = 25;  // �±������[]�����ڸ�ֵ����������
   cout << ob[2];  // ��� 25
   ob[3] = 44; // ��������ʱ�����±�3����������߽�
   return 0;
}
