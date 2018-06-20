#include<iostream>
using namespace std;
const int SIZE = 90; 
class Stack { 
	public : 
		Stack(); 
		~Stack();
 		void push(int n); 
		int pop(); 
	private: 
		int stack[SIZE]; 
		int tos; 
}; 
int main()
{
	
} 
