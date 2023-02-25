#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    stack<int> st, st1, ans;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        st.push(v[i]);
    }
    //    while(!st.empty()){
    //     cout<<st.top()<<" ";
    //       st.pop();
    st1.push(st.top());
    st.pop();
     ans.push(-1);
    while (!st.empty())
    {

        while (!st1.empty() && st.top() < st1.top())
            st1.pop();
        if (st1.empty())
            ans.push(-1);
        else
            ans.push(st1.top());
        st1.push(st.top());
        st.pop();
    }
    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    
}