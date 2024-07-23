#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<int>> result(n);

    for (int i = 0; i < n; i++)
    {
        result[i].push_back(i);
    }

    for (const auto &v : edges)
    {
        int first = v.front();
        int second = v.back();
        result[first].push_back(second);
        result[second].push_back(first);
    }
    return result;
}

