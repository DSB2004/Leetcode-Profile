// to sort an array of 0,1,2

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // using DNF algorithm
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++, mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
    // using sort approach
    void sortColors(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
    }

    //  simple iterative approach
    void sortColors(vector<int> &nums)
    {
        int zeros = 0, ones = 0, twos = 0;
        for (auto n : nums)
        {
            if (n == 0)
            {
                zeros++;
            }
            else if (n == 1)
            {
                ones++;
            }
            else
            {
                twos++;
            }
        }
        int i = 0;
        while (zeros > 0)
        {
            nums[i] = 0;
            zeros--;
            i++;
        }
        while (ones > 0)
        {
            nums[i] = 1;
            ones--;
            i++;
        }
        while (twos > 0)
        {
            nums[i] = 2;
            twos--;
            i++;
        }
    }
};