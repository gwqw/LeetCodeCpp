/**
    148. Sort List
Given the head of a linked list, return the list after sorting it in ascending order.
Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []

Constraints:
    The number of nodes in the list is in the range [0, 5 * 104].
    -10^5 <= Node.val <= 10^5
	
Algo: merge sort
- split list on 2: head1->one, head2->two
- sort list1
- sort list2
- merge 2 sorted lists

Algo2: stable merge sort
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
    ListNode* sortList(ListNode* head) {
		if (!head) return nullptr;
		size_t len = calc_len(head);
		if (len == 1) return head;
		auto head2 = split(head, len);
		head = sortList(head);
		head2 = sortList(head2);
		return merge2sortedLists(head, head2);
    }
private:
	size_t calc_len(ListNode* head) {
		size_t len = 0;
		while (head) {
			++len;
			head = head->next;
		}
		return len;
	}
	
	ListNode* split(ListNode* head, size_t len) {
		len /= 2;
		for (size_t i = 0; i+1 < len; ++i) head = head->next;
		auto head2 = head->next;
		head->next = nullptr;
		return head2;
	}
	
	ListNode* merge2sortedLists(ListNode* head1, ListNode* head2) {
		if (head1->val > head2->val) swap(head1, head2);
		auto head = head1;
		while (head1->next) { // && head2
			if (head1->next->val > head2->val) {
				swap(head1->next, head2);
			}
			head1 = head1->next;
		}
		if (head2) {
			head1->next = head2;
		}
		return head;
	}
};

// stable sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
		if (!head) return nullptr;
		size_t len = calc_len(head);
		if (len == 1) return head;
		auto head2 = split(head, len);
		head = sortList(head);
		head2 = sortList(head2);
		return merge2sortedLists(head, head2);
    }
private:
	size_t calc_len(ListNode* head) {
		size_t len = 0;
		while (head) {
			++len;
			head = head->next;
		}
		return len;
	}
	
	ListNode* split(ListNode* head, size_t len) {
		len /= 2;
		for (size_t i = 0; i+1 < len; ++i) head = head->next;
		auto head2 = head->next;
		head->next = nullptr;
		return head2;
	}
	
	ListNode* merge2sortedLists(ListNode* head1, ListNode* head2) {
		if (head1->val > head2->val) {
		    popNodeFrom2(head1, head2);
		}
		auto head = head1;
		while (head1->next && head2) {
			if (head1->next->val > head2->val) {
    			popNodeFrom2(head1->next, head2);
			}
			head1 = head1->next;
		}
		if (head2) {
			head1->next = head2;
		}
		return head;
	}
	
	void popNodeFrom2(ListNode* &n1, ListNode* &n2) {
	    auto tmp = n2;
	    n2 = n2->next;
	    tmp->next = n1;
	    n1 = tmp;
	}
};

/*
h1->1->n
*/
