// Peak Element
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return 0;
        if (arr[0] > arr[1])
            return 0;
        if (arr[n - 2] < arr[n - 1])
            return n - 1;
        int i = 1, j = n - 2;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid] < arr[mid + 1])
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return i;
    }
};