#include <bits/stdc++.h>
using namespace std;

// Approach : (TC : O(n^2) , SC : O(1)) Better Brute Force Approach (Using Running Sum)
// - Loop with two nested loops
// - Maintain a running sum instead of recomputing it
// - If sum equals K, update maxLen
int longestSubarrayWithSumK(vector<int> arr, int size, int sum)
{
    int maxlen = 0;

    for (int i = 0; i < size; i++)
    {
        int s = 0;
        for (int j = i; j < size; j++)
        {
            s += arr[j];
            if (s == sum)
                maxlen = max(maxlen, j - i + 1);
        }
    }
    return maxlen;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int sum = 5;
    int size = arr.size();
    int max = longestSubarrayWithSumK(arr, sum, size);
    cout << max;
}