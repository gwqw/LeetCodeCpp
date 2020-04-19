/**
    19. Remove Nth Node From End of List
Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?

Algo1: calc length O(N) + O(1)
- go through list and calc length l
- if l == n: 
    - remove head;
- else:
    - find n-l-1 element
    - remove next

Algo2: sliding window
- go through list n step:
- if first->next = nullptr;
    - remove head
- else:
    - make one step
    - snd ptr = head
    while first != nullptr:
        ++first
        ++second
    remove second->next
    
Algo3: use array to save ptrs
- go through list:
    - push_back to array ListNode*
- if l == n:
    - remove head
- else:
    - find n-l-1
    - remove its next

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        auto l = calcLength(head);
        if (l == n) {
            auto tmp = head;
            head = head->next;
            delete(tmp);
            return head;
        } else {
            auto node = step_n(head, l-n-1);
            auto tmp = node->next;
            node->next = tmp->next;
            delete(tmp);
        }
        return head;
    }
    
private:
    static int calcLength(ListNode* head) {
        int length = 0;
        while (head) {
            head = head->next;
            ++length;
        }
        return length;
    }
    
    static ListNode* step_n(ListNode* node, int steps) {
        while (steps > 0) {
            node = node->next;
            --steps;
        }
        return node;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        auto first = step_n(head, n);
        if (first == nullptr) {
            auto tmp = head;
            head = head->next;
            delete(tmp);
            return head->next;
        } else {
            first = first->next;
            auto second = head;
            while (first) {
                first = first->next;
                second = second->next;
            }
            auto tmp = second->next;
            second->next = tmp->next;
            delete(tmp);
        }
        return head;
    }
    
private:
    static ListNode* step_n(ListNode* node, int steps) {
        while (steps > 0) {
            assert(node);
            node = node->next;
            --steps;
        }
        return node;
    }
};

/*
Algo3: use array to save ptrs
- go through list:
    - push_back to array ListNode*
- if l == n:
    - remove head
- else:
    - find n-l-1
    - remove its next
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;
        vector<ListNode*> arr;
        auto node = head;
        while (node) {
            arr.push_back(node);
            node = node->next;
        }

        if (arr.size() == n) {
            auto tmp = head;
            head = head->next;
            delete(tmp);
            return head;
        } else {
            auto node = arr[arr.size()-n-1];
            auto tmp = node->next;
            node->next = tmp->next;
            delete(tmp);
        }
        return head;
    }
};
