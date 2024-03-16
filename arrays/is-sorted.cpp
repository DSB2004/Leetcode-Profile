// Check if Array Is Sorted and Rotated
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int counter = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                counter++;
            }
        }
        if (nums[0] < nums[nums.size() - 1])
        {
            counter++;
        }
        return counter <= 1;
    }
};