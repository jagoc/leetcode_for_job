# string
## 3. Longest Substring Without Repeating Characters
### Solution
设置2个变量，maxlen表示 无重复substr 最长长度，len表示当前位置对应的 无重复substr 长度；
遍历string，搜索前一个位置对应的len中与当前字符重复的位置，并更新len，以及maxlen；

上述方案使用到了string的substr, find的方法，可以进一步优化；

使用start表示 无重复substr 的初始位置，遍历string，逆序查找[start, i -1]之间是否存在s[i]；并更新start和maxlen；

### Tips
* 建议使用hash表加快查找速度

## 5. Longest Palindromic Substring
### Solution
遍历字符串s, 以i为中心，向左右两边查找回文substr；例如"aba", "abba"

### Error (1 times accept)
1. string的substr方法的第二个参数为count，不是右边界 -_-

### Tips
* 由于针对边界条件 P(i,i), P(i, i+1) 两次获取回文子串，因此可以将获取回文子串的求解部分独立出来

### Extend Solution
* Manacher 算法

## 6. Zigzag Conversion
### Solution
以Z字形的两边长度为一组，分组后，根据当前字母位于的行数，获取其后的字母，并组成该行的字符串，依次遍历直至numRows行。

### Tips
* 合并代码逻辑相同的部分，在相同的部分中处理两者之间的差异
```
for (int i = 0; i < numRows; ++i) {
    // 首尾行
    if (i == 0 || i == numRows - 1) {
        for (int j = i; j < len; j += subLen)
            result += s[j];
    } else {
        for (int j = i; j < len; j += subLen) {
            result += s[j];
            int offset = j + subLen - 2 * i;
            if (offset < len)
                result += s[offset];
        }
    }
}
```
```
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
```

## 14. Longest Common Prefix
### Solution
选取vector中的第一个元素作为基准，依次遍历vector中的剩余元素，判断元素当前位置是否与基准的相同；根据判断结果，获取最长公共前缀。

## 43. Multiply Strings (Incapable)
### Solution
针对短字符串，可以使用遍历，并结合乘法运算律 ab * cd = (a0 + b) * (c0 + d)，完成乘积计算；但是大整数应该怎么求解呢？

大整数，可以针对具体每一位进行求解，这样就不会出现溢出情况

### Standard Solution
令 m 和 n 分别表示 num1 和 num2 的长度，并且它们均不为0，则 num1 和 num2 的乘积的长度为 m+n-1 或 m+n。具体证明过程：略。

由于 num1 和 num2 的乘积的最大长度为 m+n，因此创建长度为 m+n 的数组 ansArr 用于存储乘积。对于任意 i 和 j，num1[i] * num2[j]的结果位于
ansArr[i+j+1]，如果 ansArr[i+j+1] >= 10，则将进位部分加到 ansArr[i+j];


## 58. Length of Last Word
### Solution
从后向前遍历，获取字符串s的最后一个单词的最后一个字母位置；继续遍历，获取最后一个单词的第一个字母位置；两者相减，即可得到最后一个单词的长度。

## 20. Valid Parentheses
### Solution
利用栈的后进先出特性，遍历字符串s，遇到左括号，进栈；遇到右括号，查看是否与栈顶匹配，如果匹配则栈顶元素出栈；重复上述步骤，即可

### Tips
* 将复杂的判断部分独立出来（函数、宏定义），这样更便于代码阅读

## 17. Letter Combinations of a Phone Number
### Solution
1. 遍历digits字符串，当遍历到位置i时，当前`vector<string> result`中是[0, i-1]数字对应的字母组合，将digits[i]对应的字母与result一一组合，并插入result中，依次类推，即可得到最终result。
2. 临界条件，当i = 0时，此时result为空，将digits[0]对应的字母插入至result中。

### Error (1 times accept)
1. 方案没问题，动手能力太差，没写出来；看了参考答案
2. substr获取子字符串写错，写成了`substr(0, sz - 1)`

## 22. Generate Parentheses (Incapable)
### Solution
1. 假设当前数字i对应的合法括号组合存于`result`中，则i+1对应的括号组合：即为遍历result中的每个字符串，将`()`插入每个字符串中，形成新的字符串，并去重；但是怎么去重呢？有没有更简单的方法

### Standard Solution
1. 我们可以生成所有 2^2n 个 '(' 和 ')' 字符构成的序列，然后我们检查每一个是否有效即可。为了生成所有序列，我们可以使用递归。
2. 如果左括号数量不大于 n，我们可以放一个左括号。如果右括号数量小于左括号的数量，我们可以放一个右括号。

## 28. Find the Index of the First Occurrence in a String
### Solution
该问题，即为实现string.find方法

## 12. Integer to Roman
### Solution
num对10进行取模，获取数字i，判断数字i是否是4 or 9；如果不是，则根据数据i > 5的结果，组装罗马数字插入字符串中即可；num = num / 10; 继续上述步骤，不过要考虑当前处理的位数；

方案可行，但是较复杂，时间复杂度为O(n)，不推荐；

### Standard Solution
根据罗马数字的唯一表示法，为了表示一个给定的整数 num，我们寻找不超过 num 的最大符号值，将 num 减去该符号值，然后继续寻找不超过 num 的最大符号值，将该符号拼接在上一个找到的符号之后，循环直至 num为 0。最后得到的字符串即为 num 的罗马数字表示。

编程时，可以建立一个数值-符号对的列表 valueSymbols，按数值从大到小排列。遍历 valueSymbols 中的每个数值-符号对，若当前数值 value 不超过 num，则从 num 中不断减去 value，直至 num 小于 value，然后遍历下一个数值-符号对。若遍历中 num 为 0 则跳出循环。


## 10. Regular Expression Matching
### Solution
1. pattern 如果没有特殊字符，则需和 string 一一匹配
2. pattern 有'.'，则可匹配对应位置的任何字符
3. pattern 有'*'，则可匹配任意个前一个位置的字符，包括0个
4. pattern 有'.*'，则可匹配任意个任意字符，包括0个
双指针，同时遍历 string 和 pattern，根据pattern的字符，判断指针位移，最后确定是否匹配；