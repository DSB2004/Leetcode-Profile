// // ques name
// #include <iostream>
// #include <unordered_set>
// #include <vector>
// #include <map>
// using namespace std;
// class Solution
// {
// public:
//     // to ques askes us to calculate the max number of subarrays whose sum of element can give us k
//     // (Brute Force): Would be calculating every possible subarray and there sum and if it is equal to the required sum then add a +1 to the result
//     int subarraySum(vector<int> &arr, int k)
//     {
//         int result = 0;
//         int n = arr.size();
//         for (int i = 0; i < n; i++)
//         {
//             long long sum = 0;
//             for (int j = i; j < n; j++)
//             {
//                 sum += (long long)arr[j];
//                 if (sum == k)
//                 {
//                     result++;
//                 }
//             }
//         }
//         return result;
//     }

//     // (Optimised Approach): This would involve a datastructure to keep count of previous sum of the array this would result in a linear time complexcity with a sapce complexcity of O(n) for maintaining the previous sum

//     int subarraySum(vector<int> &arr, int k)
//     {
//         int result = 0;
//         long long sum = 0;
//         unordered_set<long long> ref;
//         for (auto n : arr)
//         {
//             sum += n;
//             if (k == (int)sum)
//             {
//                 result++;
//             }
//             ref.insert(sum);
//             int temp = k - sum;
//             if (ref.find(temp) != ref.end())
//             {
//                 result++;
//             }
//         }
//         return result;
//     }
// };