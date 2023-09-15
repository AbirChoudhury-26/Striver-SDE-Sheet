#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
void moveZeroes(vector<int>&nums)
{
 int i=-1;
  for(int j=0;j<nums.size();j++)
  {
     if(nums[j]==0)
     {
        i=j;
        break;
     }
  }

   if(i==-1)
    return;
    
    for(int j=i+1;j<nums.size();j++)
    {
         if(nums[j]!=0)
         {
            swap(nums[i],nums[j]);
            i++;
         }
    }
}

int main()
{
  int n;
   cin>>n;
   vector<int>nums(n);
    for(int i=0;i<n;i++)
     cin>>nums[i];

    moveZeroes(nums);
     for(int i=0;i<n;i++)
      cout<<nums[i]<<" ";
  return 0;
}