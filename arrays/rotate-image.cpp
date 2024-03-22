// Rotate Image : To ratate a matrix 90deg
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    //(Brute Force): To rotate a matrix 90 degrees clockwise, observe that the column index of an element in the rotated matrix corresponds to the row index of the original matrix, and the top row elements in the original matrix are positioned to the extreme right in the rotated matrix.so by this observation we can solve this problem
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> result(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[j][n - i - 1] = matrix[i][j];
            }
        }

        matrix = result;
    }

    // (Optimised Approach):  To rotate a matrix 90 degrees clockwise, we can calculate the transpose of the whole matrix and then reverse each row of the matrix resulting in the required matrix.
    void rotate(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int column = matrix[0].size();
        // calculating the transpose
        for (int i = 0; i < row; i++)
        {
            for (int j = i; j < column; j++)
            {
                if (i != j)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        // reverse each row of matrix
        for (int i = 0; i < row; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

