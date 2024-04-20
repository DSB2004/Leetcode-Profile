// To find the smallest possible divisor which when divided with element of the array gives a sum of quotient sum less than or equal to the threshold value
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int threshold(vector<int> arr, int divisor)
    {
        int result = 0;
        for (auto n : arr)
        {
            result += ceil((double)n / (double)divisor);
        }
        return result;
    }
    int smallestDivisor(vector<int> &arr, int limit)
    {
        int i = 1, j = INT_MIN;
        for (auto n : arr)
        {
            j = max(j, n);
        }
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            int possibleThreshold = threshold(arr, mid);
            if (possibleThreshold <= limit)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return i;
    }
};