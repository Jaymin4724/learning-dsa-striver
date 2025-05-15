// Maximum Nesting Depth of the Parentheses
// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

// Example 1:
// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3
// Explanation:
// Digit 8 is inside of 3 nested parentheses in the string.

// Example 2:
// Input: s = "(1)+((2))+(((3)))"
// Output: 3
// Explanation:
// Digit 3 is inside of 3 nested parentheses in the string.

// Example 3:
// Input: s = "()(())((()()))"
// Output: 3

#include <bits/stdc++.h>
using namespace std;
//? TC: O(n)
//? SC: O(1)
// Function to find the maximum nesting depth of parentheses
int maxDepth(string s)
{
    int maxcount = 0, count = 0;
    for (auto i : s)
    {
        if (i == '(')
        {
            count++;
            if (count > maxcount)
            {
                maxcount = count;
            }
        }
        if (i == ')')
        {
            count--;
        }
    }
    return maxcount;
}
int main()
{
    string s = "(1+(2*3)+((8)/4))+1";

    cout << maxDepth(s);
    return 0;
}
