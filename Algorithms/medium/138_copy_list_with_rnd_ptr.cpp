/**
    138. Copy List with Random Pointer
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]

Example 4:
Input: head = []
Output: []
Explanation: The given linked list is empty (null pointer), so return null.

Constraints:

0 <= n <= 1000
-10000 <= Node.val <= 10000
Node.random is null or is pointing to some node in the linked list.

1->2->3->4->nullptr
|_____^

Algo: O(N), O(N) mem
dict[node]->node
for node in list:
	create node2 = node
	if node->rand and node->rand in dict:
		node2->rand = dict[node->rand]
	dict[node] = node2
	if h2:
		h2->next = node2
		h2 = h2->next
	else:
		h2 = node2
for node in list2:
	if node->rand and node->rand in dict:
		node->rand = dict[node->rand]
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
		unordered_map<Node*, Node*> dict;
		Node* head2 = nullptr;
		Node* h2 = nullptr;
		while (head) {
			Node* node = new Node(head->val);
			node->random = head->random;
			dict[head] = node;
			if (h2) {
				h2->next = node;
				h2 = h2->next;
			} else {
				h2 = node;
				head2 = node;
			}
			head = head->next;
		}
		h2 = head2;
		while (h2) {
			if (h2->random) {
				h2->random = dict[h2->random];
			}
			h2 = h2->next;
		}
		return head2;
    }
};

/*
1->2->null
*/
