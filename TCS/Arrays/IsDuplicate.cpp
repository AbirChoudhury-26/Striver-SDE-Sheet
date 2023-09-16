#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int n;
  cin>>n;
  vector<int>v(n);
   set<int>s;
   bool f=false;
   for(int i=0;i<n;i++)
    cin>>v[i];
   
    for(int i=0;i<n;i++)
    {
         if(s.find(v[i])!=s.end())
         {
            f=true;
            break;
         }
        s.insert(v[i]);
    }
    if(f)
     cout<<f<<endl;
    else
     cout<<f<<endl;

  
  return 0;
}