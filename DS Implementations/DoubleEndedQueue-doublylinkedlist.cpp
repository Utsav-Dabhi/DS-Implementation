#include<iostream>
using namespace std;

struct Node* front = NULL;
struct Node* rear = NULL;

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

void enqueueRear(int ele) {
    Node* new_node = new Node;
    new_node->data = ele;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        new_node->prev = rear;
        rear->next = new_node;
        rear = new_node;
    }
}

void enqueueFront(int ele) {
    Node* new_node = new Node;
    new_node->data = ele;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (front == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        front->prev = new_node;
        new_node->next = front;
        front = new_node;
    }
}

void dequeueFront() {
    if (front == NULL) {
        cout << "\nNo elements in queue to dequeue!" << endl;
    } else if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }
}

void dequeueRear() {
    if (rear == NULL) {
        cout << "\nNo elements in queue to dequeue!" << endl;
    } else if (rear == front) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }
}

void isEmpty() {
    if (front == NULL && rear == NULL) {
        cout << "\nQueue is empty" << endl;
    } else {
        cout << "\nQueue is not empty" << endl;
    }
}

void displayDEQueue() {
    if (rear == NULL) {
        cout << "\nNo elements in queue to print!" << endl;
    } else {
        Node* ptr = front;

        cout << "\nThe elements of queue are: front -> ";
        while (ptr->next != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }

        cout << ptr->data << " <- rear" << endl;
    }
}

int main() {
    int i = 0;
    while (i != 7) {
        cout << "\nWhat operation do you want to perform?\n1. Create a double ended queue\n2. Enqueue rear\n3. Enqueue front\n4. Dequeue front\n5. Dequeue rear\n6. Is Empty?\n7. Exit\nChoice: ";
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
                    enqueueRear(num);
                }

                displayDEQueue();

                break;

            case 2:
                cout << "\nEnter the element to be inserted from end: ";
                cin >> num;

                enqueueRear(num);
                displayDEQueue();

                break;

            case 3:
                cout << "\nEnter the element to be inserted from front: ";
                cin >> num;

                enqueueFront(num);
                displayDEQueue();

                break;
            
            case 4:
                dequeueFront();
                displayDEQueue();
                break;

            case 5:
                dequeueRear();
                displayDEQueue();
                break;

            case 6:
                isEmpty();
                break;
            
            case 7:
                cout << "\nExited successfully";
        }
    }

    return 0;
}