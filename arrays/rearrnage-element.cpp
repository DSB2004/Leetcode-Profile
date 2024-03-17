// to rearrange element of an array hy there sign

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // One solution can be maintainng 2 lists of positive and negative numbers then again iterating the array and adding the required number as it is
    vector<int> rearrangeArray(vector<int> &nums)
    {
        list<int> pos;
        list<int> neg;

        for (auto n : nums)
        {
            if (n >= 0)
            {
                pos.push_back(n);
            }
            else
            {
                neg.push_back(n);
            }
        }
        for (int i = 0; i < nums.size(); i += 2)
        {
            nums[i] = pos.front();
            nums[i + 1] = neg.front();
            pos.pop_front();
            neg.pop_front();
        }
        return nums;
    }
    // further this can be solved wihtin a single pass by maintaining 2 pointer for even and odd element of result array
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> result(nums.size());
        int odd = 1, even = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                result[even] = nums[i];
                even += 2;
            }
            else if (nums[i] < 0)
            {
                result[odd] = nums[i];
                odd += 2;
            }
        }
        return result;
    }
};