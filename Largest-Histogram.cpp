#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Normal Approach

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // int maxarea = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     int minheight = INT_MAX;
    //     for (int j = i; j < n; j++)
    //     {
    //         minheight = min(minheight, v[j]);
    //         maxarea = max(maxarea, minheight * (j - i + 1));
    //     }
    // }
    // cout << maxarea << endl;

    //  2nd Optimal Approach: using left and Right Smaller


   stack<int>st;

   vector<int>leftsmall(n),rightsmall(n);

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && v[st.top()]>=v[i])
         st.pop();

        if(st.empty())
         leftsmall[i]=0;
        else{
            leftsmall[i]=st.top()+1;
        }
        st.push(i);
    }

    for(int i=n-1;i>0;i--)
    {
        while(!st.empty() && v[st.top()]>=v[i])
         st.pop();

        if(st.empty())
         rightsmall[i]=n-1;
        else{
            rightsmall[i]=st.top()-1;
        }
            st.push(i);
    }

    int maxarea=0;

     for(int i=0;i<n;i++)
      maxarea=max(maxarea,v[i]*(rightsmall[i]-leftsmall[i]+1));
 cout<<maxarea<<endl;

}