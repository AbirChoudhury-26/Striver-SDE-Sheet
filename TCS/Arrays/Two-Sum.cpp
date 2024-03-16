#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n, target;
   cin >> n >> target;
   vector<int> v(n);
   for (int i = 0; i < n; i++)
      cin >> v[i];

   // sort(v.begin(),v.end());
   for (int i = 0; i < n; i++)
   {
      int s = i, e = i + 1;
      if (s >= n)
         break;

      while (e < n)
      {
         if (v[s] + v[e] == target)
         {
            cout << s << " " << e << endl;
            break;
         }
         e++;
      }
   }

   return 0;
}