#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at end (for testing)
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Delete by value
void deleteByValue(int value) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    // If head is to be deleted
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << value << " deleted from list\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Value not found\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    cout << value << " deleted from list\n";
}

// Delete by position (1-based)
void deleteByPosition(int pos) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node at position 1 deleted\n";
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        cout << "Invalid position\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;

    cout << "Node at position " << pos << " deleted\n";
}

// Display list
void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, pos;

    while (true) {
        cout << "\n--- LINKED LIST MENU ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Delete by Value\n";
        cout << "3. Delete by Position\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteByValue(value);
                break;

            case 3:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteByPosition(pos);
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
