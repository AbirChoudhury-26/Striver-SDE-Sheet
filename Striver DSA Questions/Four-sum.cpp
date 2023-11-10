#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    //  Using 2 pointer only 
    int n,sum;
     cin>>n>>sum;
      vector<int>v(n);
      vector<vector<int>>res;

      for(int i=0;i<n;i++)
       cin>>v[i];
    sort(v.begin(),v.end());

 for(int i=0;i<n;i++)
 {
    for(int j=i+1;j<n;j++)
    {
        int target= sum-(v[i]+v[j]);
         int f=j+1,l=n-1;
         
          while(f<l)
          {
            if(target==(v[f]+v[l]))
            {
             vector<int>quad(4,0);
              quad[0]=v[i];
              quad[1]=v[j];
              quad[2]=v[f];
              quad[3]=v[l];
               res.push_back(quad);

                while ( f< l && v[f] == quad[2]) f++;
                    
                        // Processing the duplicates of number 4
                        while ( f< l && v[l] == quad[3]) --l;
            }
            else if(target>(v[f]+v[l]))
             l--;
            else 
             f++;
          }
          while(j+1<n && v[j+1]==v[j])
           j++;
    }
    while(i+1<n && v[i+1]==v[i])
     i++;
 }

   for(int i=0;i<res.size();i++)
   {
    for(int j=0;j<res[i].size();j++)
     cout<<res[i][j]<<" ";
    cout<<endl;
   }
 }