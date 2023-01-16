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

void displayDEQueue(DEQueue* dq) {
    if (dq->rear == -1) {
        cout << "\nNo elements in queue to print!" << endl;
    } else {
        cout << "\nThe elements of queue are: front -> ";
        for (int i = dq->front; i <= dq->rear; i++) {
            cout << dq->arr[i] << " ";
        }
        cout << "<- rear" << endl;
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

            case 7:
                cout << "\nExited successfully";
        }
    }
    
    return 0;
}