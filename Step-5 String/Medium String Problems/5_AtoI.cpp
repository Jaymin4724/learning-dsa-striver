
//  String to Integer (atoi)
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:
// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -2^31 should be rounded to -2^31, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.

#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{
    int i = 0, sign = 1;
    long long result = 0;

    // Ignore leading whitespace
    while (i < s.size() && s[i] == ' ')
    {
        i++;
    }

    // Check for sign
    if (i < s.size() && (s[i] == '-' || s[i] == '+'))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Convert string to integer
    while (i < s.size() && isdigit(s[i]))
    {
        result = result * 10 + (s[i] - '0');
        if (result > INT_MAX)
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        i++;
    }

    return sign * result;
}
int main()
{
    string s = "   -42";
    int result = myAtoi(s);
    cout << result << endl; // Output: -42

    s = "4193 with words";
    result = myAtoi(s);
    cout << result << endl; // Output: 4193

    s = "words and 987";
    result = myAtoi(s);
    cout << result << endl; // Output: 0

    s = "-91283472332";
    result = myAtoi(s);
    cout << result << endl; // Output: -2147483648

    return 0;
}