// longest subarray with sum k
#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int returnSum(vector<int> &nums, int i, int j)
    {
        int sum = 0;
        for (int k = i; k <= j; k++)
        {
            sum += nums[k];
        }
        return sum;
    }
    int longestSubarrayWithSumK(vector<int> nums, long long k)
    {
        int resultLen = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (returnSum(nums, i, j) == k)
                {
                    resultLen = max(resultLen, j - i + 1);
                }
            }
        }
        return resultLen;
    }

    // using kadance algorithm
    int longestSubarrayWithSumK(vector<int> nums, long long k)
    {
        int i = 0, j = 0;
        long long sum = 0;
        int maxLen = INT_MIN;
        while (i < nums.size() && j < nums.size())
        {
            sum += nums[j];
            while (i <= j && sum > k)
            {
                sum -= nums[i];
                i++;
            }
            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
        return maxLen;
    }
};