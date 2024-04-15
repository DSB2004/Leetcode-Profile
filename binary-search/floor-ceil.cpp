// Calculate the floor and ceil value for a given number in array of number
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    pair<int, int> getFloorAndCeil(vector<int> &nums, int n, int target)
    {
        int f = -1, c = -1;
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] > target)
            {
                c = nums[mid];
                j = mid - 1;
            }
            else if (nums[mid] < target)
            {
                f = nums[mid];
                i = mid + 1;
            }
            else
            {
                return make_pair(target, target);
            }
        }
        return make_pair(f, c);
    }
};