/**
 * 83. Remove Duplicates from Sorted List
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
 * Return the linked list sorted as well.
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
    // case: []; [1]; [1,1]; [1,2]; [1,1,2]; [1,1,2,3,3];
    // 该写法没有释放内存，请注意!
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) 
            return head;
        
        ListNode *prev = head, *cur = head->next;
        while (cur) {
            if (prev->val != cur->val) {
                prev->next = cur;
                prev = prev->next;
            }
            cur = cur->next;
        }
        prev->next = cur;
        return head;
    }
};