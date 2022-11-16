/**
 * 2. Add Two Numbers
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Constraints:
 *  The number of nodes in each linked list is in the range [1, 100].
 *  0 <= Node.val <= 9
 *  It is guaranteed that the list represents a number that does not have leading zeros.
 */

#include <cstdint>
#include <stdexcept>

#include "linked_list.h"


class Solution {
public:
    // case: [],[]; [1],[9]; [2,9],[9]; [2,4,3],[5,6,4]; [9,9,9,9,9,9,9],[9,9,9,9];
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2)
            throw invalid_argument("Invalid Input!");

        ListNode *head = nullptr, *prev = nullptr;
        int8_t carry = 0;

        while (l1 && l2) {
            int8_t val = l1->val + l2->val + carry;
            carry = val / 10;
            ListNode *node = new ListNode(val % 10);
            if (!prev) {
                prev = node;
                head = node;
            } else {
                prev->next = node;
                prev = prev->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *l = l1 ? l1 : l2;
        while (l) {
            int8_t val = l->val + carry;
            carry = val / 10;
            prev->next = new ListNode(val % 10);
            prev = prev->next;
            l = l->next;
        }

        if (carry > 0)
            prev->next = new ListNode(carry);

        return head;
    }
};
