// Given an integer array nums, find the subarray with the largest sum, and return its sum.
// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Example 2:
// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Example 3:
// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n^3)
// Space Complexity: O(1)
int maxSubArrayBruteForce(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// Better Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int maxSubArrayBetter(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

//? Optimal Approach - Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
int maxSubArrayOptimal(vector<int> &nums)
{
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxSum = max(maxSum, sum);
        // Main Logic --> If the sum becomes negative, we reset it to 0
        // because a negative sum will not contribute to the maximum sum of any subarray
        // So we start a new subarray from the next element
        // If the sum is negative, we reset it to 0
        // This is the key idea of Kadane's algorithm
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    vector<vector<int>> testcases = {
        {-2, 1, -3, 4, -1, 2, 1, -5, 4},
        {1},
        {5, 4, -1, 7, 8},
        {-2, -3, -1},
        {0, 0, 0},
        {-1, -2, -3},
    };
    for (auto &nums : testcases)
    {
        cout << "Input: ";
        for (int num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
        cout << "Brute Force Output: " << maxSubArrayBruteForce(nums) << endl;
        cout << "Better Output: " << maxSubArrayBetter(nums) << endl;
        cout << "Optimal Output: " << maxSubArrayOptimal(nums) << endl;
        cout << endl;
    }
    return 0;
}