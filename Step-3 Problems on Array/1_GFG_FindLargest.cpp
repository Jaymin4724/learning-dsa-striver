#include <bits/stdc++.h>
using namespace std;

// bruteforce approach : sort an array , access the last element (O(nlogn))
// optimal approach : (O(n))
int largest(vector<int> &arr)
{
    int largest = arr[0];
    for (auto i : arr)
    {
        if (i > largest)
        {
            largest = i;
        }
    }
    return largest;
}

int main()
{
    vector<int> arr = {21, 42, 33, 94, 25, 16, 80};
    int ans = largest(arr);
    cout << ans;
};