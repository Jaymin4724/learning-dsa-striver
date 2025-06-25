#include <bits/stdc++.h>
using namespace std;

// TC : O(2^N)
// SC : O(N)
void generateBinaryStrings(int n, string current = "")
{
    // Base case: if the current string length is equal to n
    if (current.length() == n)
    {
        cout << current << endl;
        return;
    }

    // Recursive case: add '0' and '1' to the current string
    generateBinaryStrings(n, current + "0");
    generateBinaryStrings(n, current + "1");
}

