// To calculate the lower bound
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lowerBound(vector<int> nums, int n, int target)
    {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return i;
    }
};