//? https://takeuforward.org/data-structure/find-minimum-number-of-coins/
//* Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.

// Input: V = 70
// Output: 2
// Explaination: We need a 50 Rs note and a 20 Rs note.

// Input: V = 121
// Output: 3
// Explaination: We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.

#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int value)
{
    // Find the largest coin less than or equal to value
    int j = coins.size() - 1; // Start with the largest coin
    int count = 0;

    while (value > 0 && j >= 0)
    {
        if (value >= coins[j]) // Use the current coin if it fits
        {
            value -= coins[j];
            count++;
        }
        else
        {
            j--; // Move to the next smaller coin
        }
    }
    return count;
}

int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int ans1 = coinChange(coins, 70);
    cout << ans1 << endl;

    int ans2 = coinChange(coins, 121);
    cout << ans2 << endl;
}
