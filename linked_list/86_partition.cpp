/**
 * 86. Partition List
 * Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * Constraints:
 *  The number of nodes in the list is in the range [0, 200].
 *  -100 <= Node.val <= 100
 *  -200 <= x <= 200
 * 
 */

#include "linked_list.h"

class Solution {
public:
    // case: []; [1]; [2,1],2; [1,3,2],4; [3,1,2],3; [1,4,3,2,5,2],3;
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(0);
        ListNode *prev = &dummy, *cur = &dummy, *temp = nullptr;
        prev->next = head;
        while (cur->next) {
            if (cur->next->val < x) {
                if (prev != cur) {
                    temp = cur->next->next;
                    cur->next->next = prev->next;
                    prev->next = cur->next;
                    cur->next = temp;
                    prev = prev->next;
                    continue;
                } else
                    prev = prev->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};