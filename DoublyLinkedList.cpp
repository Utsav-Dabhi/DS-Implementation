#include<iostream>
using namespace std;

struct Node* head = NULL;
struct Node* tail = NULL;

int dllLength = 0;

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
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }

    dllLength++;
}

void push(int ele) {
    Node* new_node = new Node;
    new_node->prev = NULL;
    new_node->next = NULL;

    new_node->data = ele;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }

    dllLength++;
}

void insert(int ele, int pos) {
    Node* new_node = new Node;
    new_node->prev = NULL;
    new_node->next = NULL;

    new_node->data = ele;

    pos -= 2;
    Node* ptr = head;
    while (pos--) {
        ptr = ptr->next;
    }

    new_node->next = ptr->next;
    new_node->prev = ptr;
    ptr->next = new_node;
}

void truncate() {
    if (dllLength == 0) {
        cout << "\nNo elements to delete" << endl;
        return;
    }

    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    dllLength--;
}

void pop() {
    if (dllLength == 0) {
        cout << "\nNo elements to delete" << endl;
        return;
    }

    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    dllLength--;
}

void remove(int pos) {
    if (dllLength == 0) {
        cout << "\nNo elements to delete" << endl;
        return;
    }

    if (head == tail) {
        head = tail = NULL;
    } else {
        pos -= 2;

        Node* ptr = head;
        while (pos--) {
            ptr = ptr->next;
        }

        Node* tmp = ptr->next->next;
        ptr->next = tmp;
        tmp->prev = ptr;
    }

    dllLength--;
}

void displayDLL() {
    if (head == NULL) {
        cout << "\nNo elements to print!" << endl;
        return;
    }

    Node* ptr = head;
    cout << "\nThe elements of Doubly Linked List are: NULL <- ";
    while (ptr->next != NULL) {
        // cout << "Prev: " << ptr->prev << " Data: " << ptr->data << " Next: " << ptr->next << endl;
        cout << ptr->data << " <-> ";
        ptr = ptr->next;
    }
    cout << ptr->data << " -> NULL" << endl;
        
    // cout << "Prev: " << ptr->prev << " Data: " << ptr->data << " Next: " << ptr->next << endl;
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

            case 3:
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                push(num);
                displayDLL();

                continue;

            case 4:
                int pos;
                cout << "\nEnter the element and position seperated by space: ";
                cin >> num >> pos;

                while (pos > dllLength) {
                    cout << "\nPosition greater than size of Linked List! Cannot enter element";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                }

                while (pos <= 0) {
                    cout << "\nPosition cannot be less than 1";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                }

                insert(num, pos);
                displayDLL();

                continue;
            
            case 5:
                truncate();
                displayDLL();
                continue;

            case 6:
                pop();
                displayDLL();
                continue;

            case 7:
                cout << "\nEnter the element index's to be deleted: ";
                cin >> pos;

                while (pos > dllLength) {
                    cout << "\nPosition greater than size of Linked List! Cannot enter element";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                }

                while (pos <= 0) {
                    cout << "\nPosition cannot be less than 1";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                }

                remove(pos);
                displayDLL();

                continue;

            case 11:
                cout << "\nExited successfully";
                break;
        }
    }
    
    return 0;
}