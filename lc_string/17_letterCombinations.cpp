/**
 * 17. Letter Combinations of a Phone Number
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
 * Return the answer in any order.
 * 
 * A mapping of digits to letters (just like on the telephone buttons) is given below. 
 * Note that 1 does not map to any letters.
 * 
 * 
 * Constraints:
 *  0 <= digits.length <= 4
 *  digits[i] is a digit in the range ['2', '9'].
 * 
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // case: ""; "2"; "23"; "234"; "2345"
    vector<string> letterCombinations(string digits) {
        vector<string> buttons = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        for (int i = 0; i < digits.size(); ++i) {
            int idx = digits[i] - '2';
            int sz = result.size();
            for (int j = 0; j < buttons[idx].size(); ++j) {
                if (sz == 0)
                    result.emplace_back(1, buttons[idx][j]);
                for (int k = 0; k < sz; ++k) {
                    if (j == 0)
                        result[k] += buttons[idx][j];
                    else
                        result.emplace_back(result[k].substr(0, i) + buttons[idx][j]);
                }
            }
        }
        return result;
    }
};