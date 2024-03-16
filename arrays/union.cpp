// find the union of 2 sorted arrays
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void toAdd(vector<int> &result, int val)
    {
        if (result.empty())
        {
            result.push_back(val);
        }
        else if (result.back() != val)
        {
            result.push_back(val);
        }
    }
    vector<int> sortedArray(vector<int> a, vector<int> b)
    {
        vector<int> result;
        int i = 0, j = 0, m = a.size(), n = b.size();
        while (i < m && j < n)
        {
            if (a[i] <= b[j])
            {
                toAdd(result, a[i]);
                i++;
            }
            else
            {
                toAdd(result, b[j]);
                j++;
            }
        }
        while (i < m)
        {
            toAdd(result, a[i]);
            i++;
        }
        while (j < n)
        {
            toAdd(result, b[j]);
            j++;
        }
        return result;
    }
};
