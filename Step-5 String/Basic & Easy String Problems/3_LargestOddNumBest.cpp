// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
// A substring is a contiguous sequence of characters within a string.

#include <bits/stdc++.h>
using namespace std;

// TC : O(n)
// SC : O(1)
string largestOddNumber(string s)
{
    // start from the end of the string
    // if the last digit is odd, return the whole string
    // else, keep removing the last digit until you find an odd digit
    // if no odd digit is found, return an empty string
    for (int i = s.length() - 1; i >= 0; i--)
    {
        // s[i]-'0' will convert the character to integer
        // if the integer is odd, return the substring from 0 to i
        if ((s[i] - '0') % 2 == 1)
        {
            // substr(starting index, length)
            // here till i+1 because we need to include the ith index character
            // so it will create substr from 0 to i , i+1 doesnt mean it will include i+1 index
            // for example s.substr(0, 1) will return the string from 0 to 1-1 = 0, it will only return one character at index 0
            return s.substr(0, i + 1);
        }
    }
    return "";
}
int main()
{
    cout << largestOddNumber("52") << endl;
    cout << largestOddNumber("4206") << endl;
    cout << largestOddNumber("35427") << endl;
    return 0;
}
