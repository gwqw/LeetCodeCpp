/**
21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

Algo:
n = l1->next
while n and l2
  n->val <= l2->val:
    l1 = n
    n = l1->next
  n->val > l2->val (else):
    l1->next = l2
    l2 = l2->next
    l1 = l1->next
    l1->next = n       
if l2:
  l1->next = l2

Algo2: make new list and fill it's next fields
- use ref to node
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val > l2->val) {
            swap(l1, l2);
        }
        ListNode* head = l1;
        
        while (l1->next && l2) {
            if (l1->next->val > l2->val) {
                swap(l1->next, l2); // or insert l2 between l1 and l1->next. l2 = l2->next
            }
            l1 = l1->next;
        }
        if (l2) {
            l1->next = l2;
        }
        return head;
    }
};
