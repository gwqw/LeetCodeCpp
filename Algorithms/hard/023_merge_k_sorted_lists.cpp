/**
    23. Merge k Sorted Lists
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

Algo: use priority_queue for next_index: O(N*K*logK) + O(K)
- k lists
- make min pq and add non-zero heads for all lists, cmp is compare vals
- while pq not empty:
    - pop top node from pq
    - add to res
    - if not null, add node->next
n - list length, k - num of lists

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* lhs, ListNode* rhs) {return lhs->val > rhs->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        // make min_heap
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        // get answer
        ListNode* res = nullptr;
        ListNode* last = nullptr;
        while (!pq.empty()) {
            auto list = pq.top();
            pq.pop();
            if (!res) {
                res = list;
                last = res;
            } else {
                last->next = list;
                last = last->next;
            }
            if (list->next) {
                pq.push(list->next);
            }
        }
        if (last) {
            last->next = nullptr;
        }
        return res;
    }
};