//  to calculate the max number of ones appearing in the array

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxO = 0;
        int counter = 0;
        for (auto n : nums)
        {
            if (n == 1)
            {
                counter++;
                maxO = max(counter, maxO);
            }
            else
            {
                counter = 0;
            }
        }
        return maxO;
    }
};