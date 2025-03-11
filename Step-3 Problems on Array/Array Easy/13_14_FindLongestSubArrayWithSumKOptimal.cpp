// Given an array that contains positive, negative, and zero elements, we need to find the longest subarray whose sum is exactly K.

// prefixSum[i] = a[0] +a[1] +... + a[i]
// Using the prefix sum, we can compute the sum of any subarray efficiently:
// sum from index l to r= prefixSum[r] - prefixSum[l-1]

// Dry Run Example
// Let's dry run the array arr = {10, -5, 2, -3, 7, 5, -3, 1, 3} with K = 7.
// Index  |	Element  |	Prefix Sum	  |     Action
// 0	    10	10	    Store               10 → 0
// 1	    -5	5	    Store               5 → 1
//! 2	    2	7	    Prefix Sum = K, maxLen = 3
// 3	    -3	4	    Store               4 → 3
//! 4	    7	11	    Found prefixSum - K = 4 in map, maxLen = 4 - 3 = 3
// 5	    5	16	    Store               16 → 5
// 6	    -3	13      Store               13 → 6
// 7	    1	14	    Store               14 → 7
//! 8	    3	17	    Found prefixSum - K = 10 in map, maxLen = 8 - 0 = 8
//! so the answer is 8 !!

// The approach to finding the longest subarray with sum K leverages the prefix sum technique with a hash map for efficient lookup.
// As we traverse the array, we maintain a running sum (prefixSum). If at any index i, prefixSum itself equals K, it means the subarray from the start to i has the required sum, so we update maxLen.
// Otherwise, we check if (prefixSum - K) exists in the hash map, which indicates that a subarray ending at i sums to K.
// If found using the find function, we update maxLen as i - prefixMap[prefixSum - K], representing the length of the subarray with sum K.
// If prefixSum is not already present in the map, we store its first occurrence to maximize the length of future valid subarrays.
#include <bits/stdc++.h>
using namespace std;

// TC & SC : O(n)
int longestSubarrayWithSumK(vector<int> &arr, int k)
{
    unordered_map<int, int> prefixMap; // Stores prefixSum -> first occurrence index
    int prefixSum = 0, maxLen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];

        // Case 1: If sum from 0 to i is already k
        if (prefixSum == k)
        {
            maxLen = i + 1;
        }

        // Case 2: If prefixSum - k exists in the map, update maxLen
        if (prefixMap.find(prefixSum - k) != prefixMap.end())
        {
            maxLen = max(maxLen, i - prefixMap[prefixSum - k]);
        }

        // Case 3: Store the first occurrence of prefixSum
        if (prefixMap.find(prefixSum) == prefixMap.end())
        {
            prefixMap[prefixSum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {10, -5, 2, -3, 7, 5, -3, 1, 3};
    int k = 7;
    cout << "Longest Subarray Length: " << longestSubarrayWithSumK(arr, k) << endl;
    return 0;
}
