#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int left, int right)
{
    if (left >= right)
    {
        return true;
    }
    if (str[left] != str[right])
    {
        return false; // If characters at left and right don't match, it's not a palindrome
    }
    return isPalindrome(str, left + 1, right - 1); // Recursive call
}

int main()
{
    string str = "MADAM";
    if (isPalindrome(str, 0, str.length() - 1))
    {
        cout << str << " is palindrome";
    }
    else
    {
        cout << str << " is not palindrome";
    }
}
