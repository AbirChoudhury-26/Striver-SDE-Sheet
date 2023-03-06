#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool ispossible(vector<int>a,int pages,int b)
 {
    int count=0,sumallocate=0;
     for(int i=0;i<a.size();i++)
     {
        if(sumallocate+a[i]>pages)
        {
            count++;
             sumallocate=a[i];
              if(sumallocate>pages) 
               return  false; 
        }
        else
         sumallocate+=a[i];
     }

     if(count<b)
      return true;
    else
     return false;
 }

int books(vector<int>a,int b)
{
   if(b>a.size())
    return -1;
 int low=a[0],high=0;

  for(int i=0;i<a.size();i++)
   {
    high+=a[i];
    low=min(low,a[i]);
   }

   while(low<=high)
   {
     int mid=(low+high)>>1; // This means right shift two 
     if(ispossible(a,mid,b))
      high=mid-1;
     else 
      low=mid+1;
   }
    return low;
}

int main()
{
    int n,b;
    cin>>n>>b;
    vector<int>v(n);
     for(int i=0;i<n;i++)
      cin>>v[i];
    
     cout<<books(v,b);
      
}