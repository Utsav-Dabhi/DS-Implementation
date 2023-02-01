#include<iostream>
#include<math.h>
using namespace std;

struct MaxHeapQueue {
    int capacity;
    int heap_size;
    int* heapArr;
};

void createQueue(MaxHeapQueue* q, int capacity) {
    q->capacity = capacity;
    q->heap_size = 0;
    q->heapArr = new int[capacity];

    for (int i = 0; i < q->capacity; i++) {
        q->heapArr[i] = -999;
    }
}

// helper functions
int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }
int getLeftChildIndex(int index) { return 2 * index + 1; }
int getRightChildIndex(int index) { return 2 * index + 2; }

bool hasParent(int index) { return getParentIndex(index) >= 0; }
bool hasLeftChild(MaxHeapQueue* q , int index) { return getLeftChildIndex(index) < q->heap_size; }
bool hasRightChild(MaxHeapQueue* q , int index) { return getRightChildIndex(index) < q->heap_size; }

int getParent(MaxHeapQueue* q, int index) { return q->heapArr[getParentIndex(index)]; }
int getLeftChild(MaxHeapQueue* q, int index) { return q->heapArr[getLeftChildIndex(index)]; }
int getRightChild(MaxHeapQueue* q, int index) { return q->heapArr[getRightChildIndex(index)]; }
//

void heapifyUp(MaxHeapQueue* q) {
    int ind = q->heap_size - 1;

    while (hasParent(ind) && getParent(q, ind) < q->heapArr[ind]) {
        swap(q->heapArr[getParentIndex(ind)], q->heapArr[ind]);
        ind = getParentIndex(ind);
    }
}

void heapifyDown(MaxHeapQueue* q) {
    int ind = 0;

    while (hasLeftChild(q, ind)) {
        int greatestChildIndex = getLeftChildIndex(ind);

        if (hasRightChild(q, ind) && getRightChild(q, ind) > getLeftChild(q, ind)) {
            greatestChildIndex = getRightChildIndex(ind);
        }

        if (q->heapArr[ind] > q->heapArr[greatestChildIndex]) {
            break;
        } else {
            swap(q->heapArr[greatestChildIndex], q->heapArr[ind]);
            ind = greatestChildIndex;
        }
    }
}

void enqueue(MaxHeapQueue* q, int ele) {
    if (q->heap_size == q->capacity) {
        cout << "\nNo space in queue to enqueue!" << endl;
    } else {
        q->heapArr[q->heap_size] = ele;
        q->heap_size++;

        heapifyUp(q);
    }
}

void dequeue(MaxHeapQueue* q) {
    if (q->heap_size == 0) {
        cout << "\nNo elements in queue to dequeue!" << endl;
    } else {
        q->heapArr[0] = q->heapArr[q->heap_size - 1];

        q->heapArr[q->heap_size - 1] = -999;
        q->heap_size--;

        heapifyDown(q);
    }
}

void peek(MaxHeapQueue* q) {
    if (q->heap_size == 0) {
        cout << "\nNo elements in queue!" << endl;
    } else {
        cout << "\nPeek: " << q->heapArr[0] << endl;
    }
}

void isEmpty(MaxHeapQueue* q) {
    if (q->heap_size == 0) {
        cout << "\nQueue is empty!" << endl;
    } else {
        cout << "\nQueue is not empty!" << endl;
    }
}

// functions related to printing
void printSpace(int count) {
    for (int x = 0; x < count; x++) {
        cout << " ";
    }
}

void printQueue(int* arr, int size) {
    int height = ceil(log(size) + 1);   //+1 handle the last leaves
    int width = pow(2, height) * height;
    int index = 0;

    cout << "\nThe elements of queue are: \n";
    for (int x = 0; x <= height; x++) { //for each level of the tree
        for (int z = 0; z < pow(2, x); z++) {   // for each node on that tree level
            int digitWidth = 1;
            if (arr[index] != 0) {
                digitWidth = floor(log10(abs(arr[index]))) + 1;
            }
            printSpace(width/(pow(2, x)) - digitWidth);
            if (index < size) {
                cout << arr[index++];
            } else {
                cout << " ";
            }
            printSpace(width/(pow(2, x)));
        }
        cout << endl;
    }
}
// printing functions end

int main() {
    MaxHeapQueue mhq;

    int i = 0;
    while (i != 6) {
        cout << "\nWhat operation do you want to perform?\n1. Create a queue\n2. Enqueue \n3. Dequeue\n4. Peek\n5. Is Empty?\n6. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int capacity;
                cout << "\nEnter the size of queue: ";
                cin >> capacity;

                createQueue(&mhq, capacity);
                cout << "\nQueue created!" << endl;

                break;

            case 2:
                int num;
                cout << "\nEnter element to be inserted: ";
                cin >> num;

                enqueue(&mhq, num);
                printQueue(mhq.heapArr, mhq.capacity);

                break;

            case 3:
                dequeue(&mhq);
                printQueue(mhq.heapArr, mhq.capacity);
                break;

            case 4:
                peek(&mhq);
                break;

            case 5:
                isEmpty(&mhq);
                break;

            case 6:
                cout << "\nExited successfully";
                break;
        }
    }
    
    return 0;
}