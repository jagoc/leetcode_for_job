/**
 * 15. 3Sum
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 * 
 * Constraints:
 *  3 <= nums.length <= 3000
 *  -10^5 <= nums[i] <= 10^5
 * 
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // case: [0,0,0]; [0,1,1]; [-2,-1,0,1,2]; [-1,0,1,2,-1,-4]
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < sz - 2; ++i) {
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            int j = i + 1, k = sz - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    results.push_back({nums[i], nums[j], nums[k]});
                    // 循环放这里，比放下面更优
                    while (nums[++j] == nums[j-1] && j < k);
                    while (nums[--k] == nums[k+1] && j < k);

                } else if (sum < 0) {
                    ++j;
                } else {
                    --k;
                }

                // while (j < k && j > i+1 && nums[j] == nums[j-1])
                //     ++j;
                
                // while (j < k && k < sz-1 && nums[k] == nums[k+1])
                //     --k;
            }

        }
        return results;
    }
};

int main() {
    vector<int> nums{1,2,-2,-1};
    Solution solution;
    auto results = solution.threeSum(nums);
    for (auto & result : results) {
        for (auto & val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}