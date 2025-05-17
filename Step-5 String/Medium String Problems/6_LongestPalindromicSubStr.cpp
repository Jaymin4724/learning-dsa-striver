#include <bits/stdc++.h>
using namespace std;

// Brute-force approach to find the longest palindromic substring in a given string.
// Time Complexity: O(N^3) - There are O(N^2) substrings and checking each substring for palindrome takes O(N).
// Space Complexity: O(1) - Only a few variables are used for tracking indices and result.
//
// Other Solution:
// A better approach is to use Dynamic Programming (DP) with O(N^2) time and O(N^2) space.
// The most optimal solution is the "Expand Around Center" approach with O(N^2) time and O(1) space.
// For even better performance in some cases, Manacher's Algorithm can be used with O(N) time and O(N) space.

string LongestPalindromicSubStrBrute(string s)
{
    int n = s.size();
    int i, j;
    string maxsubstr = "";
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            int left = i, right = j;
            bool isPalindrome = true;

            while (left < right)
            {
                if (s[left] != s[right])
                {
                    isPalindrome = false;
                    break;
                }
                left++;
                right--;
            }
            if (isPalindrome && (j - i + 1) > maxsubstr.size())
            {
                maxsubstr = s.substr(i, j - i + 1);
            }
        }
    }
    return maxsubstr;
}

int main()
{
    cout << LongestPalindromicSubStrBrute("babad") << endl;
    return 0;
}
