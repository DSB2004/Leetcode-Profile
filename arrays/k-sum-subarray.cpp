// Longest Subarray With Sum K for positive value only
// (sliding window approach)

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int longestSubarrayWithSumK(vector<int> nums, long long k)
    {
        int maxE = INT_MIN;
        long long sum = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum > k)
            {
                sum -= nums[i];
                i++;
            }
            if (sum == k)
            {
                maxE = max(maxE, j - i + 1);
            }
        }
        return maxE;
    }
};