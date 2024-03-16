// To find the second largest and second number from the array
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{

    vector<int> getSecondOrderElements(int s, vector<int> nums)
    {

        int Smin = INT_MAX, Min = nums[0], Smax = INT_MIN, Max = nums[0];
        for (auto n : nums)
        {
            if (n > Max)
            {
                Smax = Max;
                Max = n;
            }
            else if (n < Max && n > Smax)
            {
                Smax = n;
            }
            if (n < Min)
            {
                Smin = Min;
                Min = n;
            }
            else if (n > Min && n < Smin)
            {
                Smin = n;
            }
        }
        return {Smax, Smin};
    }
};