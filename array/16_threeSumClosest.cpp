/**
 * 16. 3Sum Closest
 * Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * 
 * Constraints:
 *  3 <= nums.length <= 500
 *  -1000 <= nums[i] <= 1000
 *  -10^4 <= target <= 10^4
 * 
 */

#include <climits>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     // case: [0,0,0],1; [-1,2,1,-4],1;
//     int threeSumClosest(vector<int>& nums, int target) {
//         int interval = INT_MAX, result = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             for (int j = i + 1; j < nums.size(); ++j) {
//                 for (int k = j + 1; k < nums.size(); ++k) {
//                     int sum = nums[i] + nums[j] + nums[k];
//                     int temp = abs(sum - target);
//                     if (temp < interval) {
//                         interval = temp;
//                         result = sum;
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };


class Solution {
public:
    // case: [0,0,0],1; [-1,2,1,-4],1;
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            throw invalid_argument("Invalid Input!");

        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int result = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < sz; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            int j = i + 1, k = sz - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return target;
                
                if (abs(sum - target) < abs(result - target))
                    result = sum;
                
                if (sum < target) {
                    while (j < k && nums[j] == nums[j+1])
                        ++j;
                    ++j;
                } else {
                    while (j < k && nums[k] == nums[k-1] )
                        --k;
                    --k;
                }
            }
        }
        return result;
    }
};

