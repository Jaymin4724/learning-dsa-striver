#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute-force function
// Time Complexity: O(N^3)
//   - Outer two loops: O(N^2) for all substrings
//   - Inner loop: O(N) to count frequencies for each substring
// Space Complexity: O(1) (ignoring input and output, uses fixed-size freq array)
int beautySumBruteForce(string s)
{
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            vector<int> freq(26, 0);
            for (int k = i; k <= j; k++)
            {
                freq[s[k] - 'a']++;
            }
            int mx = 0, mn = INT_MAX;
            for (int k = 0; k < 26; k++)
            {
                if (freq[k] > 0)
                {
                    mx = max(mx, freq[k]);
                    mn = min(mn, freq[k]);
                }
            }
            sum += (mx - mn);
        }
    }
    return sum;
}

// Optimized function
// Time Complexity: O(N^2 * 26) ≈ O(N^2)
//   - Outer loop: O(N) for starting index
//   - Inner loop: O(N) for ending index
//   - Frequency calculation: O(26) for each substring
// Space Complexity: O(1) (uses fixed-size freq array)
int beautySumBetter(string s)
{
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> freq(26, 0);
        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;
            int mx = 0, mn = INT_MAX;
            for (int k = 0; k < 26; k++)
            {
                if (freq[k] > 0)
                {
                    mx = max(mx, freq[k]);
                    mn = min(mn, freq[k]);
                }
            }
            sum += (mx - mn);
        }
    }
    return sum;
}

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Beauty Sum (Brute Force): " << beautySumBruteForce(s) << endl;
    cout << "Beauty Sum (Optimized): " << beautySumBetter(s) << endl;

    return 0;
}
