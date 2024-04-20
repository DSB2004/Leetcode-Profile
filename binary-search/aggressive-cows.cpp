//  Aggressive Cows
#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> stalls, int k, int dis)
    {
        int lastStand = stalls[0];
        int placed = 1;
        for (int i = 0; i < stalls.size(); i++)
        {
            if (stalls[i] - lastStand >= dis)
            {
                placed++;
            }
        }
        return placed >= k;
    }
    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());
        int i = 1, j = (stalls.end() - stalls.begin()) - stalls[0];
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (isPossible(stalls, k, mid))
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return i;
    }
};