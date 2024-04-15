// ques name
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int count(vector<int> &nums, int n, int x)
    {
        int first = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
        int last = upper_bound(nums.begin(), nums.end(), x) - nums.begin() - 1;
        if (first < nums.size() && nums[first] == x)
        {
            return last - first + 1;
        }
        return 0;
    }
};