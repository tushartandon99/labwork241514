#include <iostream>
using namespace std;

#define MAX 100
int queueArr[MAX];
int frontIndex = -1;
int rearIndex = -1;
void enqueue(int x) {
    if (rearIndex == MAX - 1) {
        cout << "Queue Overflow\n";
        return;
    }

    if (frontIndex == -1) 
        frontIndex = 0;

    rearIndex++;
    queueArr[rearIndex] = x;
    cout << x << " enqueued\n";
}
void dequeue() {
    if (frontIndex == -1 || frontIndex > rearIndex) {
        cout << "Queue Underflow (no elements)\n";
        return;
    }

    cout << queueArr[frontIndex] << " dequeued\n";
    frontIndex++;
}
int peek() {
    if (frontIndex == -1 || frontIndex > rearIndex) {
        cout << "Queue is empty\n";
        return -1;
    }
    return queueArr[frontIndex];
}
void display() {
    if (frontIndex == -1 || frontIndex > rearIndex) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";
    for (int i = frontIndex; i <= rearIndex; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                value = peek();
                if (value != -1)
                    cout << "Front element: " << value << endl;
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
