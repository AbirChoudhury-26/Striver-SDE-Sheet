#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (auto it : nums)
    {
        if (it == first || it == second || it == third)
            continue;

        if (it > first)
        {
            third = second;
            second = first;
            first = it;
        }
        else if (it > second)
        {
            third = second;
            second = it;
        }
        else
            third = it;
    }

    cout<< (third != LLONG_MIN) ? third : first;
    return 0;
}