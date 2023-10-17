#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void subsequence(vector<int>v,int ind,vector<int>&ds,int n)
{
 if(ind==n)
  {
    for(auto it:ds)
      cout<<it<<" ";
    cout<<endl;
    return;
  }
  // Pick the elememt
  ds.push_back(v[ind]);
    subsequence(v,ind+1,ds,n);
  ds.pop_back();
  // Remove the element from recursion stack & printing other elements
    subsequence(v,ind+1,ds,n);
}

int main()
{
    vector<int>v{3,2,1};
     vector<int>ds;
     subsequence(v,0,ds,v.size());
}