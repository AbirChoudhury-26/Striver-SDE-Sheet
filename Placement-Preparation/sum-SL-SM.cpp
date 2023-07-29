#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int n;
   cin>>n;
   int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];

  int sl=INT_MIN,l=INT_MIN,ss=INT_MAX,s=INT_MAX;

   for(int i=0;i<n;i++)
   {
     if(i%2==0)
     {
        if(a[i]>l)
        {
            sl=l;
            l=a[i];
        }
        else if(a[i]< l && a[i]>sl)
         sl=a[i];
     }
     else{
        if(a[i]<s)
        {
            ss=s;
            s=a[i];
        }
        else if(a[i]>s && a[i]<ss)
         ss=a[i];
     }
   }

   cout<<ss+sl<<endl;
  return 0;
}