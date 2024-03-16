// 2 sum

#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (temp.find(target - nums[i]) != temp.end())
            {
                return {temp[target - nums[i]], i};
            }
            temp[nums[i]] = i;
        }
        return {};
    }
};