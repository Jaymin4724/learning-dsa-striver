// Problem:

// Given a CamelCase string s, count the number of words.
// The first word starts with lowercase letters.
// Each subsequent word starts with an uppercase letter.

// Input:  saveChangesInTheEditor
// Output: 5

#include <bits/stdc++.h>
using namespace std;

int CountWords(string s)
{
    if (s.empty())
        return 0;
    int count = 1;
    for (auto i : s)
    {
        int ascii = i;
        if (ascii >= 65 && ascii <= 90)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    string s = "saveChangesInTheEditor";
    cout << CountWords(s);
    return 0;
}