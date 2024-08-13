#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfsPath(int node, vector<vector<int>> adj, vector<int> &path, vector<int> &ignore, int target)
{
    if (ignore[target] == 1)
    {
        return;
    }
    ignore[node] = 1;
    path.push_back(node);

    for (auto e : adj[node])
    {
        if (ignore[e] == 0)
        {
            dfsPath(e, adj, path, ignore, target);
        }
    }
}

vector<int> getPath(int V, int E, vector<int> a, vector<int> b, int v1, int v2)
{
    vector<vector<int>> adj(V);

    // first created a adjancy list

    for (int i = 0; i < a.size(); i++)
    {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    vector<int> path, ignore(V, 0);
    dfsPath(v1, adj, path, ignore, v2);
    if (ignore[v1] == 1 && ignore[v2] == 1)
    {
        return path;
    }
    return {};
}