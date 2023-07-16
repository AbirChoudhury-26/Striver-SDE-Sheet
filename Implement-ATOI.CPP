#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int atoi(string s){
int sum=0;
  for(int i=0;i<s.size();i++)
  {
if(s[i]>='0' && s[i]<='9')
 sum=sum*10 +s[i]-'0';
  }

  if(s[0]=='-')
   return -sum;
else
 return sum;
}

int main()
{
    int n;
    cin>>n;
    while(n--);`
    {
        string s;
        cin>>s;
        int ans=atoi(s);
        cout<<ans<<endl;
        
    }
}