#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
   char str[] = { "abbba" };
 
    // Start from first and
    // last character of str
    int l = 0;
    int h = strlen(str) - 1;
 
    // Keep comparing characters
    // while they are same
    while (h > l) {
        if (str[l++] != str[h--]) {
            printf("%s is not a palindrome\n", str);
            return 0;
            // will return from here
        }
    }
 
    printf("%s is a palindrome\n", str);
  return 0;
}