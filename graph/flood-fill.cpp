#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int source = image[sr][sc];
        int n = image.size();
        int m = image[m - 1].size();
        queue<pair<int, int>> ref;
        vector<int> n_row = {0, 0, 1, -1};
        vector<int> n_col = {1, -1, 0, 0};
        vector<vector<int>> vis(m, vector<int>(n, 0));

        ref.push({sr, sc});

        while (!ref.empty())
        {
            auto front = ref.front();
            ref.pop();

            int r = front.first;
            int c = front.second;

            image[r][c] = color;

            for (int k = 0; k < 4; k++)
            {
                int ne_row = r + n_row[k];
                int ne_col = c + n_col[k];

                if (ne_row > -1 && ne_row < n && ne_col > -1 && ne_col < m && vis[ne_row][ne_col] == 0 && image[ne_row][ne_col] == source)
                {
                    ref.push({ne_row, ne_col});
                    vis[ne_row][ne_col] = 1;
                }
            }
        }
        return image;
    }
};