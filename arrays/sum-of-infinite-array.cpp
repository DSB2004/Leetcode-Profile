#include <iostream>
#include <vector>
using namespace std;

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q)
{

    vector<int> result;
    for (auto q : queries)
    {
        long long l = q[0];
        long long r = q[1];

        // converting 1 indexed to 0 indexed
        l = l - 1 - n * (l % n);
        r = r - 1 - n * (r % n);

        long long preResult;
        for (long long i = l; i <= r; i++)
        {
            preResult += arr[i];
        }
        result.push_back(preResult);
    }

    return result;
}