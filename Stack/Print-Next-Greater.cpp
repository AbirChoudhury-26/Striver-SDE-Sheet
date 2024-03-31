/* Naive Approach

*/
#include <bits/stdc++.h>
using namespace std;

void next_greater(int arr[], int query[], int n, int q)
{

    for (int i = 0; i < q; i++)
    {

        int k = query[i];
        // To detect next greater element is present or not
        bool val = false;
        // Loop for checking next greater of each query
        for (int j = k + 1; j < n; j++)
        {
            if (arr[j] > arr[k])
            {
                cout << arr[j] << " ";
                // Make val true when there exist a next greater element
                val = true;
                break;
            }
        }

        // If next greater element is not present
        if (val == false)
        {
            cout << -1 << " ";
        }
    }
}

// Driver Code
int main()
{
    // Given Numbers
    int arr[] = {3, 4, 2, 7, 5, 8, 10, 6};
    // Queries
    int query[] = {3, 6, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    int q = sizeof(query) / sizeof(query[0]);

    next_greater(arr, query, n, q);
}


/* Efficient Approach*/


/* Steps:

1) Push the first index to stack. 
2) Pick rest of the indexes one by one and follow following steps in loop. 
    a) Mark the current element as i. 
    b) If stack is not empty, then pop an index from stack and compare a[index] with a[I]. 
    c) If a[I] is greater than the a[index], then a[I] is the next greater element for the a[index]. 
    d) Keep popping from the stack while the popped index element is smaller than a[I]. a[I] becomes the next greater element for all such popped elements 
    g) If a[I] is smaller than the popped index element, then push the popped index back.
3) After the loop in step 2 is over, pop all the index from stack and print -1 as next index for them.

*/


// C++ program to print 
// next greater number 
// of Q queries
#include <bits/stdc++.h>
using namespace std;

// array to store the next
// greater element index
void next_greatest(int next[], 
				int a[], int n)
{
	// use of stl 
	// stack in c++
	stack<int> s;

	// push the 0th 
	// index to the stack
	s.push(0);

	// traverse in the 
	// loop from 1-nth index
	for (int i = 1; i < n; i++)
	{

		// iterate till loop is empty
		while (!s.empty()) {

			// get the topmost 
			// index in the stack
			int cur = s.top();

			// if the current element is 
			// greater than the top indexth 
			// element, then this will be 
			// the next greatest index 
			// of the top indexth element
			if (a[cur] < a[i])
			{
				
				// initialise the cur 
				// index position's 
				// next greatest as index
				next[cur] = i;

				// pop the cur index 
				// as its greater 
				// element has been found
				s.pop();
			}

			// if not greater
			// then break
			else
				break;
		}
		// push the i index so that its 
		// next greatest can be found
		s.push(i);
	}

	// iterate for all other 
	// index left inside stack
	while (!s.empty()) 
	{
		int cur = s.top();

		// mark it as -1 as no 
		// element in greater
		// then it in right
		next[cur] = -1;

		s.pop();
	}
}

// answers all 
// queries in O(1)
int answer_query(int a[], int next[], 
				int n, int index)
{
	// stores the next greater
	// element positions
	int position = next[index];

	// if position is -1 then no 
	// greater element is at right.
	if (position == -1)
		return -1;

	// if there is a index that
	// has greater element 
	// at right then return its
	// value as a[position]
	else
		return a[position];
}

// Driver Code
int main()
{

	int a[] = {3, 4, 2, 7, 
			5, 8, 10, 6 };

	int n = sizeof(a) / sizeof(a[0]);

	// initializes the
	// next array as 0
	int next[n] = { 0 };

	// calls the function
	// to pre-calculate 
	// the next greatest 
	// element indexes
	next_greatest(next, a, n);

	// query 1 answered
	cout << answer_query(a, next, n, 3) << " ";

	// query 2 answered
	cout << answer_query(a, next, n, 6) << " ";

	// query 3 answered
	cout << answer_query(a, next, n, 1) << " ";
}
