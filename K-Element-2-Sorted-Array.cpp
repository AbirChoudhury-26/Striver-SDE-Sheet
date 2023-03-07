#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 int main()
 {
    int m,n,k;
     cin>>m>>n>>k;
      vector<int>array1(m),array2(n);
       for(int i=0;i<m;i++)
        cin>>array1[i];
    for(int i=0;i<n;i++)
     cin>>array2[i];

   int p1=0,p2=0,counter=0,answer=0;

   while(p1<m && p2 <n)
   {
     if(counter == k) break;
        else if(array1[p1]<array2[p2]) {
            answer = array1[p1];
            ++p1;
        }
        else {
            answer = array2[p2];
            ++p2;
        }
        ++counter;
   }

       if(counter != k) {
        if(p1 != m-1) 
            answer = array1[k-counter];
        else 
            answer = array2[k-counter];
    }

 cout<<answer<<endl;

 }