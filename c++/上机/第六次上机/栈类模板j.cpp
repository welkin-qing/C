#include<iostream>
using namespace std; 
const int SIZE = 90;
template <class T>
class Stack
{
private:
  T stack[SIZE];
  T *p;
  int top;
public :
Stack()  {top=0;p=new T[SIZE];} 
~Stack()  {delete []stack;}
void push(T n);
T pop();
};
template <class T>
void Stack<T>::push(T n)
{
	top++;
	stack[top]=n;
}
template <class T>
T Stack<T>::pop()
{
	return stack[top];
	top--;
}
/*template <class T>
Stack<T>::Stack()
{
	top=0;
	stack=new T[SIZE];
}*/
/*template <class T>
Stack<T>::~Stack()
{
	delete []stack;
}*/ 
int main()
{
	Stack<int>    x;//定义对象出错，不能用构造函数 
	Stack<char>   y;
	Stack<float>  z;
	x.push(3);
	x.push(4);
	x.push(99);
	y.push('a');
	y.push(68);
	z.push(3.22);
	z.push(5.1);
	cout<<x.pop()<<endl;
	cout<<y.pop()<<endl;
	cout<<z.pop()<<endl;
	return 0;
}

