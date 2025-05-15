// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
// A substring is a contiguous sequence of characters within a string.
// Example 1:   Input: num = "52"   Output: "5"
// Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.

// Example 2:   Input: num = "4206"   Output: ""
// Explanation: There are no odd numbers in "4206".

// Example 3:   Input: num = "35427"   Output: "35427"
// Explanation: "35427" is already an odd number.

#include <bits/stdc++.h>
using namespace std;

// TC : O(n^2)
// SC : O(n^2) why ? because we are storing all the substrings in the vector
// The number of substrings can be n*(n+1)/2 which is almost n^2
string largestOddNumber(string s)
{
    // vector to store the substrings
    vector<string> substrings;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        string sub = "";
        for (int j = i; j < n; j++)
        {
            sub += s[j];
            substrings.push_back(sub);
            // all the substrings !!!
        }
    }

    string largest_odd = "";
    long long max_odd_value = -1;

    for (string i : substrings)
    {
        // i.back() - '0' will give the last digit of the string
        // for example, if i = "123", then i.back() = '3' and i.back() - '0' = 3
        // we dont need to convert the whole string to integer and check if it is odd
        // we can directly check the last digit of the string to prove it is odd
        if ((i.back() - '0') % 2 == 1)
        {
            // stoll() is used to convert string to long long
            long long num = stoll(i);
            // here we are checking if the current odd number is greater than the previous odd number
            if (num > max_odd_value)
            {
                // if the current odd number is greater than the previous odd number
                // then we update the max_odd_value and largest_odd
                max_odd_value = num;
                largest_odd = i;
            }
        }
    }

    return largest_odd;
}

int main()
{
    cout << largestOddNumber("52") << endl;
    cout << largestOddNumber("4206") << endl;
    cout << largestOddNumber("35427") << endl;
    return 0;
}
