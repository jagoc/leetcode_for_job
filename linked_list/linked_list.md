# linked list
## 2. Add Two Numbers
### Solution
链表中数字逆序排序，产生的进位会放置到当前节点的next节点中。<br>
新增进位变量carry，通过carry来判断，当前加法是否产生了进位，以及和下一位相加。<br>
同时遍历链表l1, l2，使用 l1->val + l2->val + carry 作为新节点的值，并更新carry；当某个链表遍历结束后，使用未遍历结束的链表，重复上述操作，即可得到新链表；<br>

### Error (3 times accept)
1. if (!prev) 写成了 if (prev)
2. l1, l2, l 没有遍历
3. 没有考虑到最后产生进位 carry = 1 的情形

### Tips
* 写完之后，带入case，重新过一遍代码

## 19. Remove Nth Node From End of List
### Solution
链表的长度为sz，删除倒数第n个节点，即删除正数第sz-n节点的下一个节点；该方案需要遍历2次链表；

### Standard Solution
由于我们需要找到倒数第 n 个节点，因此我们可以使用两个指针 first 和 second 同时对链表进行遍历，并且 first 比 second 超前 n 个节点。当 first 遍历到链表的末尾时，second 就恰好处于倒数第 n 个节点。该方案只需遍历1次链表；

### Tips
* 如果对链表有**修改操作**，考虑创建一个哨兵节点 dummy，这样可以避免对 head 做特殊处理；
* 快慢指针是处理部分链表题目的经典思路

## 21. Merge Two Sorted Lists
### Solution
合并2个正序链表，有循环和递归2种方法。
循环：遍历2个正序链表，比较当前值的大小，确定合并后的节点；需要prev指针
递归：比较当前值的大小，确定合并后的节点，针对链表的next节点，递归调用该函数

## 23. Merge k Sorted Lists
### Solution
对折合并？
将vector中的元素list，看成1个整体；则该问题可以转化为对vector中的元素进行合并；遍历vector，考虑首尾两两分组合并，直至合并结束；然后调整数组长度，继续上述合并操作；
在合并两元素时，采用上述的**21. Merge Two Sorted Lists** 的方法即可。

### Error (1 times accept)
1. return lists[0]; 写成了 return lists[1]; -_-

### Standard Solution
分治合并：将vector 一分为二，递归合并其左右链表；时间复杂度 O(kn * logk)，空间复杂度 O(logk)。
优先队列合并：我们需要维护当前每个链表没有被合并的元素的最前面一个，k 个链表就最多有 k 个满足这样条件的元素，每次在这些元素里面选取 val 属性最小的元素合并到答案中。在选取最小元素的时候，我们可以用优先队列来优化这个过程。时间复杂度 O(kn * logk)，空间复杂度 O(k)。

## 24. Swap Nodes in Pairs
### Solution
创建一个哨兵节点 dummy，避免针对头结点的特殊处理；同时使用3指针(prev, cur, next)对链表相邻节点进行交换。

## 25. Reverse Nodes in k-Group
### Solution
k个节点一组反转链表，可以将k个节点看成一个独立的链表；则该问题可以转化为反转n/k个链表；注意处理反转后的头结点和尾结点;

## 61. Rotate List
### Solution
思路类似**19. Remove Nth Node From End of List**，使用快慢指针；

首先快指针遍历链表，走k步，如果此时已超出链表长度length，则计算k = k % length，在重v新走k步；之后快慢指针一起走，当快指针走到链表尾时，此时慢指针的位置为旋转后的新链表头，调整指针指向即可。

### Error (1 times accept)
1. 考虑不全，忽略了k是length倍数的情况

### Tips
* **涉及for循环以及需要累积计算长度的问题时**，写代码前要考虑清楚，不要等代入case验证时，才确定