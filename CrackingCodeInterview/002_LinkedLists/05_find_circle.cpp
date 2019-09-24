/**
Given a circular linked list, implement an algorithm which returns node at the begin-
ning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an
earlier node, so as to make a loop in the linked list.
EXAMPLE
input: A -> B -> C -> D -> E -> C [the same C as earlier]
output: C

Algo:
- go through list and cache nodes, if node is already in list -> return it
O(N) + O(N)

Algo from book:
We have 2 pointers n1 and n2, they points to head
- go through list (n1 +1, n2 +2 speed) until met: met point is k steps before loop start
- n1 points to head: go through list with the same speed: met point will be loop start
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

Node* find_circle(Node* head) {
    if (!head) return nullptr;
    unordered_set<Node*> cache;
    while (head) {
        if (cache.count(head)) return head;
        cache.insert(head);
        head = head->next;
    }
    return head;
}

Node* find_circle2(Node* head) {
    if (!head) return nullptr;
    Node* n1 = head;
    Node* n2 = head;
    // first met point
    while (true) {
        if (!n1->next) return nullptr;
        if (!n2->next || !n2->next->next) return nullptr;
        n1 = n1->next;
        n2 = n2->next->next;
        if (n1 == n2) break;
    }
    // start of za loop   
    n1 = head;
    while (n1 != n2) {
        n1 = n1->next;
        n2 = n2->next;
    }
    return n1;
}
