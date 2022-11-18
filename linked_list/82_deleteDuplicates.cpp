/**
 * 82. Remove Duplicates from Sorted List II
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list. Return the linked list sorted as well.
 * 
 * Constraints:
 *  The number of nodes in the list is in the range [0, 300].
 *  -100 <= Node.val <= 100
 *  The list is guaranteed to be sorted in ascending order.
 * 
 */

#include "linked_list.h"

class Solution {
public:
    // case: []; [1]; [1,1]; [1,2]; [1,2,2]; [1,1,1,2,3]; [1,2,3,3,4,4,5];
    // 该写法没有释放内存，请注意!
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode dummy(0);
        ListNode *prev = &dummy, *cur = head;
        prev->next = head;
        while (cur) {
            if (!cur->next || cur->val != cur->next->val) {
                if (prev->next == cur)
                    prev = cur;
                else
                    prev->next = cur->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};