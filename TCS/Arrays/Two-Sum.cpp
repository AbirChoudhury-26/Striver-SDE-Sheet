#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int n,target;
   cin>>n>>target;
vector<int>v(n);
 for(int i=0;i<n;i++)
  cin>>v[i];

 //sort(v.begin(),v.end());
 int s=0,e=1,sum=v[0]+v[1];
   while(s<e)
   {
      if(v[s]+v[e]==target)
      {
         cout<<s<<" "<<e<<endl;
         break;
      }
      else if(v[s]+v[e]<target)
       e++;
      else 
       s++;
   }

  return 0;
}