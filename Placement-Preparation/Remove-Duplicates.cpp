#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  char str[1000];
   cin.getline(str,sizeof(str));
//   cout<<str<<endl;
//   char temp[1000];
//    cin.getline(temp,sizeof(temp));
  
  unordered_map<string,int>mp;

   char *token=strtok(str," ");
    while(token!=NULL)
    {
        mp[token]++;
        token=strtok(NULL," ");

    }

    for(auto it:mp)
    {
     cout<<it.first<<" "<<it.second;
     cout<<endl;
    }
 
    // char *ans=strtok(temp," ");
    //  while(ans!=NULL)
    //  {
    //     if(mp[ans]==1)
    //      cout<<ans<<" ";

    //     ans=strtok(NULL," ");
    //  }
    return 0;
}