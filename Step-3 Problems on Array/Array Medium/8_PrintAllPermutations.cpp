#include <bits/stdc++.h>
using namespace std;

/*
----------------------------------------------------------
Approach 1: Using Frequency Array and Current Path Vector
TC: O(n! * n) - because there are n! permutations, and copying each permutation takes O(n)
SC: O(n) - due to the recursion stack, curr[], and freq[] (auxiliary space only)
----------------------------------------------------------
*/
void GetAllPermutations1(vector<int> &arr, vector<int> &curr, vector<bool> &freq, vector<vector<int>> &ans)
{
    // Base Case: One complete permutation formed
    if (curr.size() == arr.size())
    {
        ans.push_back(curr);
        return;
    }

    // Try placing each unused element at the current position
    for (int i = 0; i < arr.size(); ++i)
    {
        if (!freq[i])
        {
            freq[i] = true;
            curr.push_back(arr[i]);

            GetAllPermutations1(arr, curr, freq, ans); // Recurse for next position

            // Backtrack
            curr.pop_back();
            freq[i] = false;
        }
    }
}

/*
----------------------------------------------------------
Approach 2: In-Place Swapping (Backtracking)
TC: O(n! * n) - n! permutations, each copied in O(n)
SC: O(n) - recursion depth is n (no extra space used except the call stack)
----------------------------------------------------------
*/
void GetAllPermutations2(vector<int> &arr, int idx, vector<vector<int>> &ans)
{
    // Base Case: Reached the last position, store the permutation
    if (idx == arr.size() - 1)
    {
        ans.push_back(arr);
        return;
    }

    // Swap current index with all possible indices and recurse
    for (int i = idx; i < arr.size(); i++)
    {
        swap(arr[i], arr[idx]);                 // Choose
        GetAllPermutations2(arr, idx + 1, ans); // Explore
        swap(arr[i], arr[idx]);                 // Unchoose (Backtrack)
    }
}

int main()
{
    // Input array
    vector<int> arr = {1, 2, 3};

    // ---------- Approach 1 ----------
    cout << "1st Approach (Using freq[] and curr[])\n";
    vector<vector<int>> ans1;
    vector<int> curr;
    vector<bool> freq(arr.size(), false);
    GetAllPermutations1(arr, curr, freq, ans1);

    for (auto &perm : ans1)
    {
        cout << "[ ";
        for (int val : perm)
            cout << val << " ";
        cout << "]\n";
    }

    // ---------- Approach 2 ----------
    cout << "\n2nd Approach (In-place swapping)\n";
    vector<vector<int>> ans2;
    GetAllPermutations2(arr, 0, ans2);

    for (auto &perm : ans2)
    {
        cout << "[ ";
        for (int val : perm)
            cout << val << " ";
        cout << "]\n";
    }

    return 0;
}
