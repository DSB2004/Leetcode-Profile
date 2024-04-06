// To get the longest possible subarray with sum 0
#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int getLongestZeroSumSubarrayLength(vector<int> &nums)
    {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == 0)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
    int getLongestZeroSumSubarrayLength(vector<int> &nums)
    {
        map<long long, int> ref;
        int maxLen = 0;
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum == 0)
            {
                maxLen = i + 1;
            }
            else if (ref.find(sum) != ref.end())
            {
                maxLen = max(maxLen, i - ref[sum]);
            }
            else
            {
                ref[sum] = i;
            }
        }
        return maxLen;
    }
    int getLongestZeroSumSubarrayLength(vector<int> &nums)
    {

        int i = 0, j = 0;
        long long sum = 0;
        int maxLen = INT_MIN;
        while (i < nums.size() && j < nums.size())
        {
            sum += nums[j];
            while (i <= j && sum > 0)
            {
                sum -= nums[i];
                i++;
            }
            if (sum == 0)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
        return maxLen;
    }
};