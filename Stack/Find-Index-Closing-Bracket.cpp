
#include <bits/stdc++.h>
using namespace std;

void test(string expression, int index){
	int i;
	
	// If index given is invalid and is 
	// not an opening bracket.
	if(expression[index]!='['){
		cout << expression << ", " <<
					index << ": -1\n";
		return;
	}
	
	stack <int> st;
	
	for(i = index; i < expression.length(); i++){
		
		// If current character is an 
		// opening bracket push it in stack.
		if(expression[i] == '[')
		st.push(expression[i]);
		
		// If current character is a closing
		// bracket, pop from stack. If stack 
		// is empty, then this closing
		// bracket is required bracket.
		else if(expression[i] == ']'){
			st.pop();
			if(st.empty()){
				cout << expression << ", " << 
					index << ": " << i << "\n";
				return;
			}
		}
	}
	cout << expression << ", " <<
				index << ": -1\n";
}

// Driver Code
int main() {
	test("[ABC[23]][89]", 0); // should be 8
	test("[ABC[23]][89]", 4); // should be 7
	test("[ABC[23]][89]", 9); // should be 12
	test("[ABC[23]][89]", 1); // No matching bracket
	return 0;
}

