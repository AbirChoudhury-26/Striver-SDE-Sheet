#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   stack<int>st;
   vector<int>v(n);
    for(int i=0;i<n;i++)
    {
    cin>>v[i];
     st.push(v[i]);
    }
    // st.push(1);
    // st.push(2);
    // st.push(5);
    // st.push(10);
    while(st.empty()==false)
    {
     cout<<st.top()<<" ";
      st.pop();
    }
}
