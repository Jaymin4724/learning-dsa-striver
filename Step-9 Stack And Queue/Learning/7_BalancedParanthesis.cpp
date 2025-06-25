#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
// SC : O(N)
bool isValid(string str)
{
    unordered_map<char, char> mpp = {{')', '('}, {'}', '{'}, {']', '['}};
    stack<char> s;

    for (char i : str)
    {
        if (i == '(' || i == '{' || i == '[')
        {
            s.push(i);
        }
        else
        {
            if (s.empty() || s.top() != mpp[i])
            {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}