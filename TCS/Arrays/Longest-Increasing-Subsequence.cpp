#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int n;
   cin>>n;
   vector<int>v(n);
    for(int i=0;i<n;i++)
     cin>>v[i];

    int s=0,e=0,ans=1;
      for(int i=1;i<n;i++)
      {
         if(v[i]>v[e]) 
         {
          e=i;
          ans=max(ans,(e-s)+1);
         }
        else
        {
         s=i,
         e=i;
        }

        
      }

      cout<<ans;
  return 0;
}