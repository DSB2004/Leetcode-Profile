// maximum sum in the array
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{

public:
    // the brute force solution can be calculating all the possible subarrays and then checking of the maximum sum possible

    int returnSum(vector<int> &nums, int i, int j)
    {
        int sum = 0;
        for (int k = i; k <= j; k++)
        {
            sum += nums[k];
        }
        return sum;
    }
    int maxSubArray(vector<int> &nums)
    {
        set<int> ref;
        if (nums.size() == 1)
        {
            return nums[0];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                ref.insert(returnSum(nums, i, j));
            }
        }
        int result = INT_MIN;
        for (auto n : ref)
        {
            result = max(result, n);
        }
        return result;
    }

    // the optimised version can be utilising the kadance algorithm
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = INT_MIN;
        int sum = 0;
        for (auto n : nums)
        {
            sum += n;
            maxSum = max(maxSum, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }
};