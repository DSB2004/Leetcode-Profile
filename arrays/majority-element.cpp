// majority element (to find the element that appears more than n/2 times in array where n is size of array)
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    // simple approach maintaining a hash map tree for count for each element
    int majorityElement(vector<int> &nums)
    {
        map<int, int> ref;
        for (auto n : nums)
        {
            ref[n]++;
        }
        for (auto p : ref)
        {
            if (p.second > nums.size() / 2)
            {
                return p.first;
            }
        }
        return -1;
    }
    // or by using moore voting algorithm
    int majorityElement(vector<int> &nums)
    {
        int result = nums[0];
        int counter = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            int n = nums[i];
            if (result == n)
            {
                counter++;
            }
            else
            {
                counter--;
                if (counter == 0)
                {
                    result = n;
                    counter++;
                }
            }
        }
        return result;
    }
};