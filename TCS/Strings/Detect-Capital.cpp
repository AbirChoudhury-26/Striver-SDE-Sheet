#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool detectCapitalUse(string word) {
        int c=0,c2=0;
        for (int i = 1; i < word.size();i++){
            if (isupper(word[0]) !=isupper(word[i])){
                c=1;
            }
        }
        if(c==0){
            return true;
        }
        if(isupper(word[0])){
            for (int i=1;i<word.size();i++){
                if(isupper(word[i])){
                    return false;
                }
                else{
                    c2++;
                }
            }
        }
        if(c2==word.size() - 1){
            return true;
        }
        if(c){
            return false;
        }
        return true;
    }

int main()
{
  string s;
  cin>>s; 

  bool ans=detectCapitalUse(s);
  cout<<ans<<endl;
  return 0;
}