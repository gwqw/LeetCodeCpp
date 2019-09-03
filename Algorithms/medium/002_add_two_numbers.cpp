/**
    2. Add Two Numbers
    You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order and each of their nodes contain a single digit. 
    Add the two numbers and return it as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    Example:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
    
    Algo:
    go through list and add two digits to the l1
    if sum > 9: store 1 to the next
    
    stored = 0
    lr = l1
    l1prev = l1
    while l1 or l2:
        l1.val += l2.val + stored
        if l1.val > 9:
            l1.val -= 10
            stored = 1
        else:
            stored = 0
        l1prev = l1
        l1 = l1.next
        l2 = l2.next
    l1 = l1prev
    if l2:
        l1.next = l2
    while l1 and stored:
        l1.val += stored
        if l1.val > 9:
            l1.val -= 10
            stored = 1
        else:
            stored = 0
    return l1
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Solution with O(N) and O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int stored = 0;
        ListNode* lr = l1;
        ListNode* l1prev = l1;
        while (l1 && l2) {
            l1->val += l2->val + stored;
            if (l1->val > 9) {
                l1->val -= 10;
                stored = 1;
            } else {
                stored = 0;
            }
            l1prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        // add l2
        if (l2) {
            l1prev->next = l2;
            l1 = l1prev->next;
        }
        // add stored
        while (l1 && stored) {
            l1->val += stored;
            if (l1->val > 9) {
                l1->val -= 10;
                stored = 1;
            } else {
                stored = 0;
            }
            l1prev = l1;
            l1 = l1->next;
        }
        // add stored to the end
        if (stored) {
            l1prev->next = new ListNode(stored);
        }
        return lr;
    }
};

// Solution with O(N) and O(N) with creating new List
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int stored = 0;
        ListNode* lr = nullptr;
        ListNode* lc = nullptr;
        while (l1 || l2) {
            // calc sum
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            n1 += n2 + stored;
            if (n1 > 9) {
                n1 -= 10;
                stored = 1;
            } else {
                stored = 0;
            }
            // store to lc
            if (lc) {
                lc->next = new ListNode(n1);
                lc = lc->next;
            } else {
                lc = new ListNode(n1);
                lr = lc;
            }
            // inc
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        // add stored to the end
        if (stored) {
            lc->next = new ListNode(stored);
        }
        return lr;
    }
};


