/**
    328. Odd Even Linked List
Given a singly linked list, group all odd nodes together followed by the even nodes.
Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. 
The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

Algo:
- take 2 pointers po and pe
- and make next pointers: o and e
- while o != null and e != null:
    - p.o->next = o
    - p.o = p.o.->next
    - o = o->next->next
    - p.e.->next = e
    - p.e. = e
    - e = e->next->next
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        auto po = head;
        auto pe = head->next;
        auto o = pe->next;
        auto e = o->next;
        auto second = pe;
        while (true) {
            // odd
            po->next = o;
            po = o;
            if (!e) {
                pe->next = e;
                break;
            }
            o = e->next;
            // even
            pe->next = e;
            pe = e;
            if (!o) {
                po->next = o;
                break;
            }
            e = o->next;
        }
        po->next = second;
        
        return head;
    }
};



