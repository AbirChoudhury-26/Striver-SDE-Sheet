#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	 cin>>n;
	 
	 while(n--)
	 {
	     string s;
	     int num=0,lower=0,upper=0,special=0;
	     cin>>s;
	     
	     if(s.length()<10)
	        cout<<"NO"<<endl;
	     else
	       {
	         for(int i=0;i<s.length();i++)
	         {
	          if(s[i]>='a' && s[i]<='z')
	           lower++;
	           
	           if(i>0 && i< s.length()-1)
	           {
	               if(s[i]>='a' && s[i]<='z')
	                lower++;
	               else if(s[i]>='A' && s[i]<='Z')
	                upper++;
	               else if(s[i]>='0' && s[i]<='9')
	                num++;
	               else
	                special++;
	           }
	         }
	     if(num>0 && lower>0 && upper>0 && special>0 )
	       cout<<"YES"<<endl;
	      else
	       cout<<"NO"<<endl;
	       }
	      
	    
	 }
	return 0;
}
