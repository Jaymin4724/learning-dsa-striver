// Given an integer array nums, return a list of all the leaders in the array.

// A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.

// Examples:
// Input: nums = [1, 2, 5, 3, 1, 2]
// Output: [5, 3, 2]

// Input: nums = [-3, 4, 5, 1, -4, -5]
// Output: [5, 1, -4, -5]

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n)
vector<int> LeadersBrute(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int flag = 0;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] < nums[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            ans.push_back(nums[i]);
        }
    }
    ans.push_back(nums[nums.size() - 1]);
    return ans;
}

// Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> LeadersOptimal(vector<int> &nums)
{
    vector<int> ans;
    int curr_max = INT_MIN;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] > curr_max)
        {
            ans.push_back(nums[i]);
            curr_max = nums[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> nums = {-3, 4, 5, 1, -4, -5};
    vector<int> leaders = LeadersBrute(nums);
    cout << "Leaders in the array (BruteForce): ";
    for (int leader : leaders)
    {
        cout << leader << " ";
    }
    cout << endl;

    vector<int> nums2 = {-3, 4, 5, 1, -4, -5};
    vector<int> leaders2 = LeadersOptimal(nums2);
    cout << "Leaders in the array (Optimal): ";
    for (int leader : leaders2)
    {
        cout << leader << " ";
    }
    cout << endl;
    return 0;
}