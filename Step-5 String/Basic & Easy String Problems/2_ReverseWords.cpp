// Reverse Words in a String OR Palindrome Check

#include <bits/stdc++.h>
using namespace std;

// TC : O(n)
// SC : O(n)
string reverseWords(string s)
{
    vector<string> arr;
    string word, rev;
    stringstream ss(s); // Create a stringstream object with the input string

    // Use stringstream to extract words from the input string
    while (ss >> word)
    {
        arr.push_back(word); // Add each word to the vector
    }

    // Iterate over the vector in reverse order to form the reversed string
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        rev += arr[i] + (i > 0 ? " " : ""); // Add words to the result string with spaces in between
        // here we are adding space only if it is not the last word
    }

    return rev;
}

int main()
{
    string s;
    cin >> s;
    cout << reverseWords(s) << endl;
    return 0;
}

//* SOLUTION WITHOUT STRING STREAM
// string reverseWords(string s) {
//     vector<string> words;
//     int n = s.size(), i = 0;

//     while (i < n) {
//         while (i < n && s[i] == ' ') i++; // Skip leading spaces
//         if (i >= n) break;
//         int j = i;
//         while (j < n && s[j] != ' ') j++; // Find end of word
//!         words.push_back(s.substr(i, j - i));
//         i = j;
//     }

//     string rev;
//     for (int k = words.size() - 1; k >= 0; k--) {
//         rev += words[k];
//         if (k > 0) rev += " ";
//     }

//     return rev;
// }