## linked list
### 2. Add Two Numbers
#### Solution
链表中数字逆序排序，产生的进位会放置到当前节点的next节点中。<br>
新增进位变量carry，通过carry来判断，当前加法是否产生了进位，以及和下一位相加。<br>
同时遍历链表l1, l2，使用 l1->val + l2->val + carry 作为新节点的值，并更新carry；当某个链表遍历结束后，使用未遍历结束的链表，重复上述操作，即可得到新链表；

#### Error (3 times accept)
1. if (!prev) 写成了 if (prev)
2. l1, l2, l 没有遍历
3. 没有考虑到最后产生进位 carry = 1 的情形

#### Summary
* 写完之后，带入case，重新过一遍代码

### 19. Remove Nth Node From End of List
#### Solution
链表的长度为sz，删除倒数第n个节点，即删除正数第sz-n节点的下一个节点；该方案需要遍历2次链表；

#### Standard Solution
由于我们需要找到倒数第 n 个节点，因此我们可以使用两个指针 first 和 second 同时对链表进行遍历，并且 first 比 second 超前 n 个节点。当 first 遍历到链表的末尾时，second 就恰好处于倒数第 n 个节点。该方案只需遍历1次链表；

#### Summary
* 如果对链表有修改操作，考虑创建一个哨兵节点 dummy，这样可以避免对 head 做特殊处理；
* 快慢指针是处理部分链表题目的经典思路
