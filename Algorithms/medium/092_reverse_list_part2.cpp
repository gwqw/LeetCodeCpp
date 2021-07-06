/**
    92. Reverse Linked List II
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]

Constraints:
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

Follow up: Could you do it in one pass?

Algo: reverse list
if node->val == left:
	reverse 2 right:
		new_head = nullptr
		while (node && node->val != right) {
			auto tmp = node->next;
			node = node->next
			tmp->next = new_head
			new_head = tmp
		}
		return new_head
else:
	while node->next && node->next->val != right:
		node = node->next
	reverse 2 right
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (!head) return head;
        int cnt = right - left + 1;
        int shift = left-1;
        
        if (shift == 0) {
            return reverseN(head, cnt);
        }
		
		// search left
		auto node = shiftLeft(head, shift-1);
		
		// reverse to right
		node->next = reverseN(node->next, cnt);
		return head;
    }
	
private:
    ListNode* shiftLeft(ListNode* head, int cnt) {
        while (head && cnt > 0) {
            head = head->next;
            --cnt;
        }
        return head;
    }

	ListNode* reverseN(ListNode* head, int cnt) {
		ListNode* new_head = nullptr;
		ListNode* last_node = nullptr;
		while (head && cnt > 0) {
			auto tmp = head;
			head = head->next;
			tmp->next = new_head;
			new_head = tmp;
			if (!last_node) last_node = new_head;
			--cnt;
		}
		if (last_node) last_node->next = head;
		return new_head;
	}
};

