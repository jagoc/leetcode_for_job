/**
 * 23. Merge k Sorted Lists
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * 
 * Constraints:
 *  k == lists.length
 *  0 <= k <= 10^4
 *  0 <= lists[i].length <= 500
 *  -10^4 <= lists[i][j] <= 10^4
 *  lists[i] is sorted in ascending order.
 *  The sum of lists[i].length will not exceed 10^4.
 */

#include <vector>

#include "linked_list.h"

using namespace std;

class Solution {
public:
    // case: []; [[]]; [[],[1]]; [[1],[1],[2]]; [[1,4,5],[1,3,4],[2,6]]
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        
        size_t sz = lists.size();
        while (sz > 1) {
            for (int i = 0; i < sz / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[sz - 1 - i]);
            }
            sz = sz - sz / 2;
        }
        return lists[0];
    }

private:
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