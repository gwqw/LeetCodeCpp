/**
    445. Add Two Numbers II
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

Follow up: Could you solve it without reversing the input lists?

Algo1: calc length
l1 = calc_length(h1)
l2 = calc_length(h2)
let l1 > l2:
carry = rec(h1, h2, l1 - l2)
if carry:
	new_head = new Node
	new_head->val = carry
rec add(n1, n2, shift):
	carry = 0
	if shift:
		carry = rec(n1->next, n2, shift-1)
	else:
		carry = n1->next ? rec(n1->next, n2->next) : 0
	n1->val += carry
	if shift == 0:
		n1->val += n2->val
	carry = n1->val / 10
	n1->val %= 10
	return carry

Algo2: reverse 2 lists, add, reverse result

Algo3: add wo carry to list front, take account carry, reverse output
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
    ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        auto l1 = calcLength(h1);
		auto l2 = calcLength(h2);
		if (l1 < l2) {
			swap(h1, h2);
			swap(l1, l2);
		}
		auto carry = recSum(h1, h2, l1 - l2);
		if (carry != 0) {
			return new ListNode(carry, h1);
		}
		return h1;
    }
	
private:
	int recSum(ListNode* n1, ListNode* n2, size_t shift) {
		int carry = 0;
		if (shift > 0) {
			carry = recSum(n1->next, n2, shift-1);
		} else if (n1->next) {
			carry = recSum(n1->next, n2->next, 0);
		}
		n1->val += carry;
		if (shift == 0) {
			n1->val += n2->val;
		}
		carry = n1->val / 10;
		n1->val %= 10;
		return carry;
	}

	size_t calcLength(ListNode* n1) {
		size_t len = 0;
		while (n1) {
			++len;
			n1 = n1->next;
		}
		return len;
	}
};

1 2 
  ^  
  0
  ^
s = 1

