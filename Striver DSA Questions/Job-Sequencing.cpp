#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct job
{
    int id;
    int dead;
    int profit;
};

bool comparision(job a, job b)
{
    return a.profit > b.profit;
}

pair<int, int> jobScheduling(job arr[], int n)
{
    sort(arr, arr + n, comparision);

    //  for(int i=0;i<n;i++)
    //  {
    //     cout<<arr[i].profit<<" ";
    //  }
    //   cout<<endl;

    int maxi = arr[0].dead;
    for (int i = 1; i < n; i++)
        maxi = max(maxi, arr[i].dead);

    vector<int> slot(maxi + 1, -1);
    //  for(auto it:slot)
    //   cout<<it<<" ";
      cout<<endl;
    int countjobs = 0, jobprofit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                countjobs++;
                jobprofit += arr[i].profit;
                break;
            }
        }
    }
     return make_pair(countjobs,jobprofit);
}

int main()
{
    int n;
    cin >> n;
    job arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;

    pair<int, int> ans = jobScheduling(arr, n);
     cout<<ans.first<<" "<<ans.second<<endl;

}