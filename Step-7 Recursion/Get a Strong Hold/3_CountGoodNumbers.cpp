#define MOD 1000000007
class Solution
{
public:
    // HERE WE HAVE USED CUSTOM POWER FUNCTION BECAUSE POW FUNCTION IN C++ RETURNS DOUBLE
    // AND WE NEED TO AVOID PRECISION LOSS FOR LARGE NUMBERS.
    // THIS IS THE SAME AS MYPOW FUNCTION IN PREVIOUS QUESTION.
    long long power(long long base, long long exp)
    {
        long long res = 1;
        base %= MOD;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    //? ITERATIVE OPTIMAL SOLUTION :
    // TC : O(log n) --> due to power function
    // SC : O(1)
    // Formula : (5 ^ ceil(n/2) * 4 ^ floor(n/2)) mod (10 ^ 9 + 7)
    int countGoodNumbers(long long n)
    {
        long long even_positions = (n + 1) / 2; // ceil(n/2)
        long long odd_positions = n / 2;        // floor(n/2)

        long long even_part = power(5, even_positions);
        long long odd_part = power(4, odd_positions);

        return (even_part * odd_part) % MOD;
    }
};