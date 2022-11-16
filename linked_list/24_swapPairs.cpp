/**
 * 24. Swap Nodes in Pairs
 * Given a linked list, swap every two adjacent nodes and return its head. 
 * You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
 * 
 * Constraints:
 *  The number of nodes in the list is in the range [0, 100].
 *  0 <= Node.val <= 100
 */

#include "linked_list.h"

class Solution {
public:
    // case: []; [1]; [1,2]; [1,2,3]; [1,2,3,4]
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode dummy;
        ListNode *prev = &dummy, *cur = head, *next = nullptr;
        while (cur && cur->next) {
            next = cur->next->next;
            cur->next->next = cur;
            prev->next = cur->next;
            cur->next = next;
            prev = cur;
            cur = next;
        }
        return dummy.next;
    }
};