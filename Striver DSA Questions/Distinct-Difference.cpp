#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=3;
    cin>>n;
     vector<int>v(n);
    set<int>left,right;
      for(int i=0;i<n;i++)
      {
       cin>>v[i];
        if(i>0)
          right.insert(v[i]);
      }

//  cout<<left.size()<<" "<<right.size()<<endl;
    // for(auto it1:right)
    //  cout<<it1<<" ";
    // cout<<endl;
     for(int i=0;i<n;i++)
     {
        if(i>0)
        {
          int j=i+1;
           while(j<n)
           {
            right.insert(v[j]);
            j++;
           }
        }
        int a=left.size();
        int b=right.size();
        // cout<<a<<""<<b<<endl;
        cout<<a-b<<" ";
        left.insert(v[i]);
        right.clear();
     }
}