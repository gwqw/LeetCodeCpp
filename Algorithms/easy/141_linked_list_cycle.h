/**
    141. Linked List Cycle
Given a linked list, determine if it has a cycle in it.
To represent a cycle in the given linked list, we use an integer pos 
which represents the position (0-indexed) in the linked list where tail connects to. 
If pos is -1, then there is no cycle in the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

Algo1: 2 pointers O(N) + O(1)
- use 2 iterators: one goes with double speed
- if they found nullptr -- no cycle
- if they meet -- cycle

Algo2: use cache O(N) + O(N)
- set(nodes) as cache
- check in cache

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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* ds = head;
        while (true) {
            if (!ds->next || !ds->next->next) {
                return false;
            }
            ds = ds->next->next;
            head = head->next;
            if (ds == head) {
                return true;
            }
        }
        assert(false);
        return false;
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* ds = head;
        while (ds->next && ds->next->next) {
            ds = ds->next->next;
            head = head->next;
            if (ds == head) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        unordered_set<ListNode*> cache;
        while (head) {
            if (cache.count(head)) return true;
            cache.insert(head);
            head = head->next;
        }
        return false;
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        unordered_set<ListNode*> cache;
        while (head) {
            auto [_,res] = cache.insert(head);
            if (!res) return true;
            head = head->next;
        }
        return false;
    }
};
