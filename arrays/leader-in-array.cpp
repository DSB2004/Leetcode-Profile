// find the leaders in the arrays
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    vector<int> superiorElements(vector<int> &a)
    {
        int maxE = INT_MIN;
        vector<int> result;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            int n = a[i];
            if (maxE < n)
            {
                result.push_back(n);
                maxE = n;
            }
        }
        return result;
    }
};