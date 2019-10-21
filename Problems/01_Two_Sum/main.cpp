#include <vector>
#include <iostream>

using namespace std;

//// 92.74%, 41.42%
//// Hash set
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> bas;
        for (int i = 0; i < nums.size(); ++i)
        {
            int x = nums[i];
            if (bas.find(target-x) != bas.end()) return vector<int>{i, bas[target-x]};
            bas[x] = i;
        }
        return vector<int>();
    }
};


//// Hash set
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> bas;
        vector<int> answer;
        for (int i = 0; i < nums.size(); ++i) bas.emplace(make_pair(nums[i], i));
        for (int i = 0; i < nums.size(); ++i)
        {
            int tar = target-nums[i];
            if (bas.find(tar) != bas.end() && bas[tar] != i)
            {
                answer.emplace_back(i);
                answer.emplace_back(bas[tar]);
                return answer;
            }
        }
        return answer;
    }
};


//// Brute force
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unsigned long size = nums.size();
//         int target_inside;
//         vector<int> result;
//         for (unsigned int iter = 0; iter < size-1; ++iter)
//         {
//             target_inside = target - nums[iter];
//             for (unsigned int iter_inside = iter+1; iter_inside < size; ++iter_inside)
//             {
//                 if (nums[iter_inside] == target_inside)
//                 {
//                     result.push_back(iter);
//                     result.push_back(iter_inside);
//                     return result;
//                 }
//             }
//         }
//     }
// };
// int main()
// {
//     Solution hello;
//     vector<int> nums = {2,7,11,15};
//     int target = 9;
//     vector<int> result = hello.twoSum(nums, target);
//     cout << "[" << result[1] << ", " << result[2] << "]" << endl;
// }
