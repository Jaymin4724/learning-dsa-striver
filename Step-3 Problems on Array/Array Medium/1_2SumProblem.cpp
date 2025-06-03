// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]

//? Approach : Brute Force
// This approach involves using two nested loops to check all pairs of numbers in the array.
// For each pair, we check if their sum equals the target. If we find such a pair, we return their indices.
// TC : O(n^2) for brute force approach
// SC : O(1) for brute force approach
vector<int> twoSumBruteForce(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {

                return {i, j};
            }
        }
    }
    return {};
}

//? Approach : Better Approach
// This approach uses a hash map to store the numbers and their indices.
// For each number, we calculate its complement (target - number) and check if the complement exists in the map.
// If it does, we return the indices of the two numbers.
// This approach reduces the time complexity to O(n) and space complexity to O(n).
vector<int> twosumBetter(vector<int> &nums, int target)
{
    unordered_map<int, int> num_map; // To store the numbers and their indices
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];             // Calculate the complement
        if (num_map.find(complement) != num_map.end()) // Check if the complement exists in the map
        {
            return {num_map[complement], i}; // Return the indices of the two numbers
        }
        num_map[nums[i]] = i; // Store the number and its index in the map
    }
    return {};
}

int main()
{
    vector<vector<int>> testcases = {
        {2, 7, 11, 15},
        {3, 2, 4},
        {3, 3}};
    vector<int> targets = {9, 6, 6};

    for (int t = 0; t < testcases.size(); ++t)
    {
        vector<int> result_brute = twoSumBruteForce(testcases[t], targets[t]);
        vector<int> result_better = twosumBetter(testcases[t], targets[t]);
        cout << "Test case " << t + 1 << " (Bruteforce): ";
        for (int i : result_brute)
            cout << i << " ";
        cout << endl;
        cout << "Test case " << t + 1 << " (Better): ";
        for (int i : result_better)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}