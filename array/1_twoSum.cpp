/**
 * 1. Two Sum
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 * 
 * Constraints:
 *  2 <= nums.length <= 10^4
 *  -10^9 <= nums[i] <= 10^9
 *  -10^9 <= target <= 10^9
 *  Only one valid answer exists.
 * 
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time complexity?
 * 
 */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // case: [3,3],6; [3,2,4],6; [2,7,11,15],9;
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap;
        for (int i = 0; i < nums.size(); ++i) {
            auto val = numsMap.find(target - nums[i]);
            if (val != numsMap.end())
                return {val->second, i};
            numsMap[nums[i]] = i;
        }
        return {};
    }
};