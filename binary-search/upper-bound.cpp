// To calculate the upper bound
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int upperBound(vector<int> nums, int target, int n)
    {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] > target)
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