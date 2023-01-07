#include<iostream>
using namespace std;

struct Node* head = NULL;

int cllLength = 0;

struct Node {
    int data;
    struct Node* next;
};

void append(int ele) {
    Node* new_node = new Node;
    new_node->data = ele;

    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        Node* ptr = head;

        while (ptr->next != head) {
            ptr = ptr->next;
        }

        ptr->next = new_node;
        new_node->next = head;
    }
}

void displayCLL() {
    Node* ptr = head;

    if (head == NULL) {
        cout << "\nNo elements to print" << endl;
        return;
    }

    cout << "\nThe elements of Circular Linked List are: HEAD ->";
    while (ptr->next != head) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << ptr->data << " -> HEAD";
    cout << endl;
}
 
int main() {
    int i = 0;

    while (i != 2) {
        cout << "\nWhat operation do you want to perform?\n1. Create a circular linked list\n2. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int n;
                cout << "\nHow many elements do you want to add? ";
                cin >> n;

                int num;
                for (int i = 0; i < n; i++) {
                    cout << "Enter element " << i << ": ";
                    cin >> num;
                    append(num);
                }

                displayCLL();
                continue;

            case 2:
                cout << "\nExited successfully";
                break;
        }
    }
    
    return 0;
}