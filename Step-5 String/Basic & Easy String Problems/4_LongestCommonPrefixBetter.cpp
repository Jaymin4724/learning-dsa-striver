#include <bits/stdc++.h>
using namespace std;

// this is the better and the best approach
// we will sort the array and then compare the first and the last element
// the common prefix of the first and the last element will be the longest common prefix
// we will return the longest common prefix
// TC: O(nlogn)
// SC: O(1)

string longestCommonPrefix(vector<string> &strs)
{
    // If the array is empty, return an empty string
    if (strs.size() == 0)
        return "";
    // If the array has only one element, return that element
    if (strs.size() == 1)
        return strs[0];
    // Sort the array
    sort(strs.begin(), strs.end());
    // The longest common prefix will be the common prefix of the first and last element
    string longest = "";
    for (int i = 0; i < strs[0].size(); i++)
    {
        if (strs[0][i] == strs[strs.size() - 1][i])
            longest += strs[0][i];
        else
            break;
    }
    return longest;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs);
    return 0;
}
