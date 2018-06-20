#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	queue <string> q;
	
	q.push( "C++ programming ");
	q.push( "with STL ");
	q.push( "is fun.");
	
	cout << "Number of elements in the queue: " << q.size() << endl;
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
	
	q.push( " Enjoy it!");
	cout << q.front();
	q.pop();
	if( q.empty())
		cout << " The queue is empty!" << endl;
		
	return 0;
}

