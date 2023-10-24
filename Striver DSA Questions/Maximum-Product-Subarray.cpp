#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 // Maximum products of all the possible numbers in array 

int ProductSubArray(vector<int>&nums)
{
  int left=nums[0],right=nums[0],prod=1;
   bool zeroPresent=false;

   // Left Side traversal

    for(auto it:nums)
    {
        prod*=it;

         if(it==0)
          {
            zeroPresent=true;
            prod=1;
            continue;
          }

          left=max(left,prod);
    }
     prod=1;
    // Right side traversal

     for(int j=nums.size()-1;j>=0;j--)
     {
     prod*=nums[j];
      if(nums[j]==0)
       {
        zeroPresent=true;
        prod=1;
        continue;
       }

       right=max(right,prod);
     }


  if(zeroPresent)
   return max(max(left,right),0);
  else 
   return max(left,right);
}

int main()
{
  vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<ProductSubArray(nums);
  return 0;
}