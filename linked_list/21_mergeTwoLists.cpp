/**
 * 21. Merge Two Sorted Lists
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
 * 
 * Constraints:
 *  The number of nodes in both lists is in the range [0, 50].
 *  -100 <= Node.val <= 100
 *  Both list1 and list2 are sorted in non-decreasing order.
 */

#include "linked_list.h"


class Solution {
public:
    // case: [],[]; [1],[]; [1],[3]; [1,5],[1]; [1,2,4],[1,3,4];
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        else if (!list2)
            return list1;
        
        ListNode *mergeHead = nullptr;
        if (list1->val > list2->val) {
            mergeHead = list2;
            mergeHead->next = mergeTwoLists(list1, list2->next);
        } else {
            mergeHead = list1;
            mergeHead->next = mergeTwoLists(list1->next, list2);
        }
        return mergeHead;
    }

    // loop
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        else if (!list2)
            return list1;
        
        ListNode *mergeHead = nullptr, *prev = nullptr;
        while (list1 && list2) {
            ListNode *node = nullptr;
            if (list1->val > list2->val) {
                node = list2;
                list2 = list2->next;
            } else {
                node = list1;
                list1 = list1->next;
            }
            if (!prev) {
                prev = node;
                mergeHead = prev;
            } else {
                prev->next = node;
                prev = prev->next;
            }
        }

        prev->next = list1 ? list1 : list2;
        return mergeHead;
    }
};