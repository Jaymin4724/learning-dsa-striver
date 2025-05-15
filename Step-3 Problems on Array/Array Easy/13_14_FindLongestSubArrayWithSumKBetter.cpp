// Dry Run Example
// Let's dry run the array arr = {10, -5, 2, -3, 7, 5, -3, 1, 3} with K = 7.
// Index  |	Element  |	Prefix Sum	  |     Action
// 0	    10	            10	            Store               10 → 0
// 1	    -5	            5	            Store               5 → 1
//! 2	    2	            7	            Prefix Sum = K, maxLen = 3
// 3	    -3	            4	            Store               4 → 3
//! 4	    7	            11	            Found prefixSum - K = 4 in map, maxLen = 4 - 3 = 3
// 5	    5	            16      	    Store               16 → 5
// 6	    -3	            13              Store               13 → 6
// 7	    1	            14      	    Store               14 → 7
//! 8	    3	            17	            Found prefixSum - K = 10 in map, maxLen = 8 - 0 = 8
//! so the answer is 8 !!

#include <bits/stdc++.h>
using namespace std;

// Approach : (TC : O() , SC : O()) Better Approach
// Use Hashing

// We keep adding elements to get the current sum (prefixSum).
// If at any index, prefixSum is equal to K, it means the subarray from the start to this index has sum K.
// In that case, we update maxLen to the current length (i + 1).

// If not, we check if (prefixSum - K) is already in the map.
// If it is, it means there is a subarray ending here that adds up to K.
// We update maxLen by taking the distance between current index and the index where (prefixSum - K) was first seen.

// We only store the first time we see each prefixSum in the map.
// This helps us find the longest subarray possible in future steps.
#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> arr, int size, int k)
{
    unordered_map<int, int> prefix_map;
    int sum = 0;
    int maxlen = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];

        if (sum == k)
            maxlen = i + 1;

        if (prefix_map.find(sum - k) != prefix_map.end())
        {
            maxlen = max(maxlen, i - prefix_map[sum - k]);
        }

        // Only store the first occurrence
        if (prefix_map.find(sum) == prefix_map.end())
        {
            prefix_map[sum] = i;
        }
    }

    return maxlen;
}

int main()
{
    vector<int> arr = {10, -5, 2, -3, 7, 5, -3, 1, 3};
    int k = 7;
    int size = arr.size();

    int maxlen = longestSubarrayWithSumK(arr, size, k);
    cout << "Longest subarray length: " << maxlen << endl;

    return 0;
}
