/**
 * 20. Valid Parentheses
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 *  Open brackets must be closed by the same type of brackets.
 *  Open brackets must be closed in the correct order.
 *  Every close bracket has a corresponding open bracket of the same type.
 * 
 * 
 * Constraints:
 *  1 <= s.length <= 10^4
 *  s consists of parentheses only '()[]{}'.
 * 
 */

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    // case: (); ([]); ([{]}); ([()]());
    bool isValid(string s) {
        int i = 0;
        stack<char> brackets;
        for (; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                brackets.push(s[i]);
            else if (!brackets.empty() && (
                    (brackets.top() == '(' && s[i] == ')') ||
                    (brackets.top() == '{' && s[i] == '}') ||
                    (brackets.top() == '[' && s[i] == ']')))
                brackets.pop();
            else
                break;
        }
        return i == s.size() && brackets.empty();
    }
};