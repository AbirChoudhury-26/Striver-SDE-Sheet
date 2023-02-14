#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int main()
 {

    // Using Array Method
    
    int pairs=0;
    int n;
     cin>>n;
      vector<int>v(n);
       for(int i=0;i<n;i++)
        cin>>v[i];
      for(int i=0;i<v.size();i++)
      {
        for(int j=i+1;j<v.size();j++)
        {
             if(v[i]>2*v[j])
              pairs++;
        }
      }
      cout<<pairs<<endl;
 }