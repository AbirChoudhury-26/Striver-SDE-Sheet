#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 struct item{
    int weight;
    int value;
 };

 bool comparision(item a,item b)
 {
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;

    return r1>r2;
 }

 double fractionalknapsack(item arr[],int W,int n)
 {
     sort(arr,arr+n,comparision);
    //   for(int i=0;i<n;i++)
    //    cout<<arr[i].value<<" ";
    //   cout<<endl;
     int currweight=0;
     double finalvalue=0.0;

     for(int i=0;i<n;i++)
     {
         if(currweight+arr[i].weight <= W)
         {
             currweight+=arr[i].weight;
             finalvalue+=arr[i].value;
         }
         else{
            int remaining=W-currweight;
             finalvalue += (arr[i].value/(double)arr[i].weight) *(double)remaining;
             break;
         }
     }
      return finalvalue;
     
 }

 int main()
 {
    int n,W;
     cin>>n>>W;
    item arr[n];
     for(int i=0;i<n;i++)
      cin>>arr[i].weight>>arr[i].value;

    double ans= fractionalknapsack(arr,W,n);
     cout<<setprecision(2)<<fixed<<ans<<endl;
 }