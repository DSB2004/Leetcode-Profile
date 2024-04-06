//  4 Sum:  To find all the 4 number set from an array whose sum are equal to given value target
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:

    // Brute force: We can simply just iterate the whole array 4 times taking all possible number from array which sum up to give value target
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> ref;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                        {
                            vector<int> temp = {nums[i],
                                                nums[j],
                                                nums[k],
                                                nums[l]};
                            sort(temp.begin(), temp.end());
                            ref.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> result(ref.begin(), ref.end());
        return result;
    }

    // Better Approach:  We can use a map to store the previous value from the array and this can reduce the time complexcity from  O(n^4) to O(n^3.logn)
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> ref;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                map<int, int> refMap;
                for (int k = j + 1; k < n; k++)
                {
                    int req = target - (nums[i] + nums[j] + nums[k]);
                    if (refMap.find(req) != refMap.end())
                    {
                        vector<int> temp = {nums[i],
                                            nums[j],
                                            nums[k],
                                            req};
                        sort(temp.begin(), temp.end());
                        ref.insert(temp);
                    }
                    refMap[nums[k]] = k;
                }
            }
        }
        vector<vector<int>> result(ref.begin(), ref.end());
        return result;
    }

    // Optimsed Approach: To further optimise this we can simply use two pointer approach for the last two element of the array and for the first two we can iterate the array
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> ref;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int start = j + 1, end = n - 1;
                while (start < end)
                {
                    long long req = nums[i] + nums[j];
                    req += nums[start];
                    req += nums[end];
                    if (req == target)
                    {
                        ref.insert({nums[i], nums[j], nums[start], nums[end]});
                        start++, end--;
                        while (start < end && nums[start] == nums[start - 1])
                        {
                            start++;
                        }
                        while (start < end && nums[end] == nums[end + 1])
                        {
                            end--;
                        }
                    }
                    else if (req > target)
                    {
                        end--;
                    }
                    else
                    {
                        start++;
                    }
                }
            }
        }
        vector<vector<int>> result(ref.begin(), ref.end());
        return result;
    }
};