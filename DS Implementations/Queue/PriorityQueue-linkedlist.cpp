#include<iostream>
using namespace std;

struct Node* front = NULL;
// struct Node* rear = NULL;

struct Node {
    int data;
    int priority;
    Node* next;
};

Node* createNode(int d, int p) {
    Node* new_node = new Node;
    new_node->data = d;
    new_node->priority = p;
    new_node->next = NULL;

    return new_node;
}

void enqueue(int data, int priority) {
    Node* new_node = createNode(data, priority);

    if (front == NULL) {
        front = new_node;
    } else {
        Node* ptr = front;

        while (ptr->next != NULL && ptr->next->priority >= priority) {
            ptr = ptr->next;
        }

        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

void dequeue() {
    if (front == NULL) {
        cout << "\nNo elements in queue to dequeue!" << endl;
        return;
    }

    front = front->next;
}

void peek() {
    if (front == NULL) {
        cout << "\nNo elements in queue!" << endl;
        return;
    }

    cout << "\nPeek: " << front->data << endl;
}

void isEmpty() {
    if (front == NULL) {
        cout << "\nQueue is empty!" << endl;
    } else {
        cout << "\nQueue is not empty!" << endl;
    }
}

void displayQueue() {
    if (front == NULL) {
        cout << "\nNo elements in queue to print!" << endl;
        return;
    }

    Node* ptr = front;
    cout << "\nThe elements of queue are: front -> ";
    while (ptr != NULL) {
        cout << ptr->data << "(" << ptr->priority << ") ";
        ptr = ptr->next;
    }
    cout << " <- rear" << endl;
}

int main() {
    int i = 0;

    while (i != 6) {
        cout << "\nWhat operation do you want to perform?\n1. Create a queue\n2. Enqueue \n3. Dequeue\n4. Peek\n5. Is Empty?\n6. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int n;
                cout << "\nHow many elements do you want to add? ";
                cin >> n;

                int data, priority;
                for (int i = 0; i < n; i++) {
                    cout << "Enter element and it priority seperated by space: ";
                    cin >> data >> priority;
                    enqueue(data, priority);
                }

                displayQueue();

                break;

            case 2:
                cout << "Enter element and it priority seperated by space: ";
                cin >> data >> priority;
                
                enqueue(data, priority);
                displayQueue();

                break;

            case 3:
                dequeue();
                displayQueue();
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
        }
    }
    
    return 0;
}