#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
int  n = 13;

string arr[n] = {"john","johnny","jackie","johnny","john",
"jackie","jamie","jamie","john","johnny","jamie",
"johnny","john"};

int ans=0;
string s;
map<string,int>mp;
for(int i=0;i<n;i++)
 mp[arr[i]]++;

for(auto it:mp)
 {
    if(it.second>ans)
    {
        ans=it.second;
        s=it.first;
    }
 }
 cout<<s<<" "<<to_string(ans);

return 0;
}