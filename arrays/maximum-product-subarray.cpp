#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int> &arr)
{
    int n = arr.size();
    int result = INT_MIN;
    int prefix_product = 1;
    int suffix_product = 1;

    for (int i = 0; i < n; i++)
    {
        if (prefix_product == 0)
            prefix_product = 1;
        if (suffix_product == 0)
            suffix_product = 1;
        prefix_product *= arr[i];
        suffix_product *= arr[n - i - 1];
        result = max(result, max(suffix_product, prefix_product));
    }
    return result;
}
