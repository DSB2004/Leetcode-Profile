//  move zero to the end of array 
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0, j = 0;
        while (i < nums.size() && j < nums.size())
        {
            if (nums[i] == 0)
            {
                while (j < nums.size() - 1 && nums[j] != 0)
                {
                    j++;
                }
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
    }
};
