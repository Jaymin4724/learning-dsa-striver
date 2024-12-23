// NUMBER HASHING
// Problem Statement : Check the number of frequencies of given array
// Input :
// 5
// 1 2 1 3 2
// Queries : 5
// 1 2 3 4 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // (1) precalculation & prestoring
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    cout << "\nQueries : ";

    // queries to check frequencies of a number
    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        // (2) fetching
        cout << "Frequency of " << number << " : " << mpp[number] << endl;
    }
    return 0;
}