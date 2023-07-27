#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string s1="REACTIVE";
    string s2="CREATIVE";
    bool f=true;
    map<char,int>mp1,mp2;

     for(auto it:s1)
      mp1[it]++;
    
     for(auto it:s2)
      mp2[it]++;

     cout<<endl;
    for(auto it:s1)
    {
        if(mp1[it]!=mp2[it])
         {
            f=false;
            break;
         }
    }

    if(f==true)
     cout<<"Anagram"<<endl;
    else
     cout<<"Not an Anagram"<<endl;

  
  return 0;
}