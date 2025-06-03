#include <bits/stdc++.h>
using namespace std;

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

// BruteForce Approach
// TC : O(N^3)
// SC : O(1)
int subarraySumBruteForce(vector<int> &nums, int k)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int sum = 0;
            for (int l = i; l <= j; l++)
            {
                sum += nums[l];
            }
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
}

// Better Approach
// TC : O(N^2)
// SC : O(1)
int subarraySumBetter(vector<int> &nums, int k)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                count++;
            }
        }
    }
    return count;
}

// Optimal Approach : Using Prefix Sum
// TC : O(n)
// SC : O(n)

// preSum (prefix sum) = sum of elements from index 0 to i
// we want sum of subarray = k
// if CurrPreSum - OldPreSum = k
// [then]=> OldPreSum = CurrPreSum - k

// nums = [1, 2, 3], k = 3 (preSum means CurrPreSum)
// | i | nums[i]  | preSum | preSum - k | mpp[preSum - k]  | cnt | mpp               |
// | - | -------- | ------ | ---------- | ---------------- | --- | ----------------- |
// | 0 | 1        | 1      | -2         | 0                | 0   | {0:1, 1:1}        |
// | 1 | 2        | 3      | 0          | 1                | 1   | {0:1,1:1,3:1}     |
// | 2 | 3        | 6      | 3          | 1                | 2   | {0:1,1:1,3:1,6:1} |

int subarraySumOptimal(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    mpp[0] = 1;

    int CurrPreSum = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        CurrPreSum += nums[i];
        int OldPreSum = CurrPreSum - k;
        cnt += mpp[OldPreSum];
        mpp[CurrPreSum] += 1;
    }
    return cnt;
}