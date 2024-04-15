// To find a number in a rotated sorted array
#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // Brute Force: The brute force approach can be using linear search on this array to find the element
    int search(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (target == nums[i])
                return i;
        }
        return -1;
    }

    // Optimised approach: To optimised this apporach we can use the binary search with some improvement. Assuming the sorted array(of size n) center is at position k so one side of 0 to k-1 or k to n index of array would be sorted .so using binary search incase if the middle of array is equal to target then returning the index of k but incase it is not then it can exist in either 0 to k-1 or in k to n
    // (incase the value from 0 to k-1 are sorted at the moment) so if the value exist in 0 to k-1, we have to reduce the higher pointer
    //(or if the value from k to n-1 are sorted at the moment) so if the value exist in k to n-1, we have to increase the lower pointer
    int search(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[i] <= nums[mid]) // checking if the value from 0 to mid are sorted
            {
                if (nums[i] <= target && nums[mid] >= target)
                // this means it exist between the value of i pointer to mid
                {
                    j = mid - 1;
                }
                else
                {
                    i = mid + 1;
                }
            }
            else
            // this means it exist between the value of mid pointer to j
            {
                if (nums[mid] <= target && nums[j] >= target)
                {
                    i = mid + 1;
                }
                else
                {
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
};