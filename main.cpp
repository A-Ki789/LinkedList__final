#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main(){
    LinkedList newList;
    newList.appendList(0);
    newList.appendList(1);
    newList.appendList(2);
    newList.appendList(3);
    newList.reverse();
    newList.printList();
    return 0;
}