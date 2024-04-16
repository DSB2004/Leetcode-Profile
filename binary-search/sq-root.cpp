// Find the square root of a number
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int floorSqrt(int n)
    {
        int i = 0, j = n;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            long long sq = (long long)mid * mid;
            if (sq <= n)
            {
                i = mid + 1;
            }
            else if (sq > n)
            {
                j = mid - 1;
            }
        }
        return j;
    }
};