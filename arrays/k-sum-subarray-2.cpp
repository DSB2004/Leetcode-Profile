// Longest Subarray With Sum K (+ve/-ve)
// (hashmap approach)

#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

class Solution
{
public:
    int getLongestSubarray(vector<int> &nums, int k)
    {
        int maxE = 0;
        int sum = 0;
        map<int, int> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum == k)
            {
                maxE = max(maxE, i + 1);
            }
            if (temp.find(sum) == temp.end())
            {
                temp[sum] = i;
            }
            if (temp.find(sum - k) != temp.end())
            {
                maxE = max(maxE, i - temp[sum - k]);
            }
        }
        return maxE;
    }
};