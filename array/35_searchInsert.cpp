/**
 * 35. Search Insert Position
 * Given a sorted array of distinct integers and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Constraints:
 *  1 <= nums.length <= 10^4
 *  -10^4 <= nums[i] <= 10^4
 *  nums contains distinct values sorted in ascending order.
 *  -10^4 <= target <= 10^4
 * 
 */

#include <vector>

using namespace std;

class Solution {
public:
    // case: [],1; [1],0; [1,3],2; [1,3,5,6],5; [1,3,5,6],2; [1,3,5,6],7;
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int median = left + (right - left >> 1);
            if (nums[median] == target)
                return median;
            else if (nums[median] < target)
                left = median + 1;
            else
                right = median - 1;
        }
        return left;
    }
};