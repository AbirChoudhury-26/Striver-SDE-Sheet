#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[50];
     gets(str);

    strrev(str);
    cout<<str<<endl;

    char *token=strtok(str," ");

     while(token!=NULL)
     {
        strrev(token);
        cout<<token<<" ";
        token=strtok(NULL," ");
     }

}