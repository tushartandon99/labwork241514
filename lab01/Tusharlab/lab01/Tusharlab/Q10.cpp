#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* topNode = NULL; 
void push(int x) {
    Node* newNode = new Node(); 
    newNode->data = x;
    newNode->next = topNode;   
    topNode = newNode;          
    cout << x << " pushed\n";
}
void pop() {
    if (topNode == NULL) {
        cout << "Stack Underflow (no element)\n";
        return;
    }
    Node* temp = topNode;
    cout << temp->data << " popped\n";
    topNode = topNode->next; 
    delete temp;             
}
int peek() {
    if (topNode == NULL) {
        cout << "Stack is empty\n";
        return -1;
    }
    return topNode->data;
}
void display() {
    if (topNode == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements (top to bottom): ";
    Node* temp = topNode;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n\n--- STACK MENU (Linked List) ---\n";
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
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                value = peek();
                if (value != -1)
                    cout << "Top element: " << value << endl;
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
