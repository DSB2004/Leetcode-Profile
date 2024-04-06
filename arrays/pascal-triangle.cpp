// Pascal Triangle
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    // Approach: we can simply follow the intution of nCr in pascal triangle to calculate the pascal triangle

    int cpr(int n, int r)
    {
        int result = 1;
        for (int i = 0; i < r; i++)
        {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;

        // nCr = (n!)/(r!)(n-r)!   or  n*(n-1)...*(n-r+1)/r*(r-1)*(r-2)...*1
    }
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                result[i].push_back(cpr(i, j));
            }
        }
        return result;
    }
};