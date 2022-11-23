/**
 * 43. Multiply Strings
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
 * also represented as a string.
 * 
 * Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
 * 
 * 
 * Constraints:
 *  1 <= num1.length, num2.length <= 200
 *  num1 and num2 consist of digits only.
 *  Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 * 
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // case: 1,0; 2,3; 2,23; 11,39; 123,456; max,max;
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        string result;
        vector<int> resVec = vector<int>(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >=0; --i) {
            int x = num1[i] - '0';
            for (int j = num2.size() - 1; j >= 0; --j) {
                int y = num2[j] - '0';
                resVec[i+j+1] += x * y;
            }
        }

        for (int i = resVec.size() - 1; i > 0; --i) {
            resVec[i-1] += resVec[i] / 10;
            resVec[i] %= 10;
        }

        int idx = resVec[0] == 0 ? 1 : 0;
        for (; idx < resVec.size(); ++idx)
            result.push_back(resVec[idx] + '0');

        return result;
    }
};
