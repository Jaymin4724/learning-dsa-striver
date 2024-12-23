#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> small_factors, large_factors;
    int num;
    cin >> num;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            small_factors.push_back(i);
            if (i != num / i)
                large_factors.push_back(num / i);
        }
    }
    for (int i : small_factors)
        cout << i << " ";
    for (int i = large_factors.size() - 1; i >= 0; i--)
        cout << large_factors[i] << " ";
    return 0;
}
