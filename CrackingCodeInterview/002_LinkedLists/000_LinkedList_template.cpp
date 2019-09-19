/**
    Linked list template
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