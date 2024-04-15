// To calculate the first and last occurence of a number

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int x)
    {
        int first = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
        int last = upper_bound(nums.begin(), nums.end(), x) - nums.begin() - 1;
        if (first >= nums.size() || nums[first] != x || nums[last] != x)
        {
            return {-1, -1};
        }
        return {first, last};
    }
};