#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    vector<int> result;
    vector<int> ignore(n, 0);
    queue<int> ref;

    ref.push(0);

    while (!ref.empty())
    {
        int front = ref.front();
        ref.pop();
        result.push_back(front);
        ignore[front] = 1;

        for (const auto &i : adj[front])
        {
            if (ignore[i] == 0)
            {
                ref.push(i);
                ignore[i] = 1;
            }
        }
    }
    return result;
}
