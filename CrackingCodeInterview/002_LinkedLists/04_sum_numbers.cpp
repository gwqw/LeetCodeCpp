/**
You have two numbers represented by a linked list, where each node contains a sin-
gle digit. The digits are stored in reverse order, such that the 1’s digit is at the head of
the list. Write a function that adds the two numbers and returns the sum as a linked
list.
EXAMPLE
Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
Output: 8 -> 0 -> 8

Algo:
- bool flag overhead
- go through list:
    - if l1: x = l1->value, the same for y
    - calc sum 
    - if flag: add flag
    - if sum > 10: flag = true sum -= 10
    - else: flag = false
    - increas l1 and l2
*/

struct Node {
    int value = 0;
    Node* next = nullptr;
};

std::ostream& operator<<(std::ostream& out, Node* n) {
    while (n) {
        out << n->value << " -> ";
        n = n->next;
    }
    out << "NULL";
    return out;
}

Node* sum_lists(Node* l1, Node* l2) {
    int x = 0, y = 0;
    bool over = false;
    Node* psum = nullptr;
    Node* res = nullptr;
    while (l1 || l2) {
        x = l1 ? l1->value : 0;
        y = l2 ? l2->value : 0;
        x += y;
        if (over) {
            ++x;
        }
        if (x >= 10) {
            x -= 10;
            over = true;
        } else {
            over = false;
        }
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
        if (res) {
            res->next = new Node{x};
            res = res->next;
        } else {
            res = new Node{x};
            psum = res;
        }   
    }
    if (over) {
      res->next = new Node{1};
    }
    return psum;
}

