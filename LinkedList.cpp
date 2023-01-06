#include<iostream>
using namespace std;

struct Node* head = NULL;
struct Node* tail = NULL;

int llLength = 0;

struct Node {
    int data;
    struct Node* next;
};

void append(int ele) {
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

    llLength++;
}

void push(int ele) {
    Node* new_node = new Node;
    new_node->data = ele;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }

    llLength++;
}

void insert(int ele, int pos) {
    pos-=2;

    Node* ptr = head;
    while (pos--) {
        ptr = ptr->next;
    }
    
    Node* new_node = new Node;
    new_node->data = ele;
    new_node->next = ptr->next;
    ptr->next = new_node;

    llLength++;
}

void truncate() {
    if (head == tail) {
        head = tail = NULL;

        llLength--;

        return;
    }

    int localLength = llLength - 2;

    Node* ptr = head;
    while (localLength--) {
        ptr = ptr->next;
    }

    ptr->next = NULL;

    llLength--;
}

void pop() {
    if (head == tail) {
        head = tail = NULL;

        llLength--;

        return;
    }

    Node* ptr = head->next;
    head = ptr;

    llLength--;
}

void remove(int pos) {
    if (head == tail) {
        head = tail = NULL;

        llLength--;

        return;
    }

    pos-=2;

    Node* ptr1 = head;
    while (pos--) {
        ptr1 = ptr1->next;
    }

    Node* ptr2 = ptr1->next;
    Node* ptr3 = ptr2->next;

    ptr1->next = ptr3;

    llLength--;
}

void displayLL() {
    if (llLength == 0) {
        cout << "\nNo elements in the Linked List to diaplay!" << endl;
        return;
    }

    Node* ptr = head;

    cout << "\nThe elements in Linked List are: ";
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}
 
int main() {

    int i = 0;
    int llFlag = 0;
    while (i != 10) {
        cout << "\nWhat operation do you want to perform?\n1. Create a linked list\n2. Insert element (at end)\n3. Insert element (at beginning)\n4. Insert element (in between)\n5. Delete element (from end)\n6. Delete element (from beginning)\n7. Delete element (from between)\n8. Search an element\n9. Display linked list\n10. Exit\nChoice: ";
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
                displayLL();
                llFlag = 1;
                
                continue;
            
            case 2:
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                append(num);
                displayLL();
                continue;

            case 3:
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                push(num);
                displayLL();
                continue;

            case 4:
                int ele, pos;
                cout << "\nEnter the element and position seperated by space: ";
                cin >> ele >> pos;

                while (pos > llLength) {
                    cout << "\nPosition greater than size of Linked List! Cannot enter element";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                }

                while (pos <= 0) {
                    cout << "\nPosition cannot be less than 1";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                }

                insert(ele, pos);
                displayLL();
                continue;
            
            case 5:
                truncate();
                displayLL();
                continue;
            
            case 6:
                pop();
                displayLL();
                continue;

            case 7:
                cout << "\nEnter the element index's to be deleted: ";
                cin >> pos;

                while (pos > llLength) {
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
                displayLL();
                continue;
            
            case 9:
                if (llFlag == 0) {
                    cout << "\nNo elements in Linked List to display!" << endl;
                } else {
                    displayLL();
                }
                continue;
            
            case 10:
                cout << "\nExited successfully";
                break;
        }

    }
    
    return 0;
}