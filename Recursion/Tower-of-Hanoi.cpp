#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
void towerofHanoi(int n,char beg,char dest,char aux)
{
     if(n==0) 
      return ;
     else{
         towerofHanoi(n-1,beg,aux,dest);
          cout<<n<<" "<<beg<<" "<<dest<<endl;
        towerofHanoi(n-1,aux,dest,beg);
     }
}
int main()
{
  int n=3;
  towerofHanoi(n,'a','b','c');
  return 0;
}