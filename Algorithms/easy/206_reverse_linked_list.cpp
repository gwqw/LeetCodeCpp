/**
    206. Reverse Linked List
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively.
Could you implement both?

Algo: itterative: O(N) + O(1)
- use add pointer for reverse
- good idea to think about stack

Algo: recursive: O(N) + O(N)
- recursive treat head->next and obtain new head and last element
- add head to last element
- return new head and head(new last element)

we can use head as pointer to tail, and we don't need to return tail element.
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
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = nullptr;
        while (head) {
            auto n = head->next;
            head->next = new_head;
            new_head = head;
            head = n;
        }
        return new_head;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        auto [rev_list, _] = reverseListRec(head);
        return rev_list;
    }
    
private:
    pair<ListNode*, ListNode*> reverseListRec(ListNode* head) {
        if (!head->next) return {head, head};
        auto [rev_list, rev_last] = reverseListRec(head->next);
        rev_last->next = head;
        head->next = nullptr;
        return {rev_list, head};
    }
};

/*
3->2->1->null
   ^  ^
0<-3<-2<-1
   ^  ^  ^
*/


