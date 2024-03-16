//  to find the number that appears once in the array

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int returnVal = 0;
        for (auto n : nums)
        {
            returnVal ^= n;
        }
        return returnVal;
    }
};