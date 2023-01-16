#include<iostream>
using namespace std;

struct DEQueue {
    int size;
    int front;
    int rear;
    int* arr;
};

void createDEQueue(DEQueue* dq, int size) {
    dq->size = size;
    dq->front = dq->rear = -1;
    dq->arr = new int[dq->size];
}

void enqueueRear(DEQueue* dq, int ele) {
    if (dq->rear + 1 == dq->size) {
        cout << "\nNo space in queue to enqueue from rear!" << endl;
    } else if (dq->rear == -1) {
        dq->rear++;
        dq->arr[dq->rear] = ele;

        dq->front++;
    } else {
        dq->rear++;
        dq->arr[dq->rear] = ele;
    }
}

void enqueueFront(DEQueue* dq, int ele) {
    if (dq->front == 0) {
        cout << "\nNo space in queue to enqueue from front!" << endl;
    } else if (dq->front == -1) {
        dq->front++;
        dq->arr[dq->front] = ele;

        dq->rear++;
    } else {
        dq->front--;
        dq->arr[dq->front] = ele;
    }
}

void dequeueFront(DEQueue* dq) {
    if (dq->front == -1) {
        cout << "\nNo elements in queue to dequeue!" << endl;
    } else if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else {
        dq->front++;
    }
}

void dequeueRear(DEQueue* dq) {
    if (dq->rear == -1)  {
        cout << "\nNo elements in queue to dequeue!" << endl;
    } else if (dq->rear == dq->front) {
        dq->front = dq->rear = -1;
    } else {
        dq->rear--;
    }
}

void isEmpty(DEQueue* dq) {
    if (dq->rear == -1) {
        cout << "\nQueue is empty" << endl;
    } else {
        cout << "\nQueue is not empty" << endl;
    }
}

void displayDEQueue(DEQueue* dq) {
    if (dq->rear == -1) {
        cout << "\nNo elements in queue to print!" << endl;
    } else {
        cout << "\nThe elements of queue are: front -> ";
        for (int i = dq->front; i <= dq->rear; i++) {
            cout << dq->arr[i] << "(" << i << ") ";
        }
        cout << "<- rear";
        cout << "\nSize: " << dq->size <<  endl;
    }
}

int main() {
    DEQueue deq;

    int i = 0;
    while (i != 7) {
        cout << "\nWhat operation do you want to perform?\n1. Create a double ended queue\n2. Enqueue rear\n3. Enqueue front\n4. Dequeue front\n5. Dequeue rear\n6. Is Empty?\n7. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int capacity;
                cout << "\nEnter the size of queue: ";
                cin >> capacity;

                createDEQueue(&deq, capacity);

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
                    enqueueRear(&deq, num);
                }

                displayDEQueue(&deq);

                break;

            case 2:
                cout << "\nEnter the element to be inserted from end: ";
                cin >> num;

                enqueueRear(&deq, num);
                displayDEQueue(&deq);

                break;

            case 3:
                cout << "\nEnter the element to be inserted from front: ";
                cin >> num;

                enqueueFront(&deq, num);
                displayDEQueue(&deq);

                break;

            case 4:
                dequeueFront(&deq);
                displayDEQueue(&deq);
                break;

            case 5:
                dequeueRear(&deq);
                displayDEQueue(&deq);
                break;

            case 6:
                isEmpty(&deq);
                break;

            case 7:
                cout << "\nExited successfully";
        }
    }
    
    return 0;
}