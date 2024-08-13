#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{

    vector<vector<int>> adj(n + 1);
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
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

                for (int edge : adj[val])
                {
                    if (!vis[edge])
                    {
                        vis[edge] = 1;
                        ref.push({edge, val});
                    }
                    else if (edge != par)
                    {
                        return "Yes";
                    }
                }
            }
        }
    }
    return "No";
}
