/**
    142. Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

Constraints:

The number of the nodes in the list is in the range [0, 104].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list.

Follow up: Can you solve it using O(1) (i.e. constant) memory?

Algo: tortoise and hare: O(N), O(1) mem
2 pointers: t-pointer -- 1 step, h-pointer -- 2 steps
after meet: h-pointer moves with its normal speed
t-pointer with 1-step speed from the begining

Algo: naive use set: O(N), O(N) mem

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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
		auto t = head->next;
		auto h = head->next->next;
		while (h && t != h) {
			t = t->next;
			h = h->next;
			if (!h) break;
			h = h->next;
		}
		if (!h) return nullptr;
		h = head;
		while (h != t) {
			t = t->next;
			h = h->next;
		}
		return h;
    }
};
