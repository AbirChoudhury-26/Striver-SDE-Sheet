// C++ program to find duplicate parenthesis in a
// balanced expression
#include <bits/stdc++.h>
using namespace std;


bool findDuplicateparenthesis(string str)
{
	// create a stack of characters
	stack<char> Stack;

	// Iterate through the given expression
	for (char ch : str)
	{
		// if current character is close parenthesis ')'
		if (ch == ')')
		{
			// pop character from the stack
			char top = Stack.top();
			Stack.pop();

			int elementsInside = 0;
			while (top != '(')
			{
				elementsInside++;
				top = Stack.top();
				Stack.pop();
			}
			if(elementsInside < 1) {
				return 1;
			}
		}

	
		else
			Stack.push(ch);
	}

	// No duplicates found
	return false;
}


// Driver code
int main()
{
	// input balanced expression
	string str = "(((a+(b))+(c+d)))";

	if (findDuplicateparenthesis(str))
		cout << "Duplicate Found ";
	else
		cout << "No Duplicates Found ";

	return 0;
}
