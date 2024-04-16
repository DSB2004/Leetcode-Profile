// Koko eats banana (calculate the minimum number of bananas koko have to eat to finish the piles of bananas in h hours)
#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:

    long long reqTime(vector<int> piles, int canEat)
    {
        long long req = 0;
        for (auto pile : piles)
        {
            req += (long long)ceil((double)(pile) / (double)(canEat));
        }
        return req;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int minRange = 1, maxRange = INT_MIN;
        for (auto pile : piles)
        {
            maxRange = max(maxRange, pile);
        }
        while (minRange <= maxRange)
        {
            int middle = minRange + (maxRange - minRange) / 2;
            long long req = reqTime(piles, middle);
            if (req <= h)
                maxRange = middle - 1;
            else
                minRange = middle + 1;
        }
        return minRange;
    }
};