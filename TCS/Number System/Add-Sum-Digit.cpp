#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
 // Brute force- Add all the digit until a Single digit is obtained by using while loop & replacing the value

int main()
{
//   int n;
// cin>>n;

// int num=n;

//  while(num>9)
//  {
//     int temp=0;
//      while(num>0)
//      {
//         temp+=num%10;
//         num/=10;
//      }
//      num=temp;
//  }

//  cout<<num<<endl;
//   return 0;

// Second Approach - Observation 
// We see for first 100 Numbers, each set of 9 Numbers are repeated with sum from 1-9.
// Therefore we can build a logic of Modulo 9 & hence the remainder will be our answer,
// One edge case Need to take care- On Modulo 9, if we get 0 theat means it is Perfectly divisible by 9 ,hence digit os um will be 9 only.

 int num;
cin>>num;

 if(num==0)
  cout<<0<<endl;
else if(num%9==0)
 cout<<9<<endl;
else
 cout<<num%9<<endl;
 
}