#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(n + 1);
    for (auto edge : edges)
    {
        adj[edge.first].push_back(edge.second);
    }

    vector<int> vis(n + 1, 0);
    queue<pair<int, int>> ref;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {

            ref.push({i, -1});
            vis[i] = 1;

            while (!ref.empty())
            {
                auto front = ref.front();
                ref.pop();
                int val = front.first;
                int par = front.second;

                for (auto ele : adj[val])
                {
                    if (!vis[ele])
                    {
                        ref.push({ele, val});
                        vis[ele] = 1;
                    }
                    else if (ele != par)
                    {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}
