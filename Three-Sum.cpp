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
        vector<vector<int>>ans;

         sort(v.begin(),v.end());

          for(int i=0;i<v.size();i++)
          {
             if(i==0 || (i>0 && v[i]!=v[i-1]))
             {
              int low=i+1,high=v.size()-1,sum=0-v[i];

                while(low<high)
                {
                  if(v[low]+v[high]==sum)
                  {
                      vector<int>temp;
                       temp.push_back(v[i]);
                       temp.push_back(v[low]);
                       temp.push_back(v[high]);
                        ans.push_back(temp);
                         while(low<high && v[low]==v[low+1])low++;
                          while(low<high & v[high]==v[high-1])high--;
                        low++;
                        high--;
                  }
                  else if(v[low]+v[high]<sum) low++;
                  else high--;
                }
             }
          }
           cout<<"Triplets are:"<<endl;
           for(int i=0;i<ans.size();i++)
           { 
            for(int j=0;j<ans[i].size();j++)
             cout<<ans[i][j]<<" ";
            cout<<endl;
           }
 }