#include <iostream>
using namespace std;

#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

void init(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack &s) {
    return s.top == -1;
}

bool isFull(Stack &s) {
    return s.top == MAX - 1;
}

void push(Stack &s, int x) {
    if (isFull(s)) {
        cout << "Stack Overflow\n";
        return;
    }
    s.arr[++s.top] = x;
}

int pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return s.arr[s.top--];
}

// Queue using 2 stacks
Stack s1, s2;

// Enqueue operation
void enqueue(int x) {
    push(s1, x);
    cout << x << " enqueued\n";
}

// Dequeue operation
int dequeue() {
    int value;

    if (isEmpty(s1) && isEmpty(s2)) {
        cout << "Queue Underflow\n";
        return -1;
    }

    // Move elements from s1 to s2 only if s2 is empty
    if (isEmpty(s2)) {
        while (!isEmpty(s1)) {
            push(s2, pop(s1));
        }
    }

    value = pop(s2);
    cout << value << " dequeued\n";
    return value;
}

// Peek front element
int peek() {
    if (isEmpty(s1) && isEmpty(s2)) {
        cout << "Queue is empty\n";
        return -1;
    }

    if (isEmpty(s2)) {
        while (!isEmpty(s1)) {
            push(s2, pop(s1));
        }
    }

    return s2.arr[s2.top];
}

// Display queue elements
void display() {
    if (isEmpty(s1) && isEmpty(s2)) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue (front to rear): ";

    // Print s2 from top to bottom
    for (int i = s2.top; i >= 0; i--)
        cout << s2.arr[i] << " ";

    // Print s1 from bottom to top
    for (int i = 0; i <= s1.top; i++)
        cout << s1.arr[i] << " ";

    cout << endl;
}

int main() {
    init(s1);
    init(s2);

    int choice, value;

    while (true) {
        cout << "\n--- QUEUE USING TWO STACKS ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                value = peek();
                if (value != -1)
                    cout << "Front: " << value << endl;
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
