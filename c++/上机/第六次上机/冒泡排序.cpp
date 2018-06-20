#include <iostream>
using namespace std;

//√∞≈›≈≈–Ú∑®
template<typename T>
void sort(T *data, int n)
{
 int i, j;
 T t;
 for (i = 0; i < n - 1; i++)
 {
  for (j = 0; j < n -1; j++)
  {
   if (data[j] > data[j+1])
   {
    t = data[j];
    data[j] = data[j+1];
    data[j+1] = t;
   }
  }
 }

}

int main()
{
 int i;
 int a[] = {3, 7, 1, 9, 2 ,7};
 
 double c[] = {1.5, 5.1, 1.7};

 sort(a, 6);
 	for (i = 0; i < 6; i++)
    cout << a[i] << " ";
	cout << endl;

 
 sort(c, 3);
		for (i = 0; i < 3; i++)
		cout << c[i] << " ";
		cout << endl;

 		return 0;
}
