/**
 * 14. Longest Common Prefix
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 * 
 * 
 * Constraints:
 *  1 <= strs.length <= 200
 *  0 <= strs[i].length <= 200
 *  strs[i] consists of only lowercase English letters.
 * 
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // case: []; ["ab"]; ["ab","ac"]; ["flower","flow","flight"]; ["dog","racecar","car"];
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        
        string prefix = strs[0];
        for (int i = 0; i < prefix.size(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (prefix[i] != strs[j][i]) {
                    return prefix.substr(0, i);
                }
            }
        }
        return prefix;
    }
};