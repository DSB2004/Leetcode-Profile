// to print a matrix in spiral order

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // To print the spiral order of any matrix we first have to maintain 4 pointer top and left initialized at 0 and right and bottom initialized at the end of matrix column and row respectively then firstly we iterate the top of the matrix from left to right and increase the top to 1 then we iterate the right from top to bottom decreasing the right pointer by 1 then iterate the bottom from right to left decreasing the bottom by 1 and atlast iterating the left side bottom to top and increase the left side by one we continue this appraoch until the whole matrix has been itrerated .Note: While iterating the bottom and left side we first have to check that is there any left and bottom side left to iterate or not

    vector<int> spiralMatrix(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int top = 0, left = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                result.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                result.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    result.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    result.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return result;
    }
};