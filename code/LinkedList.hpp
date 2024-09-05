#ifndef H_LINKEDLIST
#define H_LINKEDLIST

#include "User.hpp"

struct Node {
    User data;
    Node* next;

    // in-line constructor
    Node(User val) : data(val), next(nullptr) {} // no code in body needed
};

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        Node* getHead();
        void insert(User);
        void printList();
        std::string toString();
    private:
        Node* head;
};

#endif