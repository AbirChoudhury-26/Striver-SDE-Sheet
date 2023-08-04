#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{ 
    char str[100],temp[100];
    cout<<"Enter Original String:";
    cin.getline(str,sizeof(str));

    cout<<endl;
    cout<<"Enter Rotation string:";
    cin.getline(temp,sizeof(temp));

    char s[200];
     strcpy(s,str);
     strcat(s,str);

     if(strstr(s,temp))
        cout<<"Rotation Exist"<<endl;
     else
      cout<<"Not a valid Rotation"<<endl;

  return 0;
}