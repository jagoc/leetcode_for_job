/**
 * 25. Reverse Nodes in k-Group
 * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the linked list. 
 * If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 * 
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
 * 
 * Constraints:
 *  The number of nodes in the list is n.
 *  1 <= k <= n <= 5000
 *  0 <= Node.val <= 1000
 * 
 * Follow-up: Can you solve the problem in O(1) extra memory space?
 */

#include "linked_list.h"


class Solution {
public:
    // case: []; [1],1; [1,2],1; [1,2],2; [1,2,3,4,5],2; [1,2,3,4,5],3;
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *cur = head, *next = nullptr, *temp = nullptr;
        while (cur) {
            for (int i = 1; i < k && cur; ++i) {
                cur = cur->next;
            }

            if (cur) {
                next = cur->next;
                cur->next = nullptr;
                reverseList(prev->next);
                temp = prev->next;
                temp->next = next;
                prev->next = cur;

                prev = temp;
                cur = next;
            }
        }

        return dummy.next;
    }

private:
    void reverseList(ListNode* head) {
        ListNode *prev = nullptr, *cur = head, *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return;
    }
};