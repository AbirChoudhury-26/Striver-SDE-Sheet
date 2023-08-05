#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int n,m;
   cin>>n>>m;
   int sum1=0,sum2=0;

    for(int i=1;i<=n;i++)
    {
        if(i%m==0)
         sum1+=i;
        else
         sum2+=i;
    }

    cout<<sum2-sum1<<endl;
  return 0;
}