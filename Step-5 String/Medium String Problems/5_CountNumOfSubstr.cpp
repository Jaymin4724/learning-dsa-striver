#include <iostream>
#include <string>
#include <set>
using namespace std;

int countUniqueSubstrings(const string &s)
{
    int n = s.length();
    set<string> substrings;
    for (int i = 0; i < n; ++i)
    {
        string sub = "";
        for (int j = i; j < n; ++j)
        {
            sub += s[j];
            substrings.insert(sub);
        }
    }
    return substrings.size();
}

// Function to count total number of substrings (including duplicates)
int countTotalSubstrings(const string &s)
{
    int n = s.length();
    // Number of substrings = n * (n + 1) / 2
    return n * (n + 1) / 2;
}

int countTotalSubstringsBrute(const string &s)
{
    int n = s.size();
    int i, j;
    int count = 1;
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            cout << count << " : ";
            for (int k = i; k <= j; k++)
            {
                cout << s[k];
            }
            count++;
            cout << endl;
        }
    }
    return count - 1;
}
int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Unique substrings count: " << countUniqueSubstrings(s) << endl;
    cout << "Total substrings count: " << countTotalSubstrings(s) << endl;

    return 0;
}
