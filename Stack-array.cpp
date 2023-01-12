#include<iostream>
using namespace std;

struct Stack {
    int top;
    int size;
    int* arr;

    Stack() {
        top = -1;
    }
};

void createStack(Stack* s, int size) {
    s->size = size;
    s->arr = new int[s->size];
}

void push(Stack* s, int ele) {
    if (s->top == s->size - 1) {
        cout << "\nFull capacity reached! Cannot push elements" << endl;
    } else {
        s->top++;
        s->arr[s->top] = ele;
    }
}

void pop(Stack* s) {
    if (s->top == -1) {
        cout << "\nNo elements in stack to remove!" << endl;
    } else {
        s->top--;
    }
}

void peek(Stack* s) {
    if (s->top == -1) {
        cout << "\nNo elements in stack!" << endl;
    } else {
        cout << "\nTop: " << s->arr[s->top] << endl;
    }
}

void isEmpty(Stack* s) {
    if (s->top == -1) {
        cout << "\nStack is empty" << endl;
    } else {
        cout << "\nStack is not empty" << endl;
    }
}

void displayStack(Stack* s) {
    if (s->top == -1) {
        cout << "\nNo elements in stack to print!" << endl;
    } else {
        cout << "\nThe elements of stack are: ";
        for (int i = 0; i <= s->top; i++) {
            cout << s->arr[i] << " ";
        }
        cout << "<- top" << endl;
    }
}
 
int main() {
    Stack st;

    int i = 0;
    while (i != 6) {
        cout << "\nWhat operation do you want to perform?\n1. Create a stack\n2. Push\n3. Pop\n4. Peek\n5. Is Empty?\n6. Exit\nChoice: ";
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

                while (capacity < n) {
                    cout << "\nCannot enter elements more than capacity!";
                    cout << "\nRe-enter: ";
                    cin >> n;
                }

                int num;
                for (int i = 0; i < n; i++) {
                    cout << "Enter element " << i << ": ";
                    cin >> num;
                    push(&st, num);
                }

                displayStack(&st);

                break;
            
            case 2:
                cout << "\nEnter the element to be inserted: ";
                cin >> num;

                push(&st, num);
                displayStack(&st);

                break;
            
            case 3:
                pop(&st);
                displayStack(&st);
                break;

            case 4:
                peek(&st);
                break;

            case 5:
                isEmpty(&st);
                break;

            case 6:
                cout << "\nExited successfully";
                break;
        }
    }
    
    return 0;
}