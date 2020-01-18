/**
    160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:

begin to intersect at node c1.

Example 1:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). 
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. 
There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
 
Example 2:
Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). 
From the head of A, it reads as [0,9,1,2,4]. 
From the head of B, it reads as [3,2,4]. 
There are 3 nodes before the intersected node in A; 
There are 1 node before the intersected node in B.
 
Example 3:
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. 
From the head of B, it reads as [1,5]. 
Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.

Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

Algo: simple O(N1ave + N2) + O(N1)
- go through 1-st list and save nodes to set
- go through 2-nd list and check node in set


\
 \
  \
   -----
  /
  
Algo2: use lenght pattern: O(N1+N2) + O(1)
- calc both length's
- if l2 > l1: swap
- shift list1 on l1-l2
- go through lists and find the same node

Algo3: use 2 stacks (like right reverse list): O(N1+N2) + O(N1+N2)

Algo4: "cycle" go through: O(N1+N2) + O(1)
- two pointers: p1 goes through list1, p2 goes through list2 in parallel
- if pointer meet end of list: it starts from the begin of other list
- they at the same point in intersection point
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> dict;
        while (headA) {
            dict.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (dict.count(headB)) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        auto length1 = calcListLength(head1);
        auto length2 = calcListLength(head2);
        if (length2 > length1) {
            swap(head1, head2);
            swap(length1, length2);
        }
        head1 = shiftHead(head1, length1 - length2);
        while(head1 && head2) {
            if (head1 == head2) return head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        return nullptr;
    }
private:
    size_t calcListLength(ListNode* head) {
        size_t length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        return length;
    }
    ListNode* shiftHead(ListNode* head, size_t shift) {
        while (shift-->0) {
            head = head->next;
            if (!head) break;
        }
        return head;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *heada, ListNode *headb) {
        stack<ListNode*> sta, stb;
        while (heada) {
            sta.push(heada);
            heada = heada->next;
        }
        while (headb) {
            stb.push(headb);
            headb = headb->next;
        }
        ListNode* prev = nullptr;
        while (!sta.empty() && !stb.empty()) {
            if (sta.top() != stb.top()) return prev;
            prev = sta.top();
            sta.pop();
            stb.pop();
        }
        return prev;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        if (!h1 || !h2) return nullptr;
        auto p1 = h1;
        auto p2 = h2;
        bool was_here1 = false, was_here2 = false;
        while (p1 != p2) {
            p1 = next(p1, h2, was_here1);
            p2 = next(p2, h1, was_here2);
        }
        return p1;
    }
private:
    ListNode* next(ListNode* p, ListNode* h, bool& was_here) {
        if (p->next) {
            return p->next;
        } else if (!was_here) {
            was_here = true;
            return h;            
        } else {
            return nullptr;
        }
    }
};

