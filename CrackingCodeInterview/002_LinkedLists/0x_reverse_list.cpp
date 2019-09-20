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

Node* reverse_list(Node* head) {
    if (!head) return nullptr;
    Node* new_head = nullptr;
    Node* p = head->next;
    while (head) {
        head->next = new_head;
        new_head = head;
        head = p;
        if (p)
            p = p->next;
    }
    return new_head;
}
