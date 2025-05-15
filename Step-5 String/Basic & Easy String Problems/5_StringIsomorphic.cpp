// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character,but a character may map to itself.

// example
// Input: s = "egg", t = "add"
// Output: true
// Input: s = "foo", t = "bar"
// Output: false
// Input: s = "paper", t = "title"
// Output: true

#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;

    // we are taking 2 maps to store the mapping of characters from s to t and t to s
    unordered_map<char, char> s_map, t_map;

    for (int i = 0; i < s.length(); i++)
    {
        char s_char = s[i];
        char t_char = t[i];
        // if both map doesn't contain the character then add it to the map
        if (s_map.find(s_char) == s_map.end() && t_map.find(t_char) == t_map.end())
        {
            s_map[s_char] = t_char;
            t_map[t_char] = s_char;
        }
        // if both map contains the character then check if the character is mapped to the same character
        // if not then return false
        else if (s_map[s_char] != t_char || t_map[t_char] != s_char)
            return false;
    }

    return true;
}

int main()
{
    cout << isIsomorphic("egg", "add") << endl;     // Output: 1 (true)
    cout << isIsomorphic("foo", "bar") << endl;     // Output: 0 (false)
    cout << isIsomorphic("paper", "title") << endl; // Output: 1 (true)
}
