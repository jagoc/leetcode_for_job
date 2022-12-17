/**
 * 18. 4Sum
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *  0 <= a, b, c, d < n
 *  a, b, c, and d are distinct.
 *  nums[a] + nums[b] + nums[c] + nums[d] == target
 * 
 * You may return the answer in any order.
 * 
 * Constraints:
 *  1 <= nums.length <= 200
 *  -10^9 <= nums[i] <= 10^9
 *  -10^9 <= target <= 10^9
 * 
 */

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // case: [1]; [1,0,-1]; [-1,0,1,1],2; [2,2,2,2,2],8; [1,0,-1,0,-2,2],0; 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        for (int a = 0; a < n-3; ++a) {
            if (a > 0 && nums[a] == nums[a-1])
                continue;
            // 优化点
            if ((int64_t)nums[a] + nums[a+1] + nums[a+2] + nums[a+3] > target)
                break;
            if ((int64_t)nums[a] + nums[n-3] + nums[n-2] + nums[n-1] < target)
                continue;

            for (int b = a+1; b < n-2; ++b) {
                if (b > a+1 && nums[b] == nums[b-1])
                    continue;
                // 优化点
                if ((int64_t)nums[a] + nums[b] + nums[b+1] + nums[b+2] > target)
                    break;
                if ((int64_t)nums[a] + nums[b] + nums[n-2] + nums[n-1] < target)
                continue;

                int c = b + 1, d = n - 1;
                while (c < d) {
                    int64_t sum = (int64_t)nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum < target)
                        ++c;
                    else if (sum > target)
                        --d;
                    else {
                        results.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while (nums[++c] == nums[c-1] && c < d);
                        while (nums[--d] == nums[d+1] && c < d);
                    }
                }
            }
        }
        return results;
    }
};

int main() {
    vector<int> nums{1000000000,1000000000,1000000000,1000000000};
    int target = 0;
    Solution solution;
    auto results = solution.fourSum(nums, target);
    for (auto & result : results) {
        for (auto & val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}