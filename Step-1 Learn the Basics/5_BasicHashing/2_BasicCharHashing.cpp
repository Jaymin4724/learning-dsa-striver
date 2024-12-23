// NUMBER HASHING
// Problem Statement : Check the number of frequencies of given character array(SMALL letters only)
// Input :
// "abcdabefc"
// Queries : 6
// a b c x y z
// if you want to take SMALL and CAPITAL both letters then hash array would be of length 256 and directly it will store the character value, no need to do this : hash[str[i] - 'a']++;
// directly hash[str[i]]++;

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    // (1) precalculation & prestoring
    int hash[26] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        hash[str[i] - 'a']++;
    }

    cout << "\nQueries : ";
    // queries to check frequencies of a number
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // (2) fetching
        cout << "Frequency of " << c << " : " << hash[c - 'a'] << endl;
    }
    return 0;
}