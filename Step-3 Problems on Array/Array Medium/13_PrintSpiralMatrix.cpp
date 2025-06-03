// Given an m x n matrix, return all elements of the matrix in spiral order.

// matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
#include <bits/stdc++.h>
using namespace std;

// TC : O(M*N)=> O(N^2)
// SC : O(M*N)=> O(N^2)
vector<int> spiralOrder(vector<vector<int>>& matrix) {
vector<int> result;
if (matrix.empty()) return result;

int rowSize = matrix.size();
int colSize = matrix[0].size();
int top = 0, bottom = rowSize - 1;
int left = 0, right = colSize - 1;

while (top <= bottom && left <= right) {
    // left to right
    for (int i = left; i <= right; i++)
        result.push_back(matrix[top][i]);
    top++;

    // top to bottom
    for (int i = top; i <= bottom; i++)
        result.push_back(matrix[i][right]);
    right--;

    // right to left
    if (top <= bottom) {
        for (int i = right; i >= left; i--)
            result.push_back(matrix[bottom][i]);
        bottom--;
    }

    // bottom to top
    if (left <= right) {
        for (int i = bottom; i >= top; i--)
            result.push_back(matrix[i][left]);
        left++;
    }
}

return result;
}
