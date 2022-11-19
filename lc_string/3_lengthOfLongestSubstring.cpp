/**
 * 3. Longest Substring Without Repeating Characters
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * 
 * Constraints:
 *  0 <= s.length <= 5 * 10^4
 *  s consists of English letters, digits, symbols and spaces.
 * 
 */

#include <string>

using namespace std;

class Solution {
public:
    // ""; "a"; "aa"; "ab"; "aba"; "abcabcbb"; "bbbbb"; "pwwkew";
    // 该方案使用了string的substr, find的方法，可以进一步优化
    // int lengthOfLongestSubstring(string s) {
    //     if (s.empty())
    //         return 0;
        
    //     int maxlen = 1;
    //     string sub = s.substr(0, 1);
    //     for (int i = 1; i < s.size(); ++i) {
    //         auto pos = sub.find(s[i]);
    //         if (pos != string::npos) {
    //             sub = sub.substr(pos + 1) + s[i];
    //         } else {
    //             sub = sub + s[i];
    //         }
    //         if (sub.size() > maxlen)
    //             maxlen = sub.size();
    //     }

    //     return maxlen;
    // }

    // ""; "a"; "aa"; "ab"; "aba"; "abcabcbb"; "bbbbb"; "pwwkew";
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        int start = 0, len = 0, maxlen = 1;
        for (int i = 1; i < s.size(); ++i) {
            for (int j = i - 1; j >= start; --j) {
                if (s[j] == s[i]) {
                    start = j + 1;
                    break;
                }
            }
            len = i - start + 1;
            if (len > maxlen)
                maxlen = len;
        }
        return maxlen;
    }
};
