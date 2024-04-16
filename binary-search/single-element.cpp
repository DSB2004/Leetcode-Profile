// find the non duplicate element in a sorted array of duplicate elements
#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        if (arr.size() == 1)
        {
            return arr[0];
        }
        if (arr[0] != arr[1])
        {
            return arr[0];
        }
        if (arr[arr.size() - 2] != arr[arr.size() - 1])
        {
            return arr[arr.size() - 1];
        }
        int i = 1, j = arr.size() - 2;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (arr[mid - 1] != arr[mid] && arr[mid] != arr[mid + 1])
            {
                return arr[mid];
            }
            else if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid] == arr[mid - 1]))
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return arr[i];
    }
};