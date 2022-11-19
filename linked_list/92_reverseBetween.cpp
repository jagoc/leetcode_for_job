/**
 * 92. Reverse Linked List II
 * Given the head of a singly linked list and two integers left and right where left <= right, 
 * reverse the nodes of the list from position left to position right, and return the reversed list.
 * 
 * Constraints:
 *  The number of nodes in the list is n.
 *  1 <= n <= 500
 *  -500 <= Node.val <= 500
 *  1 <= left <= right <= n
 * 
 * Follow up: Could you do it in one pass?
 */

#include "linked_list.h"

class Solution {
public:
    // []; [1]; [1,2],1,1; [1,2],1,2; [1,2,3],2,3; [1,2,3,4,5],2,4;
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode dummy(0);
        ListNode *prev = &dummy, *prevRe = nullptr, *cur = nullptr, *next = nullptr;
        prev->next = head;
        for (int i = 1; i < left; ++i)
            prev = prev->next;

        prevRe = prev->next;
        cur = prevRe;
        next = cur->next;
        for (int i = left + 1; i <= right; ++i) {
            cur = next;
            next = cur->next;
            cur->next = prevRe;
            prevRe = cur;
        }

        prev->next->next = next;
        prev->next = cur;
    
        return dummy.next;    
    }
};  