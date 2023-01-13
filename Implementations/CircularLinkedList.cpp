#include<iostream>
using namespace std;

struct Node* head = NULL;
struct Node* tail = NULL;

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

        tail = new_node;
    } else {
        new_node->next = tail->next;
        tail->next = new_node;
        tail = new_node;
    }

    cllLength++;
}

void push(int ele) {
    Node* new_node = new Node;
    new_node->data = ele;

    if (head == NULL) {
        head = new_node;
        new_node->next = head;

        tail = new_node;
    } else {
        new_node->next = tail->next;
        tail->next = new_node;

        head = new_node;
    }

    cllLength++;
}

void insert(int ele, int pos) {
    pos -= 2;

    Node* ptr = head;
    while (pos--) {
        ptr = ptr->next;
    }

    Node* new_node = new Node;
    new_node->data = ele;
    new_node->next = ptr->next;
    ptr->next = new_node;

    cllLength++;
}

void truncate() {
    if (head == NULL) {
        cout << "\nNo elements to delete!" << endl;
        return;
    }

    if (head == tail) {
        head = tail = NULL;

        cllLength--;
    } else {
        int localLength = cllLength - 2;

        Node* ptr = head;
        while (localLength--) {
            ptr = ptr->next;
        }

        ptr->next = head;
        tail = ptr;

        cllLength--;
    }

    cout << "\nElement deleted successfully!";
}

void pop() {
    if (head == NULL) {
        cout << "\nNo elements to delete!" << endl;
        return;
    }

    if (head == tail) {
        head = tail = NULL;

        cllLength--;
    } else {
        Node* ptr = head->next;
        head = ptr;

        tail->next = ptr;

        cllLength--;
    }

    cout << "\nElement deleted successfully!";
}

void remove(int pos) {
    if (head == NULL) {
        cout << "\nNo elements to delete!" << endl;
        return;
    }

    if (head == tail) {
        head = tail = NULL;

        cllLength--;
    } else {
        pos -= 2;

        Node* ptr = head;
        while (pos--) {
            ptr = ptr->next;
        }

        ptr->next = ptr->next->next;

        cllLength--;
    }

    cout << "\nElement deleted successfully!";
}

void search(int ele) {
    if (cllLength == 0) {
        cout << "\nNo elements to search!" << endl;
        return;
    }

    int pos = 1;

    Node* ptr = head;
    while (ptr != tail) {
        if (ptr->data == ele) {
            cout << "\nElement is found at position: " << pos << endl;
            return;
        }

        ptr = ptr->next;
        pos++;
    }

    if (ptr->data == ele) {
        cout << "\nElement is found at position: " << pos << endl;
        return;
    }

    cout << "\nNo element found!" << endl;
}

void replace(int ele, int pos) {
    if (cllLength == 0) {
        cout << "\nNo elements to replace!" << endl;
        return;
    }

    pos -= 1;

    Node* ptr = head;
    while (pos--) {
        ptr = ptr->next;
    }

    ptr->data = ele;
}

void displayCLL() {
    if (head == NULL) {
        cout << "\nNo elements to print!" << endl;
        return;
    }

    Node* ptr = head;
    cout << "\nThe elements of Circular Linked List are: HEAD -> ";
    while (ptr != tail) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    cout << ptr->data << " -> HEAD";
    cout << endl;
}
 
int main() {
    int i = 0;
    while (i != 11) {
        cout << "\nWhat operation do you want to perform?\n1. Create a circular linked list\n2. Insert element (at end)\n3. Insert element (in beginning)\n4. Insert element (in between)\n5. Delete element (from end)\n6. Delete element (from beginning)\n7. Delete element (from between)\n8. Search an element\n9. Replace element\n10. Display linked list\n11. Exit\nChoice: ";
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
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                append(num);
                displayCLL();

                continue;
            
            case 3:
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                push(num);
                displayCLL();

                continue;
            
            case 4:
                int pos;
                cout << "\nEnter the element and position seperated by space: ";
                cin >> num >> pos;

                while (pos > cllLength) {
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
                displayCLL();

                continue;

            case 5:
                truncate();
                displayCLL();
                continue;

            case 6:
                pop();
                displayCLL();
                continue;

            case 7:
                cout << "\nEnter the element index's to be deleted: ";
                cin >> pos;

                while (pos > cllLength) {
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
                displayCLL();

                continue;

            case 8:
                cout << "\nEnter the element to be searched: ";
                cin >> num;

                while (num > INT_MAX || num < INT_MIN) {
                    cout << "\nOnly 32-bit integers are allowed";
                    cout << "\nRe-enter element: ";
                    cin >> num;
                }

                search(num);

                continue;
            
            case 9:
                cout << "\nEnter the element and position seperated by space: ";
                cin >> num >> pos;

                while (pos > cllLength) {
                    cout << "\nPosition greater than size of Linked List! Cannot enter element";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                }

                while (pos <= 0) {
                    cout << "\nPosition cannot be less than 1";
                    cout << "\nRe-enter position: ";
                    cin >> pos;
                }

                replace(num, pos);
                displayCLL();

                continue;

            case 10:
                displayCLL();
                continue;

            case 11:
                cout << "\nExited successfully";
                break;
        }
    }
    
    return 0;
}