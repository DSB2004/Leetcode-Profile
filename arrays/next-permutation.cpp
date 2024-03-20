//  find the next permutation
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int dropIndex = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                dropIndex = i;
                break;
            }
        }
        if (dropIndex == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int ReqI = dropIndex + 1;
        for (int i = dropIndex + 2; i < n; i++)
        {
            if (nums[ReqI] > nums[i])
            {
                ReqI = i;
            }
        }
        swap(nums[ReqI], nums[dropIndex]);
        sort(nums.begin() + dropIndex + 1, nums.end());
    }
};
// // first to find the drip in the array
// int drip_index = -1;
// for (int i = nums.size() - 1; i > 0; i--)
// {
//     if (nums[i] < nums[i - 1])
//     {
//         drip_index = i;
//         break;
//     }
// }
// if (drip_index == -1)
// {
//     sort(nums.begin(), nums.end());
//     return;
// }
// int maxIndex = drip_index;
// for (int i = drip_index + 1; i < nums.size(); i++)
// {
//     if (nums[maxIndex] < nums[i])
//     {
//         maxIndex = i;
//     }
// }
// swap(nums[maxIndex], nums[drip_index]);
// sort(nums.begin() + drip_index, nums.end());