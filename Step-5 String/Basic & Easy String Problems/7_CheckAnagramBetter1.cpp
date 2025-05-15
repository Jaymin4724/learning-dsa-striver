// An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.
// Valid Anagram
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn)
// SC: O(1)
bool checkAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << checkAnagram(s, t) << endl;
    return 0;
}