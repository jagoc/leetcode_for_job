/**
 * 4. Median of Two Sorted Arrays
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 * 
 * 
 * Constraints:
 *  nums1.length == m
 *  nums2.length == n
 *  0 <= m <= 1000
 *  0 <= n <= 1000
 *  1 <= m + n <= 2000
 *  -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     // case: [],[1]; [],[1,2]; [1,3],[2]; [1,2],[3,4];
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         double result;
//         int m = nums1.size(), n = nums2.size(), len = m + n;
//         int i = 0, j = 0;
//         while (i < m && j < n && i + j < (len - 1) / 2) {
//             if (nums1[i] < nums2[j])
//                 ++i;
//             else
//                 ++j;
//         }

//         if (i == m) {
//             j = (len - 1) / 2 - i;
//             result = (len & 0x01) ? nums2[j] : (double)(nums2[j] + nums2[j+1]) / 2;
//         } else if (j == n) {
//             i = (len - 1) / 2 - j;
//             result = (len & 0x01) ? nums1[i] : (double)(nums1[i] + nums1[i+1]) / 2;
//         } else {
//             if (len & 0x01)
//                 result = min(nums1[i], nums2[j]);
//             else {
//                 if (nums1[i] < nums2[j])
//                     result = nums1[i] + (i + 1 < m && nums1[i+1] < nums2[j] ? nums1[i+1] : nums2[j]);
//                 else
//                     result = nums2[j] + (j + 1 < n && nums2[j+1] < nums1[i] ? nums2[j+1] : nums1[i]);
//                 result /= 2;
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    // case: [],[1]; [],[1,2]; [1,3],[2]; [1,2],[3,4];
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n & 0x01) != 0)
            return getKElement(nums1, nums2, (m + n) / 2 + 1);
        else
            return (double)(getKElement(nums1, nums2, (m + n) / 2) + getKElement(nums1, nums2, (m + n) / 2 + 1)) / 2;
    }

private:
    int getKElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;

        while (i < m && j < n && k > 1) {
            // 注意偏移量计算
            int ii = min(i + k / 2 - 1, m - 1);
            int jj = min(j + k / 2 - 1, n - 1);

            if (nums1[ii] <= nums2[jj]) {
                k -= ii - i + 1;
                i = ii + 1;
            } else {
                k -= jj - j + 1;
                j = jj + 1;
            }
        }

        if (i == m)
            return nums2[j + k - 1];
        if (j == n)
            return nums1[i + k - 1];

        return min(nums1[i], nums2[j]);
    }
};

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
}