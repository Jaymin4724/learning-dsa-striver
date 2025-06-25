#include <bits/stdc++.h>
using namespace std;

// TC : O(2^n)
// SC : O(N)
vector<vector<int>> res;
void helper(vector<int> &nums, vector<int> &path, int idx)
{
    res.push_back(path);
    for (int i = idx; i < nums.size(); ++i)
    {
        path.push_back(nums[i]);
        helper(nums, path, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> path;
    helper(nums, path, 0);
    return res;
}