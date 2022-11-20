/**
 * 5. Longest Palindromic Substring
 * Given a string s, return the longest palindromic substring in s.
 * 
 * 
 * Constraints:
 *  1 <= s.length <= 1000
 *  s consist of only digits and English letters.
 * 
 */

#include <string>

using namespace std;

class Solution {
public:
    // "a"; "aa"; "ab"; "aba"; "abba"; "babad"; "cbbd"
    string longestPalindrome(string s) {
        size_t sublen = 0, len = s.size();
        string substr;
        for (int i = 0; i < len; ++i) {
            int left = i - 1, right = i + 1;
            for (; left >= 0 && right < len; --left, ++right) {
                if (s[left] != s[right])
                    break;
            }
            if (right - left - 1 > sublen) {
                sublen = right - left - 1;
                substr = s.substr(left + 1, sublen);
            }

            if (i + 1 < len && s[i] == s[i + 1]) {
                for (left = i - 1, right = i + 2; left >= 0 && right < len; --left, ++right) {
                    if (s[left] != s[right])
                        break;
                }
                if (right - left - 1 > sublen) {
                    sublen = right - left - 1;
                    substr = s.substr(left + 1, sublen);
                } 
            }
            
        }
        return substr;
    }
};