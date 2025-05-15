// Sort Characters By Frequency
// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

// Example 1:
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

// Example 2:
// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.

// Example 3:
// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

// s consists of uppercase and lowercase English letters and digits.

#include <bits/stdc++.h>
using namespace std;

//? TC: O(nlogn) for sorting + O(n) for creating the frequency map
//? SC: O(n) for storing the frequency map
//? The overall time complexity is O(nlogn) and space complexity is O(n).

// Function to sort characters by frequency
string frequencySort(string s)
{
    // Create a frequency map
    unordered_map<char, int> freqMap;
    for (char c : s)
    {
        freqMap[c]++;
    }

    // Testing :
    // for (auto i : freq) {
    //     cout << i.first << "-->" << i.second << "\n";
    // }

    // No, we cannot directly sort the map because unordered_map does not maintain any order.
    // Sorting requires a container that supports ordering, like a vector or a map with ordering (e.g., map or multimap).
    vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());
    sort(freqVec.begin(), freqVec.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return a.second > b.second; });

    string result;
    for (auto p : freqVec)
    {
        // Append the character p.first, p.second times to the result string
        // The string constructor creates a string with p.second copies of p.first
        result += string(p.second, p.first);
    }

    return result;
}

int main()
{
    string s = "tree";
    cout << frequencySort(s) << endl; // Output: "eert"
    s = "cccaaa";
    cout << frequencySort(s) << endl; // Output: "aaaccc"
    s = "Aabb";
    cout << frequencySort(s) << endl; // Output: "bbAa"
    return 0;
}