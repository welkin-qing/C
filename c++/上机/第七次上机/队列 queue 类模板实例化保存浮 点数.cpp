#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	queue <float> q;
	
	q.push(12.3);
	q.push(15.8);
	q.push(783.69);
	
	cout << "Number of elements in the queue: " << q.size() << endl;
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
	
	q.push(3.14159265753);
	cout << q.front();
	q.pop();
	if( q.empty())
		cout << " The queue is empty!" << endl;
		
	return 0;
}

