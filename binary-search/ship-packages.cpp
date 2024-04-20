// Capacity To Ship Packages Within D Days
#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> weights, int days, int cap)
    {
        int req = 0;
        int temp = 0;
        for (auto w : weights)
        {
            temp += w;
            if (temp > cap)
            {
                req++;
                if (req > days)
                {
                    return false;
                }
                temp = w;
            }
        }
        if (temp > 0)
        {
            req++;
        }
        return req <= days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int i = INT_MIN, j = 0;
        for (auto w : weights)
        {
            i = max(i, w);
            j += w;
        }
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (isPossible(weights, days, mid))
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