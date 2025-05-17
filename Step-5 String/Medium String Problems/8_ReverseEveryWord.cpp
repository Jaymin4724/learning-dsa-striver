#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Function to reverse the words in a string
// Time Complexity: O(n), where n is the length of the string
// Space Complexity: O(n), where n is the length of the string
// This function reverses the words in a given string
// It uses a stringstream to split the string into words
// and then reverses the order of the words
// Finally, it concatenates the words back into a single string

string reverseWords(string s)
{
    stringstream ss(s);
    string word;
    vector<string> words;
    while (ss >> word)
    {
        words.push_back(word);
    }
    string result;
    for (int i = words.size() - 1; i >= 0; --i)
    {
        result += words[i];
        if (i != 0)
            result += ' ';
    }
    return result;
}

int main()
{
    vector<string> testCases = {
        "the sky is blue",
        "  hello world  ",
        "a good   example",
        "  Bob    Loves  Alice   ",
        "Alice does not even like bob ",
        "  ",
        "a",
        "a b",
        "a b c d e f g h i j k l m n o p q r s t u v w x y z",
    };
    for (string testCase : testCases)
    {
        cout << "Input: " << testCase << endl;
        cout << "Output: " << reverseWords(testCase) << endl;
    }
    return 0;
}
