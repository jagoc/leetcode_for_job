/**
 * 58. Length of Last Word
 * Given a string s consisting of words and spaces, return the length of the last word in the string.
 * A word is a maximal substring consisting of non-space characters only.
 * 
 * 
 * Constraints:
 *  1 <= s.length <= 10^4
 *  s consists of only English letters and spaces ' '.
 *  There will be at least one word in s.
 * 
 */

#include <string>

using namespace std;

class Solution {
public:
    // case: "bob"; "Hello World"; "   fly me   to   the moon  "; "luffy is still joyboy";
    int lengthOfLastWord(string s) {
        int start = 0, end = 0;

        for (start = s.size() - 1; start >= 0; --start) {
            if (s[start] != ' ' && end == 0) {
                end = start;
            }else if (s[start] == ' ' && end != 0) {
                break;
            }
        }

        return end - start;
    }
};