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


