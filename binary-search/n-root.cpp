// Check for N-root of number
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int checkRoot(int n, int m, int target)
    {
        long long p;
        for (int i = 0; i < n; i++)
        {
            p *= (long long)m;
        }

        if (p == target)
            return 1;
        else if (p > target)
            return 2;
        else
            return 0;
    }
    int NthRoot(int n, int m)
    {
        int i = 0, j = m;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            int result = checkRoot(n, mid, m);
            if (result == 1)
                return mid;
            else if (result == 0)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return -1;
    }
};