#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    set<int> s;
    for (auto i : a)
    {
        s.insert(i);
    }
    for (auto j : b)
    {
        s.insert(j);
    }
    vector<int> c;
    for (auto k : s)
    {
        c.emplace_back(k);
    }
    return c;
}
int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    vector<int> arr2 = {1, 7, 8, 9, 0};
    vector<int> arr3 = findUnion(arr1, arr2);
    for (auto i : arr3)
    {
        cout << i << " ";
    }
    return 0;
}