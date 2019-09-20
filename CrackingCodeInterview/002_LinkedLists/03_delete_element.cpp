/**
    Implement an algorithm to delete a node in the middle of a single linked list, given
    only access to that node.
    EXAMPLE
    Input: the node ‘c’ from the linked list a->b->c->d->e
    Result: nothing is returned, but the new linked list looks like a->b->d->e
    
    Algo:
    Copy rest part to this node
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

void delete_element(Node* p) {
    if (p->next) {
        *p = *(p->next);
    }
}

