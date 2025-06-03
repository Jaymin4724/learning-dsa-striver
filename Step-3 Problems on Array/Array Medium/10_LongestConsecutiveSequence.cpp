// Given an array nums of n integers, return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

// Examples:
// Input: nums = [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

// Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
// Output: 9
// Explanation: The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9.
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &a, int num)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == num)
            return true;
    }
    return false;
}

// TC : O(N^2)
// SC : O(1)
int LongestConsSeqBruteForce(vector<int> nums)
{
    int n = nums.size();
    int maxlen = 1;
    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        int len = 1;
        // search for consecutive numbers
        // using linear search:
        while (linearSearch(nums, x + 1) == true)
        {
            x += 1;
            len += 1;
        }

        maxlen = max(maxlen, len);
    }
    return maxlen;

    // My BruteForce
    // int maxlen = 1;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     int len = 1;
    //     for (int j = 0; j < nums.size(); j++)
    //     {
    //         if (nums[i] + len == nums[j])
    //         {
    //             len++;
    //             j = 0;
    //         }
    //     }
    //     maxlen = max(len, maxlen);
    // }
    // return maxlen;
}

// TC : O(N LOGN)
// SC : O(N)
int LongestConsSeqBetter(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int longest = 1;
    int count = 0;
    // for handling the duplicates
    int lastSmaller = INT_MIN;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        // check whether the previous element is the last smaller ?
        if (nums[i - 1] == lastSmaller)
        {
            count++;
            lastSmaller = nums[i];
        }
        // if the previous element is not the last smaller then check whether current element is not last smaller ?
        // current element will be = lastsmaller (if it is duplicate element) so no need to do anything
        else if (nums[i] != lastSmaller)
        {
            count = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, count);
    }
    return longest;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "BruteForce : " << LongestConsSeqBruteForce(nums) << endl;
    cout << "Better : " << LongestConsSeqBetter(nums) << endl;
    return 0;
}