// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:
// Input: nums = [3,2,3]
// Output: 3

// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

#include <iostream>
#include <vector>
using namespace std;

// TC : O(n^2)
// SC : O(1)
// This is a brute force approach where we count the occurrences of each element
// in the array and check if it is greater than n/2. If it is, we return that element.
int majorityElementBruteForce(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        int count = 0;
        for (int j = 0; j < n; ++j)
        {
            if (nums[j] == nums[i])
            {
                count++;
            }
        }
        if (count > n / 2)
        {
            return nums[i];
        }
    }
    return -1; // This line should never be reached as per problem statement
}

int majorityElementBetter(vector<int> &nums)
{
    unordered_map<int, int> num_count;
    int half_n = nums.size() / 2;
    for (int i = 0; i < nums.size(); ++i)
    {
        num_count[nums[i]]++;
    }
    for (auto pair : num_count)
    {
        if (pair.second > half_n)
        {
            return pair.first;
        }
    }
    return -1; // This line should never be reached as per problem statement
}

//? Optimal: Moore's Voting Algorithm
// TC : O(n)
// SC : O(1)
int majorityElementOptimal(vector<int> &nums)
{
    int count = 0, candidate;
    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

int main()
{
    vector<int> nums = {3, 2, 3};
    cout << majorityElementBrute(nums) << endl;   // Output: 3
    cout << majorityElementBetter(nums) << endl;  // Output: 3
    cout << majorityElementOptimal(nums) << endl; // Output: 3

    // Test with another example
    nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElementBrute(nums) << endl;   // Output: 2
    cout << majorityElementBetter(nums) << endl;  // Output: 2
    cout << majorityElementOptimal(nums) << endl; // Output: 2

    return 0;
}