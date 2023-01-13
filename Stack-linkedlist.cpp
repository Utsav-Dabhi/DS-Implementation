#include<iostream>
using namespace std;

struct Node* top = NULL;

struct Node {
    int data;
    struct Node* next;
};

void push(int ele) {
    Node* new_node = new Node;
    new_node->data = ele;

    if (top == NULL) {
        new_node->next = NULL;
    } else {
        new_node->next = top;
    }

    top = new_node;
}

void pop() {
    if (top == NULL) {
        cout << "\nNo elements in stack to pop!" << endl;
    } else {
        top = top->next;
    }
}

void peek() {
    if (top == NULL) {
        cout << "\nNo elements in stack!" << endl;
    } else {
        cout << "\nTop: " << top->data << endl;
    }
}

void isEmpty() {
    if (top == NULL) {
        cout << "\nStack is empty" << endl;
    } else {
        cout << "\nStack is not empty" << endl;
    }
}

void displayStack() {
    if (top == NULL) {
        cout << "\nNo elements in stack to print!" << endl;
    } else {
        Node* ptr = top;

        cout << "\nThe elements of stack are: top -> ";
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}
 
int main() {
    int i = 0;
    while (i != 6) {
        cout << "\nWhat operation do you want to perform?\n1. Create a stack\n2. Push\n3. Pop\n4. Peek\n5. Is Empty?\n6. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int n;
                cout << "\nHow many elements do you want to insert? ";
                cin >> n;

                int num;
                for (int i = 0; i < n; i++) {
                    cout << "Enter element " << i << ": ";
                    cin >> num;
                    push(num);
                }

                displayStack();

                break;

            case 2:
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                push(num);
                displayStack();

                break;

            case 3:
                pop();
                displayStack();
                break;

            case 4:
                peek();
                break;

            case 5:
                isEmpty();
                break;
                
            case 6:
                cout << "\nExited successfully";
                break;

            default:
                cout << "\nWrong Choice!" << endl;
                break;
        }
    }
    
    return 0;
}