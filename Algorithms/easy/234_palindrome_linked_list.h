/**
    234. Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?

Algo: naive O(N) + O(N)
- copy to vector and check if it's palindrome

Algo: 
- calc size
- make reverse list from second part
- cmp lists

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
    bool isPalindrome(ListNode* head) {
        vector<int> lst;
        while (head) {
            lst.push_back(head->val);
            head = head->next;
        }
        for (int i = 0; i < lst.size() / 2; ++i) {
            if (lst[i] != lst[lst.size() - 1 - i]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        auto sze = getSize(head);
        auto new_head = getHalfPtr(head, sze);
        new_head = reverse(new_head);
        return cmp_lists(head, new_head);
    }
    
private:
    static size_t getListSize(TreeNode* head) {
        size_t sze = 0;
        while (head) {
            ++sze;
            head = head->next;
        }
        return sze;
    }
    
    TreeNode* getHalfPtr(TreeNode* head, size_t sze) {
        while (sze != 0) {
            head = head->next;
            --sze;
        }
        return head;
    }
    
    TreeNode* reverse(TreeNode* head) {
        if (!head) return nullptr;
        TreeNode* new_head = nullptr;
        TreeNode* next = head;
        while (head->next) {
            next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
        }
        if (head) {
            head->next = new_head;
        }
        return head;
    }
    
    bool cmp_lists(TreeNode* head, TreeNode* new_head) {
        while (head) {
            if (head->val != new_head->val) return false;
            head = nead->next;
            new_head = new_head->next;
        }
        return true;
    }
    
    /*
        1 -> 2 -> 3 -> nullptr
        h    n
    
    */
    
};