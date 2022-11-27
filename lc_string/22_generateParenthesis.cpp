/**
 * 22. Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * 
 * Constraints:
 *  1 <= n <= 8
 * 
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // case: 1; 2; 3; 4; 5;
    vector<string> generateParenthesis(int n) {
        string current;
        vector<string> result;
        // generate(current, n, n, result);
        generate(current, result, 0, 0, n);
        return result;
    }

private:
    void generate(string& current, int left, int right, vector<string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }

        if (left < 0 || right < 0 || left > right)
            return;
        
        current += '(';
        generate(current, left-1, right, result);
        current.pop_back();

        current += ')';
        generate(current, left, right-1, result);
        current.pop_back();
    }

    void generate(string& current, vector<string>& result, int left, int right, int n) {
        if (left == n && right == n) {
            result.push_back(current);
            return;
        }

        if (left < n) {
            current += '(';
            generate(current, result, left+1, right, n);
            current.pop_back();
        }

        if (right < left) {
            current += ')';
            generate(current, result, left, right+1, n);
            current.pop_back();
        }
        return;
    }
};