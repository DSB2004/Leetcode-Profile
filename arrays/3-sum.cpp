// 3 sum to find all the 3 number set from an array whose sum are equal to 0

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // BRUTE FORCE APPROACH: To solve this problem we can simply take 3 nested loops iterating over the array and checking for required sum
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> temp;
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int sum = 0;
                for (int k = j + 1; k < nums.size(); k++)
                {
                    sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0)
                    {
                        vector<int> ref = {nums[i], nums[j], nums[k]};
                        sort(ref.begin(), ref.end());
                        temp.insert(ref);
                    }
                }
            }
        }
        for (auto p : temp)
        {
            result.push_back(p);
        }

        return result;
    }
    // Better Approach:  the above appraoch has a time complexicity of O(n^3) along with extra space complexcity for the set . To optimise the time complexicity we can use the map data structure to keep track of number we get behind optimising the time complexicity to O(n^2.log n)

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> temp;
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
        {
            map<int, int> refMap;
            for (int j = i + 1; j < nums.size(); j++)
            {
                int sum = 0 - (nums[i] + nums[j]);
                if (refMap.find(sum) != refMap.end())
                {

                    vector<int> ref = {
                        nums[i],
                        nums[j],
                        sum};
                    sort(ref.begin(), ref.end());
                    temp.insert(ref);
                }
                refMap[nums[j]] = j;
            }
        }
        for (auto p : temp)
        {
            result.push_back(p);
        }

        return result;
    }
    // Optimised Approach: can be by using 2 pointer approach where firstly the whole array would be sorted then using a posinter to iterate over the an element we will run a binary search for each element whose combine sum would be equal to 0

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> ref;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                int start = i + 1;
                int end = n - 1;
                int sum = 0;
                while (start < end)
                {
                    sum = nums[i] + nums[start] + nums[end];
                    if (sum == 0)
                    {
                        ref.insert({nums[i], nums[start], nums[end]});
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
                    else if (sum < 0)
                    {
                        start++;
                    }
                    else if (sum > 0)
                    {
                        end--;
                    }
                }
            }
        }
        vector<vector<int>> result(ref.begin(), ref.end());
        return result;
    }
};