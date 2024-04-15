// search for a number if present return index if not return the most appropriate index 
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
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