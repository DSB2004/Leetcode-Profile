#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // starting node is 1
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int result = 0;
        vector<int> ignore(n, 0);
        queue<int> ref;

        for (int i = 0; i < n; i++)
        {
            if (ignore[i] == 0)
            {
                result++;
                ref.push(i);
                ignore[i] = 1;
                while (!ref.empty())
                {
                    int front = ref.front();
                    ref.pop();
                    for (int j = 0; j < n; j++)
                    {
                        if (isConnected[front][j] == 1 && ignore[j] == 0)
                        {
                            ref.push(j);
                            ignore[j] = 1;
                        }
                    }
                }
            }
        }
        return result;
    }
};