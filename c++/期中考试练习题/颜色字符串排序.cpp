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

设int x；，则经过（c）后，语句*px=0；可将x值置为0。 (2分)
int * px；
int const * px=&x；//指向的内容不变 
int * const px=&x；//用来限制修改 
const int * px=&x；
 */
 //所有的类都要有构造函数和析构函数 
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
