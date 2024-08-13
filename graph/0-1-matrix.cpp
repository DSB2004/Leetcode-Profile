#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

        int m = mat.size();
        int n = mat[m - 1].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        vector<int> n_row = {0, 0, 1, -1};
        vector<int> n_col = {1, -1, 0, 0};
        queue<pair<int, int>> ref;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!mat[i][j])
                {
                    ref.push({i, j});
                    result[i][j] = 0;
                }
            }
        }

        while (!ref.empty())
        {
            auto front = ref.front();
            ref.pop();
            int r = front.first;
            int c = front.second;

            for (int k = 0; k < 4; k++)
            {

                int ne_row = r + n_row[k];
                int ne_col = c + n_col[k];

                if (ne_row > -1 && ne_row < m && ne_col > -1 && ne_col < n && result[ne_row][ne_col] == -1)
                {
                    ref.push({ne_row, ne_col});
                    result[ne_row][ne_col] = result[r][c] + 1;
                }
            }
        }
        return result;
    }
};