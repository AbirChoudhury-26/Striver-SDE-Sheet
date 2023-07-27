#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  char s[500];
  cout<<"Enter string:";
  cin.getline(s,sizeof(s));

  char *token=strtok(s," ");
   while(token!=NULL)
   {
    cout<<token<<" "<<strlen(token)<<endl;
    token=strtok(NULL," ");
   }

  return 0;
}