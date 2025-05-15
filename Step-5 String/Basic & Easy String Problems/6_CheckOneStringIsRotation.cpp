// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true

// Example 2:
// Input: s = "abcde", goal = "abced"
// Output: false

// Constraints:
// 1 <= s.length, goal.length <= 100
// s and goal consist of lowercase English letters.

// Approach:
// 1. If the length of the two strings is not equal, then return false.
// 2. Concatenate the first string with itself and check if the second string is a substring of the concatenated string.
// 3. If the second string is a substring of the concatenated string, then return true. Otherwise, return false.

// TC: O(N)
// SC: O(N)
#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal)
{
    if (s.size() != goal.size())
        return false;
    string con = s + s;

    int n = s.size();
    for (int i = 0; i < con.size(); i++)
    {
        if (con.substr(i, n) == goal)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s = "abcde", goal = "cdeab";
    cout << rotateString(s, goal) << endl;
    return 0;
}
