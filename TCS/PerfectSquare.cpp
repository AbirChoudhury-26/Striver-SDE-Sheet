#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void isPerfect(int n)
{
    if (n == 1)
        cout << "True" << endl;
    double val;
    for (int i = 1; i < n; i++)
    {
        val = n * (1.0) / i;
        if (val == i)
        {
            cout << "True" << endl;
            break;
        }
        else if (i > val)
        {
            cout<<"False"<<endl;
            break;
        }
    }

}

int main()
{
    int n;
    cin >> n;
    isPerfect(n);
    return 0;
}