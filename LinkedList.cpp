#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void addElement(Node* n, int ele) {
    n->data = ele;
    n->next = NULL;
}
 
int main() {
    Node head;

    addElement(&head, 5);

    cout << head.data;
    
    return 0;
}