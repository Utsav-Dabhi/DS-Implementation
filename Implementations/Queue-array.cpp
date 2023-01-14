#include<iostream>
using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int* arr;
};

void createQueue(Queue* q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->arr = new int[q->size];
}

void enqueue(Queue* q, int ele) {
    if (q->rear + 1 == q->size) {
        cout << "\nNo space in queue to enqueue!" << endl;
    } else if (q->rear == -1) {
        q->rear++;
        q->arr[q->rear] = ele;

        q->front++;
    } else {
        q->rear++;
        q->arr[q->rear] = ele;
    }
}

void dequeue(Queue* q) {
    if (q->rear == -1) {
        cout << "\nNo elements in queue to dequeue!" << endl;
    } else if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        for (int i = q->front; i < q->rear; i++) {
            q->arr[i] = q->arr[i + 1];
        }
        q->rear--;
    }
}

void peek(Queue* q) {
    if (q->rear == -1) {
        cout << "\nNo elements in queue!" << endl;
    } else {
        cout << "\nFront: " << q->arr[q->front] << endl;
    }
}

void isEmpty(Queue* q) {
    if (q->rear == -1) {
        cout << "\nQueue is empty" << endl;
    } else {
        cout << "\nQueue is not empty" << endl;
    }
}

void displayQueue(Queue* q) {
    if (q->rear == -1) {
        cout << "\nNo elements in queue to print!" << endl;
    } else {
        cout << "\nThe elements of queue are: front -> ";
        for (int i = q->front; i <= q->rear; i++) {
            cout << q->arr[i] << " ";
        }
        cout << "<- rear" << endl;
    }
}

int main() {
    Queue que;

    int i = 0;
    while (i != 6) {
        cout << "\nWhat operation do you want to perform?\n1. Create a queue\n2. Enqueue (add at end)\n3. Dequeue (remove from front)\n4. Peek\n5. Is Empty?\n6. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int capacity;
                cout << "\nEnter the size of queue: ";
                cin >> capacity;

                createQueue(&que, capacity);

                int n;
                cout << "\nHow many elements do you want to insert? ";
                cin >> n;

                while (capacity < n) {
                    cout << "\nCannot enter elements more than capacity!";
                    cout << "\nRe-enter: ";
                    cin >> n;
                }

                int num;
                for (int i = 0; i < n; i++) {
                    cout << "Enter element " << i << ": ";
                    cin >> num;
                    enqueue(&que, num);
                }

                displayQueue(&que);

                break;
            
            case 2:
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                enqueue(&que, num);
                displayQueue(&que);

                break;

            case 3:
                dequeue(&que);
                displayQueue(&que);
                break;

            case 4:
                peek(&que);
                break;

            case 5:
                isEmpty(&que);
                break;

            case 6:
                cout << "\nExited successfully";
        }
    }
    
    return 0;
}