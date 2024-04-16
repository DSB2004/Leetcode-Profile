// to find the minimum value in a rotate sorted array
#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &arr)
    {
        int result = INT_MAX;
        int i = 0, j = arr.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (arr[i] <= arr[mid])
            {
                result = min(result, arr[i]);
                i = mid + 1;
            }
            else
            {
                result = min(result, arr[mid]);
                j = mid - 1;
            }
        }
        return result;
    }
};