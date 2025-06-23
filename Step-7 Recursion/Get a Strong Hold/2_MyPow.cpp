// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
#include <bits/stdc++.h>
using namespace std;

// Recursive BruteForce Approach (TLE - Leetcode)
// TC : O(N)
// SC : O(N) --> Recursion depth
double helper(double x, double curr, long long n)
{
    if (n == 0)
        return curr;
    if (n > 0)
        return helper(x, curr * x, n - 1);
    return helper(x, curr / x, n + 1);
}

double myPow(double x, int n)
{
    // convert n to long long to safely handle INT_MIN
    return helper(x, 1.0, (long long)n);
}

//---------------------------------------------------------------------------------------------------------------------------------------------
// Iterative Optimal Approach (Learn this before learning recursion)
// TC : O(LOG N)
// SC : O(1)
double myPow(double x, int n)
{
    long long N = n; // avoid overflow on -2^31
    if (N < 0)
    {
        x = 1.0 / x;
        N = -N;
    }

    double result = 1.0;

    while (N > 0)
    {
        if (N % 2 == 1)
        {
            result *= x; // include current x if n is odd
        }
        x *= x; // square the base
        N /= 2; // halve the exponent
    }

    return result;
}

//* The technique "square the base and halve the exponent" is called:
//* Exponentiation by Squaring
//* Also known as: Binary Exponentiation
//* To compute a^8:
//* Step 1: a^2 = a * a
//* Step 2: a^4 = (a^2)^2
//* Step 3: a^8 = (a^4)^2
//* This reduces the number of multiplications significantly (from O(n) to O(log n)).

//---------------------------------------------------------------------------------------------------------------------------------------------
// Recursive Optimal Approach
// TC : O(LOG N)
// SC : O(LOG N) --> Recursion depth
double powHelper(double x, long long n)
{
    if (n == 0)
        return 1;
    // if power is even
    if (n % 2 == 0)
    {
        // square the base &  halve the exponent
        return powHelper(x * x, n / 2);
    }
    // if power is odd
    else
    {
        // that number * number raise to its power-1
        return x * powHelper(x, n - 1);
    }
}

double myPow(double x, int n)
{
    long long N = n; // use long long to avoid overflow
    if (N < 0)
    {
        // For NEGATIVE power
        x = 1 / x;
        N = -N;
    }
    return powHelper(x, N);
}
