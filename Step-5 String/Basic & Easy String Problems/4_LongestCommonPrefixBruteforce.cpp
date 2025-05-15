// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

#include <iostream>
#include <vector>

using namespace std;

// TC: ALMOST O(n*m) where n is the number of strings and m is the length of the smallest string
// SC: O(1)

string longestCommonPrefix(vector<string> &strs)
{
    string longest = strs[0];
    int i, j;
    for (auto i : strs)
    {
        // if any string is empty, return empty string
        if (i == "")
            return "";
        for (int j = 0; j < i.size(); j++)
        {
            // If characters at the same index are not equal in both the current string (i) and the longest prefix string (longest),
            // erase the longest prefix string from that index to the end
            if (i[j] != longest[j])
            {
                longest.erase(j, longest.size());
                break;
            }
            // If you have reached the end of the current string (i), truncate the longest prefix string to match the length of the current string.
            if (j + 1 == i.size())
            {
                longest.erase(j + 1, longest.size());
            }
        }
    }
    return longest;
}

int main()
{
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs1) << endl;

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(strs2) << endl;

    return 0;
}
