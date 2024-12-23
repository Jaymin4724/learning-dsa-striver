//  https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1
// Sum of First n Cubes
// Given an integer n, calculate the sum of series 1^3 + 2^3 + 3^3 + 4^3 + … till n-th term.
// Input: n = 5
// Output: 225
// Explanation: 13 + 23 + 33 + 43 + 53 = 225

#include <bits/stdc++.h>
using namespace std;
int sumOfSeries(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return pow(n, 3) + sumOfSeries(n - 1);
}
int main()
{
    int n = 5;
    int sum = sumOfSeries(n);
    cout << sum;
    return 0;
}