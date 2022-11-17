/**
 * 61. Rotate List
 * Given the head of a linked list, rotate the list to the right by k places.
 * 
 * 
 * Constraints:
 *  The number of nodes in the list is in the range [0, 500].
 *  -100 <= Node.val <= 100
 *  0 <= k <= 2 * 10^9
 * 
 */

#include "linked_list.h"

class Solution {
public:
    // case: []; [1]; [1,2],0-10; [1,2,3,4,5],2; [0,1,2],4;
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        
        int len = 0;
        ListNode *slow = head, *fast = head;        
        while (len < k) {
            fast = head;
            for (; len < k && fast; ++len) {
                fast = fast->next;
            }

            if (!fast) {
                k %= len;
                len = 0;
            }
        }
        
        if (!fast)
            return head;

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
    }
};