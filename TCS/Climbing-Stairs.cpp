#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//  Using only Steps of 1 and Steps 2

int climbStairs(int n)
{
    if (n <= 2)
        return n;

    vector<int> dp(n + 1, -1);

    dp[0] = 0, dp[1] = 1, dp[2] = 2;

    if (dp[n] != -1)
        return dp[n];

    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    int ans = climbStairs(n);
    cout << ans << endl;
    return 0;
}