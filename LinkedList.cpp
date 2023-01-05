#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void addElement(int ele) {
    Node* new_node = new Node;
    new_node->data = ele;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = tail->next;
    }
}

void displayLL() {
    Node* ptr = head;

    cout << "\nThe elements in Linked List are: ";
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
}
 
int main() {

    int i = 0;
    while (i != 8) {
        cout << "\nWhat operation do you want to perform?\n1. Create a linked list\n2. Insert element (at end)\n3. Delete element (from end)\n4. Insert element (in between)\n5. Delete element (from between)\n6. Search an element\n7. Display linked list\n8. Exit\nChoice: ";
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
                    addElement(num);
                }
                displayLL();
                
                continue;
            
            case 8:
                cout << "\nExited successfully";
                break;
        }

    }
    
    return 0;
}