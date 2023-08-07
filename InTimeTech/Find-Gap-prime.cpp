#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
    if (x <= 1)
        return false;
    for (int i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
        {
            return false;
            break;
        }
    }
    return true;
}

void find_gap(int a, int b, int gap)
{
    vector<int> ans;
    set<int> s;
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
            ans.push_back(i);
    }
    // for (auto it : ans)
    //     cout << it << " ";
    // cout << endl;

    
    for (int i = 0; i < ans.size(); i++)
    {
        int n = ans[i] + gap;
        auto it = find(ans.begin(), ans.end(), n);
        if (it != ans.end())
        {
            cout << ans[i] << " " << *it << endl;
            break;
        }
    }
}
int main()
{
    int a, b, gap;
    cin >> a >> b >> gap;
    find_gap(a, b, gap);

    return 0;
}

// #include<bits/stdc++.h>

// int searchResult(std::vector<int> arr, int k){
//     std::vector<int>::iterator it;
//     it = std::find(arr.begin(), arr.end(), k);
//     if(it != arr.end())
//         return *it;
//     else
//         return -1;
// }

// int main(){
//     std::vector<int> arr = {1, 2, 3, 4, 5, 6};
//     int k = 4;
//     std::cout << searchResult(arr, k) << std::endl;
//     return 0;
// }
