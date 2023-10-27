#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
     cin>>n;
      vector<int>arr(n),dep(n);
       for(int i=0;i<n;i++)
        cin>>arr[i];
       for(int i=0;i<n;i++)
        cin>>dep[i];

    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());

  int ans=1,count=1,i=1,j=0;
   while(i<n && j<n)
   {
     if(arr[i]<=dep[j])
      {
        count++;
         i++;
      }
      else
      {
        count--;
         j++;
      }

      ans=max(ans,count);
   }

    cout<<ans<<endl;
}