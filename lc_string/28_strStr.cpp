/**
 * 28. Find the Index of the First Occurrence in a String
 * Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
 * or -1 if needle is not part of haystack.
 * 
 * 
 * Constraints:
 *  1 <= haystack.length, needle.length <= 10^4
 *  haystack and needle consist of only lowercase English characters.
 * 
 */

#include <string>

using namespace std;

class Solution {
public:
    // case: "a","a"; "adb","ab"; "sadbutsad","sad";
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.size(); ++i) {
            int k = 0;
            for (int j = i; j < haystack.size() && k < needle.size(); ++j, ++k) {
                if (haystack[j] != needle[k])
                    break;
            }
            if (k == needle.size())
                return i;
        }
        return -1;
    }
};