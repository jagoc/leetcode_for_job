/**
 * 19. Remove Nth Node From End of List
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * 
 * Constraints:
 *  The number of nodes in the list is sz.
 *  1 <= sz <= 30
 *  0 <= Node.val <= 100
 *  1 <= n <= sz
 * 
 * Follow up: Could you do this in one pass?
 */

#include "linked_list.h"

class Solution {
public:
    // case: [1],1; [1,2],2; [1,2,3,4,5],2;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* node = head;
        while (node) {
            ++length;
            node = node->next;
        }

        length -= n;
        node = head;
        if (length < 0)
            return head;
        else if (length == 0) {
            ListNode *next = head->next;
            delete head;
            head = nullptr;
            return next;
        }

        while (--length) {
            node = node->next;
        }
        ListNode *next = node->next->next;
        delete node->next;
        node->next = next;
        return head;
    }
};

// Best Solution
class Solution {
public:
    // case: [1],1; [1,2],2; [1,2,3,4,5],2;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        ListNode *first = head, *second = dummy;
        dummy->next = head;
        while (n--) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }

        if (second == dummy)
            head = head->next;
        ListNode *del = second->next;
        second->next = second->next->next;
        delete del, dummy;
        return head;
    }
};