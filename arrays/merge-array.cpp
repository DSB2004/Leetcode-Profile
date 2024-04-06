// merge 2 sorted array without using extra space

#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // Brute force: We can just simply put both the sorted array in a new array and return it as a merged array
    void merge(vector<int> &num1, int m, vector<int> &num2, int n)
    {
        int i = 0, j = 0;
        vector<int> result;
        while (i < m && j < n)
        {
            if (num1[i] < num2[j])
            {
                result.push_back(num1[i]);
                i++;
            }
            else
            {
                result.push_back(num2[j]);
                j++;
            }
        }
        while (i < m)
        {
            result.push_back(num1[i]);
            i++;
        }
        while (j < n)
        {
            result.push_back(num2[j]);
            j++;
        }
        num1 = result;
    }
    // Better approach:The above approach has a time and space complexcity of O(m+n) but according to ques we have to store the merged array in num1 only so we can just simply merge the two array and them sort the whole array
    void merge(vector<int> &num1, int m, vector<int> &num2, int n)
    {
        for (int i = m; i < m + n; i++)
        {
            num1[i] = num2[i - m];
        }
        sort(num1.begin(), num1.end());
    }
};