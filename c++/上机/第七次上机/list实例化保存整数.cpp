#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

int main()
{
	list <int> lst;
	int i;
	
	for( i = 0; i < 10; i++)
		lst.push_back(rand());
		
	cout << "Original contents: ";
	
	list <int>::iterator p = lst.begin();
	
	while( p != lst.end()){
		cout << *p<<" ";
		p++;
	}
	cout << endl << endl;
	
	lst.sort();
	cout << "Sorted contents: ";
	p = lst.begin();
	while( p != lst.end()){
		cout << *p<<" ";
		p++;
	}
	cout << endl;
	
	return 0;
}


//#include<iostream>
//#include<list>
//using namespace std;
//int main()
//{
//     list<int>li;
//	 int i;
//	 for(i=0;i<10;i++)   li.push_back(10+i);
//	 list<int>::iterator p=li.begin();
//	 while(p!=li.end())   {cout<<*p<<" ";p++;}
//}

