// Rotate Matrix by 90 Degree

#include <bits/stdc++.h>
using namespace std;

// TC : O(N^2)
// SC : O(N)
void rotateBruteForce(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> temp(n, vector<int>(n, 0));

    for (int row = 0; row < n; row++)
    {
        int k = n - 1 - row;
        for (int col = 0; col < n; col++)
        {
            temp[col][k] = matrix[row][col];
        }
    }
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            matrix[row][col] = temp[row][col];
        }
    }
}

// Traverse, Transpose, Reverse
// TC : O(N^2)
// SC : O(1)
void rotateOptimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row; col++)
        {
            swap(matrix[row][col], matrix[col][row]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
