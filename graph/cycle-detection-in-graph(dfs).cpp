#include <iostream>
#include <vector>

using namespace std;
class Graph
{

public:
    bool detectCycleDFS(int node, int par, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto const ele : adj[node])
        {
            if (!vis[ele])
            {
                if (detectCycleDFS(ele, node, adj, vis) == true)
                {
                    return true;
                }
            }
            else if (ele != par)
            {
                return true;
            }
        }
        return false;
    }
    bool detectCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detectCycleDFS(i, -1, adj, vis))
                {
                    return true;
                };
            }
        }
        return false;
    }
};