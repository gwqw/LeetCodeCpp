/**
    203. Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.
Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;
        TreeNode* new_head = head;
        // remove head
        while (head && head->value == val) {
            TreeNode* t = head;
            head = head->next;
            delete t;
        }
    }
private:
    removeElement(TreeNode* prev, TreeNode* del) {
        prev->next = del->next;
        delete(del);
    }
};
