#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of rows and columns (N) = ";
    cin >> n;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
    cout << "entered matrix = " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++)
    {
        d1 += mat[i][i];
        d2 += mat[i][n - i - 1];
    }
    cout<<abs(d1-d2)<<endl;
}