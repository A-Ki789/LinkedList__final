

#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H

#include "Node.h"

class LinkedList{

private:
    int length = 0;
    Node* head;
    Node* tail;
public:
    LinkedList() =default;
    explicit LinkedList(int value);
    void printList();
    ~LinkedList();
    void appendList(int value);
    void deleteLast();
    void getLength();
    void prepend(int value);
    void deleteFirst();
    Node* get(int index);
    bool set(int index,int value);
    bool insert(int index, int value);
    void deleteNode(int index);
    void reverse();
};
#endif //LINKED_LIST_LINKEDLIST_H
