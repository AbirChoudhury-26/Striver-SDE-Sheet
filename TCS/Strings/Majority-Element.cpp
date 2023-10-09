#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int n;
  cin>>n;
   vector<int>nums(n);

   for(int i=0;i<n;i++)
    cin>>nums[i];

    sort(nums.begin(), nums.end());
        int n = nums.size();
        cout<<nums[n/2];
  return 0;
}