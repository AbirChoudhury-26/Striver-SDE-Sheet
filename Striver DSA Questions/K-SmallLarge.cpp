#include <bits/stdc++.h>
using namespace std;

void kth_Largest_And_Smallest_By_AscendingOrder(vector<int> &arr, int k)
{

    sort(arr.begin(), arr.end());
    int n = arr.size();

    cout << "kth Largest element " << arr[n - k] << ", "
         << "kth Smallest element " << arr[k - 1];
}
int main()
{

    vector<int> arr = {5, 322, 64, 432, 10, 3};
    kth_Largest_And_Smallest_By_AscendingOrder(arr, 3);

    return 0;
}