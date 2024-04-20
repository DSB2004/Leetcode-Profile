// ques name
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int noOfBouquet(vector<int> arr, int flowerReq, int timeLimit)
    {
        int possibleBouquot = 0;
        int flowerPlucked = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= timeLimit)
            {
                flowerPlucked++;
            }
            else
            {
                possibleBouquot += (flowerPlucked / flowerReq);
                flowerPlucked = 0;
            }
        }

        possibleBouquot += (flowerPlucked / flowerReq);
        return possibleBouquot;
    }
    int minDays(vector<int> &arr, int m, int k)
    {
        if (arr.size() < (long long)m * k)
        {
            return -1;
        }
        int minDay = INT_MAX, maxDay = INT_MIN;
        for (auto n : arr)
        {
            minDay = min(minDay, n);
            maxDay = max(maxDay, n);
        }
        while (minDay <= maxDay)
        {
            int mid = minDay + (maxDay - minDay) / 2;
            int bouquotPossible = noOfBouquet(arr, k, mid);
            if (bouquotPossible < m)
            {
                minDay = mid + 1;
            }
            else
            {
                maxDay = mid - 1;
            }
        }
        return minDay;
    }
};
