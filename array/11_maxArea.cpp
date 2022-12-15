/**
 * 11. Container With Most Water
 * You are given an integer array height of length n. There are n vertical lines drawn such that 
 * the two endpoints of the ith line are (i, 0) and (i, height[i]).
 * 
 * Find two lines that together with the x-axis form a container, such that the container contains the most water.
 * 
 * Return the maximum amount of water a container can store.
 * 
 * Notice that you may not slant the container.
 * 
 * Constraints:
 *  n == height.length
 *  2 <= n <= 10^5
 *  0 <= height[i] <= 10^4
 * 
 */

#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     // case: [1,1]; [1,2,3]; [2,4,1,2]; [1,8,6,2,5,4,8,3,7]
//     int maxArea(vector<int>& height) {
//         int area = 0, sz = height.size();
//         for (int i = 0; i < sz; ++i) {
//             for (int j = 0; j < sz; ++j) {
//                 if (i != j && height[j] >= height[i])
//                     area = max(area, abs(i-j) * height[i]);
//             }
//         }
//         return area;
//     }
// };


class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            if (height[left] <= height[right]) {
                area = max(area, height[left] * (right - left));
                ++left;
            } else {
                area = max(area, height[right] * (right - left));
                --right;
            }
        }
        return area;
    }
};