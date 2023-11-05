#include<iostream>
#include<bits/stdc++.h>
using namespace std;

stack<pair<int,int>>st;

void Push()
{
int min,x;
cin>>x;
 if(st.empty())
  min=x;
 else
  min= std::min(st.top().second,x);
st.push({x,min});
cout<<NULL<<endl;
}

void Pop()
{
  st.pop();
}

int Top()
{
  cout<<st.top().first<<endl;
}
int GetMin()
{
  cout<< st.top().second<<endl;
}

int main()
{
    // Naive approach

    int n;
    
  while(1)
  {
   cout<<"Enter the choice:"<<endl;
   cout<<"\n1:Push\n2:Pop\n3:Top\n4:GetMin\n5:Exit"<<endl;
   cin>>n;
    switch(n)
    {
      case 1:
       Push();
      break;
      case 2:
       Pop();
      break;
      case 3:
       Top();
      break;
      case 4:
      GetMin();
      break;
      case 5:
       exit(0);
        
    }
  }
}