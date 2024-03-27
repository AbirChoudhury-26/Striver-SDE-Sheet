#include <bits/stdc++.h>
using namespace std;

// Naive Approach

/*
 Steps:

1. Reverse first k elements.
2. Remove from front and add to back (N – K) elements.
*/

// Function to reverse first k elements of a queue
queue<int> reverseFirstK(queue<int> q, int k) {
	solve(q, k);
	int s = q.size() - k;
	while (s-- > 0) {
		int x = q.front();
		q.pop();
		q.push(x);
	}
	return q;
}

void solve(queue<int>& q, int k) {
	if (k == 0) return;
	int e = q.front();
	q.pop();
	solve(q, k - 1);
	q.push(e);
}

// Driver code
int main() {
	queue<int> queue;
	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	queue.push(50);
	queue.push(60);
	queue.push(70);
	queue.push(80);
	queue.push(90);
	queue.push(100);

	int k = 5;
	queue = reverseFirstK(queue, k);

	// Printing queue
	while (!queue.empty()) {
		cout << queue.front() << " ";
		queue.pop();
	}
	return 0;
}

// Using Auxillary stack:

/* Steps:
Create an empty stack.
One by one dequeue first K items from given queue and push the dequeued items to stack.
Enqueue the contents of stack at the back of the queue
Dequeue (size-k) elements from the front and enqueue them one by one to the same queue.

*/


// C++ program to reverse first
// k elements of a queue.
#include <bits/stdc++.h>
using namespace std;

/* Function to reverse the first
K elements of the Queue */
void reverseQueueFirstKElements(int k, queue<int>& Queue)
{
	if (Queue.empty() == true || k > Queue.size())
		return;
	if (k <= 0)
		return;

	stack<int> Stack;

	/* Push the first K elements
	into a Stack*/
	for (int i = 0; i < k; i++) {
		Stack.push(Queue.front());
		Queue.pop();
	}

	/* Enqueue the contents of stack
	at the back of the queue*/
	while (!Stack.empty()) {
		Queue.push(Stack.top());
		Stack.pop();
	}

	/* Remove the remaining elements and
	enqueue them at the end of the Queue*/
	for (int i = 0; i < Queue.size() - k; i++) {
		Queue.push(Queue.front());
		Queue.pop();
	}
}

/* Utility Function to print the Queue */
void Print(queue<int>& Queue)
{
	while (!Queue.empty()) {
		cout << Queue.front() << " ";
		Queue.pop();
	}
}

// Driver code
int main()
{
	queue<int> Queue;
	Queue.push(10);
	Queue.push(20);
	Queue.push(30);
	Queue.push(40);
	Queue.push(50);
	Queue.push(60);
	Queue.push(70);
	Queue.push(80);
	Queue.push(90);
	Queue.push(100);

	int k = 5;
	reverseQueueFirstKElements(k, Queue);
	Print(Queue);
}
