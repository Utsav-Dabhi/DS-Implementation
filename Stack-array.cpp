#include<iostream>
using namespace std;

struct Stack {
    int top;
    int size;
    int* arr;
};

void createStack(Stack* s, int size) {
    s->size = size;
    s->arr = new int[s->size];
    s->top = -1;
}

void push(Stack* s, int ele) {
    if (s->top == s->size - 1) {
        cout << "\nFull capacity reached! Cannot push elements";
    } else {
        s->top++;
        s->arr[s->top] = ele;
    }
}

void displayStack(Stack* s) {
    cout << "\nThe elements of stack are: ";
    for (int i = 0; i <= s->top; i++) {
        cout << s->arr[i] << " ";
    }
    cout << "<- top" << endl;
}
 
int main() {
    Stack st;

    int i = 0;
    while (i != 2) {
        cout << "\nWhat operation do you want to perform?\n1. Create a stack\n2. Exit\nChoice: ";
        cin >> i;

        switch(i) {
            case 1:
                int capacity;
                cout << "\nEnter the size of stack: ";
                cin >> capacity;

                createStack(&st, capacity);

                int n;
                cout << "\nHow many elements do you want to insert? ";
                cin >> n;

                int num;
                for (int i = 0; i < n; i++) {
                    cout << "Enter element " << i << ": ";
                    cin >> num;
                    push(&st, num);
                }

                displayStack(&st);

                break;
            
            case 2:
                cout << "2\n";
                break;
        }
    }
    
    return 0;
}