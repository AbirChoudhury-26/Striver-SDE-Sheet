
/* Steps:
Initialize a stack, say S, to keep track of the score and initially push 0 into the stack.
Traverse the string str using the variable i and perform the following steps:
If the value of str[i] is equal to ‘(‘, push 0 to the stack S.
Otherwise, perform the following steps:
Store the top of the stack S in a variable, say temp, and pop the element from the top of the stack.
If the value of temp is non-zero, then inner parentheses exist. Add 2 * temp to the top of the stack. Otherwise, add 1 to the top of the stack.

*/
#include <bits/stdc++.h>
using namespace std;


void scoreOfParentheses(string s)
{
	// To keep track of the score
	stack<int> stack;

	// Initially, push 0 to stack
	stack.push(0);

	// Traverse the string s
	for (char c : s) {

		// If '(' is encountered,
		// then push 0 to stack
		if (c == '(')
			stack.push(0);

		// Otherwise
		else {

			// Balance the last '(', and store
			// the score of inner parentheses
			int tmp = stack.top();
			stack.pop();

			int val = 0;

			// If tmp is not zero, it means
			// inner parentheses exists
			if (tmp > 0)
				val = tmp * 2;

			// Otherwise, it means no
			// inner parentheses exists
			else
				val = 1;

			// Pass the score of this level
			// to parent parentheses
			stack.top() += val;
		}
	}

	// Print the score
	cout << stack.top();
}

// Driver Code
int main()
{
	string S = "(()(()))";
	scoreOfParentheses(S);

	return 0;
}
