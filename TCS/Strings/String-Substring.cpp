#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
   std::string haystack = "It is like looking for a needle in a haystack";
    std::string needle = "needle";
 
    const char* found = strstr(haystack.c_str(), needle.c_str());
 
    if (found) {
        std::cout << "String found" << std::endl;
    }
    else {
        std::cout << "String not found" << std::endl;
    }
 
    return 0;
  return 0;
}