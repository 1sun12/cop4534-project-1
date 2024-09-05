/***************************************************************
  Student Name:       Regan O'Donnell
  File Name:          LinkedList.cpp
  Assignment number:  Project 1

    Object file for linked-list; some operations are inserting, searching, and some print functions
***************************************************************/

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

Node* LinkedList::getHead() {
    return head;
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
        std::cout << " --> ";
        nodeToPrint = nodeToPrint->next;
    }

    // print last node, since while loop stops
    nodeToPrint->data.print();
}

std::string LinkedList::toString() {
    std::string tooString = "";
    Node* nodeToPrint = head;

    if (nodeToPrint == nullptr) {
        return "";
    }

    while (nodeToPrint->next != nullptr) {
        tooString += nodeToPrint->data.toString() + " --> ";
        nodeToPrint = nodeToPrint->next;
    }

    // print last node, since while loop stops
    if (nodeToPrint != nullptr) {
        tooString += nodeToPrint->data.toString();
    }

    return tooString;
}