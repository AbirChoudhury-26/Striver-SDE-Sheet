#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int arr[100],n;
  cout<<"Enter the total numbers:"<<endl;
  cin>>n;

  cout<<"Enter the numbers:"<<endl;
   for(int i=0;i<n;i++)
    cin>>arr[i];

//  for(int i=0;i<n;i++)
//   cout<<arr[i]<<endl;
  int freq[10]={0};

   for(int i=0;i<n;i++){  // 78,78%10=8,78/10=7
     int temp=arr[i];

      while(temp>0)
      {
        int n=temp%10;
        freq[n]++;
        temp=temp/10;
      }
   }

    
  //  for(int j=0;j<=9;j++)
  //   {
  //       cout<<j<<" "<<freq[j]<<endl;
  //   }
   string s="";

   for(int j=9;j>=0;j--)
   {
       while(freq[j]>0)
       {
        s+=to_string(j);
        freq[j]--;
       }
   }

   cout<<"Final Number is:"<<s<<endl;
  return 0;
}