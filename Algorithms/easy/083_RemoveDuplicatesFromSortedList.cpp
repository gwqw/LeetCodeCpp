/**
83. Remove Duplicates from Sorted List (Easy)
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3

Algo:
while ptr != NULL:
  if ptr->next and ptr->val == ptr->next->val:
    d_ptr = ptr->next
    ptr->next = d_ptr->next
    delete d_ptr
  else:
    ptr = ptr->next
    
O(N), O(1)
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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* ptr = head;
      while (ptr != nullptr) {
        if (ptr->next && ptr->val == ptr->next->val) {
          ListNode* d_ptr = ptr->next;
          ptr->next = d_ptr->next;
          delete d_ptr;
        }
        else {
          ptr = ptr->next;
        }
      }
      return head;
    }
};