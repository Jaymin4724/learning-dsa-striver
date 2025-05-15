
#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
bool checkAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
        mp[t[i]]--;
    }
    for (auto it : mp)
    {
        if (it.second != 0)
            return false;
    }
    return true;
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << checkAnagram(s, t) << endl;
    return 0;
}