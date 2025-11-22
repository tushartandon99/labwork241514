#include <iostream>
using namespace std;

#define MAX 100 

struct Stack {
    int arr[MAX];
    int top;
};
void init(Stack &s) {
    s.top = -1;
}
void push(Stack &s, int value) {
    if (s.top == MAX - 1) {
        cout << "Stack Overflow\n";
    } else {
        s.top++;
        s.arr[s.top] = value;
        cout << value << " pushed into stack\n";
    }
}
int pop(Stack &s) {
    if (s.top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    } else {
        int value = s.arr[s.top];
        s.top--;
        cout << value << " popped from stack\n";
        return value;
    }
}
int peek(Stack &s) {
    if (s.top == -1) {
        cout << "Stack is empty\n";
        return -1;
    } else {
        return s.arr[s.top];
    }
}
void display(Stack &s) {
    if (s.top == -1) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack elements: ";
        for (int i = s.top; i >= 0; i--) {
            cout << s.arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Stack s;
    init(s);

    int choice, value;

    while (true) {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(s, value);
                break;

            case 2:
                pop(s);
                break;

            case 3:
                value = peek(s);
                if (value != -1)
                    cout << "Top element is: " << value << endl;
                break;

            case 4:
                display(s);
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
