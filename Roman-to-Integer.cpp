#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
    cin>>n;
     while(n--)
     {
        string s;
        int sum=0;
         cin>>s;
         unordered_map<char,int>mp={ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

          for(int i=0;i<s.length();i++){
            if(mp[s[i]]<mp[s[i+1]])
             sum-=mp[s[i]];
             else
           sum+=mp[s[i]];
          }

          cout<<sum<<endl;
     } 

}