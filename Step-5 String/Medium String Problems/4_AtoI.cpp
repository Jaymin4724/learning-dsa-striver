// String to Integer (atoi)
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:
// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain in the range. Specifically, integers less than -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.
// Return the integer as the final result.

#include <bits/stdc++.h>
using namespace std;

// list of the functions needed in the program
// 1. myAtoi(string s): This function converts a string to a 32-bit signed integer.
// 2. main(): This function is the entry point of the program and tests the myAtoi function with various test cases.
// 3. isdigit(char c): This function checks if a character is a digit (0-9).
// 4. stoi(string s): This function converts a string to an integer.

int myAtoi(string s)
{
    int i = 0, n = s.size(), sign = 1;
    long ans = 0;

    // Whitespace
    while (i < n && s[i] == ' ')
        i++;

    // Signedness
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }

    // Conversion
    while (i < n && isdigit(s[i]))
    {
        ans = ans * 10 + (s[i] - '0');
        // Rounding
        if (sign == 1 && ans > INT_MAX)
            return INT_MAX;
        if (sign == -1 && -ans < INT_MIN)
            return INT_MIN;
        i++;
    }

    return (int)(ans * sign);
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