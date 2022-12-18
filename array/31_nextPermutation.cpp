/**
 * 31. Next Permutation
 * A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
 * 
 *  For example, for arr = [1,2,3], 
 *  the following are all the permutations of arr: [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].
 * 
 * The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
 * More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, 
 * then the next permutation of that array is the permutation that follows it in the sorted container. 
 * If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
 * 
 *  For example, the next permutation of arr = [1,2,3] is [1,3,2].
 *  Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
 *  While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
 * 
 * Given an array of integers nums, find the next permutation of nums.
 * 
 * The replacement must be in place and use only constant extra memory.
 * 
 * Constraints:
 *  1 <= nums.length <= 100
 *  0 <= nums[i] <= 100
 * 
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // case: [1]; [2,1]; [1,2,3]; [3,2,1]; [1,1,5]; [1,1,1];
    void nextPermutation(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        for (left = right; left > 0; --left) {
            if (nums[left-1] < nums[left]) {
                for (int i = right; i >= left; --i) {
                    if (nums[i] > nums[left-1]) {
                        swap(nums[left-1], nums[i]);
                        break;
                    }
                }
                break;
            }
        }
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
        return;
    }
};