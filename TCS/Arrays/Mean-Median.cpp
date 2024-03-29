#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
double findMean(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
 
    return (double)sum / (double)n;
}
 
// Function for calculating median
double findMedian(int a[], int n)
{
    // First we sort the array
    sort(a,a+n);
 
    // check for even case
    if (n % 2 != 0)
        return (double)a[n / 2];
 
    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}
 

// Driver code
int main()
{
    int a[] = { 1, 3, 4, 2, 7, 5, 8, 6 };
    int N = sizeof(a) / sizeof(a[0]);
 
    // Function call
    printf("Mean = %f\n", findMean(a, N));
    printf("Median = %f\n", findMedian(a, N));
    return 0;

}

