#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* frontNode = NULL;   
Node* rearNode = NULL;    

void enqueue(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if (rearNode == NULL) {  
   
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }

    cout << x << " enqueued\n";
}

void dequeue() {
    if (frontNode == NULL) {
        cout << "Queue Underflow (no element)\n";
        return;
    }

    Node* temp = frontNode;
    cout << temp->data << " dequeued\n";

    frontNode = frontNode->next;

    if (frontNode == NULL) {  

        rearNode = NULL;
    }

    delete temp;
}

int peek() {
    if (frontNode == NULL) {
        cout << "Queue is empty\n";
        return -1;
    }
    return frontNode->data;
}

void display() {
    if (frontNode == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";
    Node* temp = frontNode;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n--- QUEUE MENU (Linked List) ---\n";
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
