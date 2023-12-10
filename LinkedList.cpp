#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;
LinkedList::LinkedList(int value) {
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

void LinkedList::printList() {
    Node* temp = head;
    while(temp){
        cout<<temp->value<<endl;
        temp = temp->next;
    }

}

LinkedList::~LinkedList() {
    Node* temp = head;
    while(head){
        head = head->next;
        delete temp;
        temp = head;
    }
    //head, tail, length gets deleted by default destructor

}

void LinkedList::appendList(int value) {
    Node* newNode = new Node(value);

    if (length == 0){
        tail = newNode;
        head = newNode;
    }

    else{
        tail->next = newNode;
        tail = newNode;

    }
    length += 1;

}

void LinkedList::deleteLast() {
    Node* temp = head;

    if(length==0)return;
    if(length==1) {
        head = nullptr;
        tail = nullptr;
    }
    else{
    Node* pre = head;
    while(temp->next){
        pre = temp;
        temp = temp->next;
    }
    tail = pre;
    tail->next = nullptr;
    }

    length--;
    delete temp;
}

void LinkedList::getLength() {
    cout<<"Length: "<<this->length<<endl;

}

void LinkedList::prepend(int value) {
    auto* newNode = new Node(value);

    if(length==0){
        head = newNode;
        tail = newNode;
    }

    else{
        newNode->next = head;
        head = newNode;
    }

    length++;

}

void LinkedList::deleteFirst() {
    Node* temp = head;

    if(length==0)return;
    if(length==1){
        head = nullptr;
        tail = nullptr;
    }else{
    head = head->next;
    }
    length--;
    delete temp;

}

Node* LinkedList::get(int index) {
    if(index<0 || index>=length){
        return nullptr;
    }

    Node* temp = head;
    for (int i = 0;i<index;i++)
        temp = temp->next;

    return temp;
}

bool LinkedList::set(int index, int value) {
    auto temp = get(index);
    if(temp){
        temp->value = value;
        return true;
    }
    return false;
    delete temp;
}

bool LinkedList::insert(int index, int value) {
    if(index<0 ||index>length) return false;

    if(index==0){
        prepend(value);
        return true;
    }
    if(index == length){
        appendList(value);
        return true;
    }
    Node* newNode = new Node(value);
    Node* temp = get(index-1);
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
    return true;

}

void LinkedList::deleteNode(int index) {
    if(index<0 || index>=length){return;}
    if(index==0){return deleteFirst();}
    if(index==length-1){return deleteLast();}


    Node *temp = get(index);
    Node *pre = get(index - 1);
    pre->next = temp->next;
    delete temp;
    length--;
}

void LinkedList::reverse() {
    Node* temp;
    temp = head;
    head = tail;
    tail = temp;

    Node* before = nullptr;
    Node* after = temp->next;

    for(int i = 0;i<length;i++){
        after = temp->next;
        temp->next = before;
        before= temp;
        temp = after;

    }
}




