#include<iostream>
#include<string>

using namespace std;


const int SIZE = 90; 
template<typename T> class Stack 
{ 
	public : 
	Stack()
	{
		tos=0;
	}
	void push(T n); 
	T pop(); 
	void print()
	{
		for(int i=0;i<tos;i++)
		cout<<stack[i]<<' ';
		cout<<endl;
	}
	private: 
	T stack[SIZE]; 
	int tos; 
};

// ÈëÕ»
template<typename T> void Stack<T> ::push(T n)
{
	if(tos==SIZE)
	{
		cout<<"Õ»Âú"<<endl;
		return ; 
	}
	stack[tos]=n;
	tos++;
}

//³öÕ»
template<typename T> T Stack<T> ::pop()
{
	if(tos==0)
	{
		cout<<"Õ»¿Õ"<<endl;
		return 0;
	}
	tos--;
	return stack[tos];
 } 

int main()
{
	Stack<int> a;
	a.push(10);
	a.push(20);
	a.print();
	
	Stack<double> b;
	b.push(90.213);
	b.push(234.56);
	b.push(76856.232);
	b.print();
	cout<<b.pop()<<endl;
	b.print();
	
	Stack<string> str;
	str.push("Hello");
	str.push("World");
	str.push("!");
	str.print();
	
	return 0;
}

