#include <bits/stdc++.h>
using namespace std;

// Approach : (TC : O(n^3) , SC : O(1)) Bruteforce Approach
// - Loop through all subarrays with thre0e nested loops 
// - Calculate sum of each subarray 
// - Check if sum equals K and update maxLen
int longestSubarrayWithSumK(vector<int> arr, int size, int k)
{
    int maxlen = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            int s = 0;
            for (int k = i; k <= j; k++)
            {
                s += arr[k];
            }
            if (s == k)
                maxlen = max(maxlen, j - i + 1);
        }
    }
    return maxlen;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 5;
    int size = arr.size();
    int maxlen = longestSubarrayWithSumK(arr, k, size);
    cout << maxlen;
}