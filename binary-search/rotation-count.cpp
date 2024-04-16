// To calculate the no of times an array has been rotated
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findKRotation(vector<int> &arr)
    {
        int result, temp = INT_MAX;
        int i = 0, j = arr.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (arr[i] <= arr[mid])
            {
                if (temp > arr[i])
                {
                    result = i;
                    temp = min(temp, arr[i]);
                }
                i = mid + 1;
            }
            else
            {
                if (temp > arr[mid])
                {
                    result = mid;
                    temp = min(temp, arr[mid]); // Corrected this line
                }
                j = mid - 1;
            }
        }
        return result;
    }
};