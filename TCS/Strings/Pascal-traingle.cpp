#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTriangle(int numRows)
{
    vector<vector<int>> result;
    vector<int> prevRow;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> currentRow(i + 1, 1);

        for (int j = 1; j < i; j++)
        {
            currentRow[j] = prevRow[j - 1] + prevRow[j];
        }

        result.push_back(currentRow);
        prevRow = currentRow;
    }

    return result;
}

int main()
{
    int rows;
    cin >> rows;
    vector<vector<int>> result=pascalTriangle(rows);
     
     for(int i=0;i<result.size();i++)
     {
         for(int j=0;j<result[i].size();j++)
          cout<<result[i][j]<<" ";
        cout<<endl;
     }
    return 0;
}