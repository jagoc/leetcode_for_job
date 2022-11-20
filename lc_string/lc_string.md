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