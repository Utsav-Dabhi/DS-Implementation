#include<iostream>
using namespace std;

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

void append(int ele) {
    Node* new_node = new Node;
    new_node->prev = NULL;
    new_node->next = NULL;

    new_node->data = ele;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void displayDLL() {
    if (head == NULL) {
        cout << "\nNo elements to print!" << endl;
        return;
    }

    Node* ptr = head;
    cout << "\nThe elements of Doubly Linked List are: NULL <- ";
    while (ptr->next != NULL) {
        cout << ptr->data << " <-> ";
        ptr = ptr->next;
    }
    cout << ptr->data << " -> NULL" << endl;
}
 
int main() {
    int i = 0;
    while (i != 11) {
        cout << "\nWhat operation do you want to perform?\n1. Create a doubly linked list\n2. Insert element (at end)\n3. Insert element (at beginning)\n4. Insert element (in between)\n5. Delete element (from end)\n6. Delete element (from beginning)\n7. Delete element (from between)\n8. Search an element\n9. Replace element\n10. Display linked list\n11. Exit\nChoice: ";
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

                displayDLL();

                continue;

            case 2:
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                append(num);
                displayDLL();

                continue;

            case 11:
                cout << "\nExited successfully";
                break;
        }
    }
    
    return 0;
}