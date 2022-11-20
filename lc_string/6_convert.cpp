/**
 * 6. Zigzag Conversion
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string s, int numRows);
 * 
 * 
 * Constraints:
 *  1 <= s.length <= 1000
 *  s consists of English letters (lower-case and upper-case), ',' and '.'.
 *  1 <= numRows <= 1000
 * 
 */

#include <string>

using namespace std;

class Solution {
public:
    // case: "a"; "ab",1/2; "abc",1/2; "abcd",1/2/3; "abcde",1/2/3/4; "PAYPALISHIRING",1/2/3/4/5 
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        int len = s.size();
        int subLen = numRows + (numRows - 2);
        string result;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < len; j += subLen) {
                result += s[j];
                if (i > 0 && i < numRows - 1) {
                    int offset = j + subLen - 2 * i;
                    if (offset < len)
                        result += s[offset];
                }
            }
        }
        return result;
    }
};