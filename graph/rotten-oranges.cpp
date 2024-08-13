#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        int freshOrange = 0;
        int timeRequired = 0;
        int n = grid.size();
        int m = grid[n - 1].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> ref;

        // first calculating the no of fresh oranges and pushing rotten oranges in the queue

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    freshOrange++;
                    vis[i][j] = 1;
                }
                else if (grid[i][j] == 2)
                {
                    ref.push({make_pair(i, j), 0});
                    vis[i][j] = 2;
                }
            }
        }

        // neighbour array
        vector<int> n_row = {0, 0, 1, -1};
        vector<int> n_col = {1, -1, 0, 0};

        // using bfs over the grid to rot oranges

        while (!ref.empty())
        {

            auto front = ref.front();

            int row = front.first.first;
            int col = front.first.second;
            int tim = front.second;
            ref.pop();

            for (int k = 0; k < 4; k++)
            {
                int ne_row = row + n_row[k];
                int ne_col = col + n_col[k];

                if (ne_row > -1 && ne_row < n && ne_col > -1 && ne_col < m && vis[ne_row][ne_col] == 1 && grid[ne_row][ne_col] == 1)
                {
                    ref.push({{ne_row, ne_col}, tim + 1});
                    vis[ne_row][ne_col] = 2;
                    freshOrange--;
                    timeRequired = max(timeRequired, tim + 1);
                }
            }
        }

        return (freshOrange > 0) ? -1 : timeRequired;
    }
};