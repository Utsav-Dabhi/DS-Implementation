#include<iostream>
using namespace std;

struct Node* front = NULL;
struct Node* rear = NULL;

struct Node {
    int data;
    struct Node* next;
};

void enqueue(int ele) {
    Node* new_node = new Node;
    new_node->data = ele;
    new_node->next = NULL;

    if (rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue() {
    if (rear == NULL) {
        cout << "\nNo elements in queue to dequeue!" << endl;
    } else if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
}

void peek() {
    if (rear == NULL) {
        cout << "\nNo elements in queue!" << endl;
    } else {
        cout << "\nFront: " << front->data << endl;
    }
}

void isEmpty() {
    if (rear == NULL) {
        cout << "\nQueue is empty" << endl;
    } else {
        cout << "\nQueue is not empty" << endl;
    }
}

void displayQueue() {
    if (rear == NULL) {
        cout << "\nNo elements in queue to print!" << endl;
    } else {
        Node* ptr = front;

        cout << "\nThe elements of queue are: front -> ";
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << "<- rear" << endl;
    }
}

int main() {
    int i = 0;
    while (i != 6) {
        cout << "\nWhat operation do you want to perform?\n1. Create a queue\n2. Enqueue (add at end)\n3. Dequeue (remove from front)\n4. Peek\n5. Is Empty?\n6. Exit\nChoice: ";
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
                    enqueue(num);
                }

                displayQueue();

                break;

            case 2:
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                enqueue(num);
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