#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    int n;
      cin>>n;
      vector<int>v(n);
      set<int>s;
       for(int i=0;i<n;i++)
       {
        cin>>v[i];
        s.insert(v[i]);
       }
   
       int longstreak=0;
       int currentstreak;
        for(auto num:v){
            if(!s.count(num-1))
            {
                int current=num;
                 currentstreak=1;

                 while(s.count(current+1))
                 {
                    current++;
                    currentstreak++;
                 }
            }
            longstreak= max(longstreak,currentstreak);
        }
         
          cout<<longstreak<<endl;
    
 }