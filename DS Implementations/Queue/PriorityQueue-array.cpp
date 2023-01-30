#include<iostream>
using namespace std;

struct item {
    int value;
    int priority;
};

struct Queue {
    int size;
    int front, rear;
    item* arr;
};

void createQueue(Queue* q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->arr = new item[q->size];
}

int peek(Queue* q) {
    int maxPriority = INT_MIN;
    int peekPos = -1;

    for (int i = q->front; i <= q->rear; i++) {
        if (maxPriority == q->arr[i].priority && peekPos > -1 && q->arr[peekPos].value < q->arr[i].value) {
            maxPriority = q->arr[i].priority;
            peekPos = i;
        } else if (maxPriority < q->arr[i].priority) {
            maxPriority = q->arr[i].priority;
            peekPos = i;
        }
    }

    return peekPos;
}

void enqueue(Queue* q, int ele, int prio) {
    if (q->rear + 1 == q->size) {
        cout << "\nNo space in queue to enqueue!" << endl;
    } else if (q->rear == -1) {
        q->rear++;
        q->arr[q->rear].value = ele;
        q->arr[q->rear].priority = prio;

        q->front++;
    } else {
        q->rear++;
        q->arr[q->rear].value = ele;
        q->arr[q->rear].priority = prio;
    }
}

void dequeue(Queue* q) {
    if (q->rear == -1) {
        cout << "\nNo elements in queue to dequeue!" << endl;
    } else if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        int maxPrioIndex = peek(q);

        for (int i = maxPrioIndex; i <= q->rear; i++) {
            q->arr[i].value = q->arr[i + 1].value;
            q->arr[i].priority = q->arr[i + 1].priority;
        }

        q->rear--;
    }
}

void isEmpty(Queue* q) {
    if (q->rear == -1) {
        cout << "\nQueue is empty!" << endl;
    } else {
        cout << "\nQueue is not empty!" << endl;
    }
}

void displayQueue(Queue* q) {
    if (q->front == -1) {
        cout << "\nNo elements in queue to print!" << endl;
    } else {
        cout << "\nThe elements of queue are: front -> ";
        for (int i = q->front; i <= q->rear; i++) {
            cout << q->arr[i].value << "(" << q->arr[i].priority << ")" << " ";
        }
        cout << "<- rear" << endl;
    }
}

int main() {
    Queue que;

    int i = 0;
    while (i != 6) {
        cout << "\nWhat operation do you want to perform?\n1. Create a queue\n2. Enqueue \n3. Dequeue\n4. Peek\n5. Is Empty?\n6. Exit\nChoice: ";
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

                int num, priority;
                for (int i = 0; i < n; i++) {
                    cout << "Enter element and it priority seperated by space: ";
                    cin >> num >> priority;
                    enqueue(&que, num, priority);
                }

                displayQueue(&que);

                break;
            
            case 2:
                cout << "\nEnter element and it priority seperated by space: ";
                cin >> num >> priority;
                    
                enqueue(&que, num, priority);
                displayQueue(&que);

                break;

            case 3:
                dequeue(&que);
                displayQueue(&que);

                break;

            case 4: {
                int maxPrioIndex = peek(&que);
                cout << "\nPeek: " << que.arr[maxPrioIndex].value << "(" << que.arr[maxPrioIndex].priority << ")" << endl;
            }
            
                break;

            case 5:
                isEmpty(&que);
                break;

            case 6:
                cout << "\nExited successfully";
                break;
        }
    }
    
    return 0;
}