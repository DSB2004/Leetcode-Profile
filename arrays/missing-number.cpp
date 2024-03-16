// Missing Number in an array of [0,n] having n distinct numbers
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sumE = (n * (n + 1)) / 2;
        for (auto e : nums)
        {
            sumE -= e;
        }
        return sumE;
    }
};