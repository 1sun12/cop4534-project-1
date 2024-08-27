#include "LinkedList.hpp"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    // Clean up memory
    Node* current = head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void LinkedList::insert(User user) {
    Node* newItem = new Node(user);

    // if head is null, make this the new head
    // else, set next-ptr of most recent addition to this item; place new item at the tail
    if (head == nullptr) {
        head = newItem;
    } else {
        // I just wanna note these next two lines as important
        // notice how temp becomes a different item after each while loop, kind of like recursion
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // now we're at the tail-end of the linked-list and can add newNode
        temp->next = newItem;
    }
}

void LinkedList::printList() {
    Node* nodeToPrint = head;
    while (nodeToPrint->next != nullptr) {
        nodeToPrint->data.print();
        nodeToPrint = nodeToPrint->next;
    }

    // print last node, since while loop stops
    nodeToPrint->data.print();
}