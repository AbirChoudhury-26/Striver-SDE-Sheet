#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
void calculateSum(int start,int end, int &sumEven,int &sumOdd)
{
    if(start>end)
     return;

    if(start%2==0)
     sumEven+=start;
    else 
     sumOdd+=start;

    calculateSum(start+1,end,sumEven,sumOdd);
}
int main()
{
  int start,end;
  cin>>start>>end;

  int sumEven=0,sumOdd=0;

  calculateSum(start,end,sumEven,sumOdd);
  cout<<sumEven<<" "<<sumOdd<<endl;
  return 0;
}