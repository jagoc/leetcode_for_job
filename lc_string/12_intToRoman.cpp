/**
 * 12. Integer to Roman
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. 
 * The number 27 is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. 
 * Instead, the number four is written as IV. Because the one is before the five we subtract it making four. 
 * The same principle applies to the number nine, which is written as IX. 
 * There are six instances where subtraction is used:
 *  I can be placed before V (5) and X (10) to make 4 and 9. 
 *  X can be placed before L (50) and C (100) to make 40 and 90. 
 *  C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * Given an integer, convert it to a roman numeral.
 * 
 * Constraints:
 *  1 <= num <= 3999
 * 
 */

#include <string>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
    // case: 3; 4; 9; 42; 95; 1984
    // string intToRoman(int num) {
    //     unordered_map<int, string> roman{{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}};
    //     string result;
    //     int ratio = 1;
    //     while (num > 0) {
    //         int dig = num % 10;
    //         if (dig == 9)
    //             result = roman[ratio] + roman[ratio*10] + result;
    //         else if (dig == 4)
    //             result = roman[ratio] + roman[ratio*5] + result;
    //         else {
    //             string tmp;
    //             if (dig >= 5) {
    //                 dig -= 5;
    //                 tmp = roman[ratio*5];
    //             }
    //             while (dig--) {
    //                 tmp += roman[ratio];
    //             }
    //             result = tmp + result;
    //         }
    //         num = num / 10;
    //         ratio *= 10;
    //     }
    //     return result;
    // }
// }

const pair<int, string> valueSymbols[] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
    {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} 
};

class Solution {
public:
    string intToRoman(int num) {
        string result;
        for (const auto & [val, sym]: valueSymbols) {
            while (num >= val) {
                result += sym;
                num -= val;
            }
            if (num == 0)
                break;
        }
        return result;
    }
};