/* 
#include <iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
 	//string a={"red","yellow","blue","green","white"};
 	//string a{};
 	int i=0;
 	vector<string> s;
 	while(i<5)
 	{
 		//gets(a);
 		getline(cin,a[i]);
 		i++; 
 		s.push_back(a);
	 }
 	
 	sort(s.begin(),s.end());
	vector<string>::iterator p=s.begin();
	cout<<"After sorted:"<<endl;
	while(p!=s.end())
	{
		cout<<*p<<'\n';
		p++;
	}
	cout<<endl;
	return 0;
} 

��int x�����򾭹���c�������*px=0���ɽ�xֵ��Ϊ0�� (2��)
int * px��
int const * px=&x��//ָ������ݲ��� 
int * const px=&x��//���������޸� 
const int * px=&x��
 */
 //���е��඼Ҫ�й��캯������������ 
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char a[5][100];
	for(int i=0;i<5;i++){
		//gets(a[i]);
		cin>>a[i]; 
	}
	for(int i=0;i<5;i++)
	{
		for(int j=i;j<i-1;j++)
		{
			if(strcompare(a[i],a[j]))
			{
				
			}
		}
	}
	cout<<"After sorted:"<<endl;
	for(int i=0;i<5;i++){
		//puts(a[i]); 
		cout<<a[i]<<'\n';
	} 
}	
