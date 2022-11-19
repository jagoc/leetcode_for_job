# string
## 3. Longest Substring Without Repeating Characters
### Solution
设置2个变量，maxlen表示 无重复substr 最长长度，len表示当前位置对应的 无重复substr 长度；
遍历string，搜索前一个位置对应的len中与当前字符重复的位置，并更新len，以及maxlen；

上述方案使用到了string的substr, find的方法，可以进一步优化；

使用start表示 无重复substr 的初始位置，遍历string，逆序查找[start, i -1]之间是否存在s[i]；并更新start和maxlen；

### Tips
* 建议使用hash表加快查找速度