#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class QueueLL {
private:
    Node* frontNode;
    Node* rearNode;

public:
    QueueLL() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rearNode == nullptr) {
            frontNode = rearNode = newNode;
            return;
        }
        rearNode->next = newNode;
        rearNode = newNode;
        cout<<newNode->data<<" added in the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        cout<<temp->data<<" removed from the queue.\n";
        delete temp;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        
        cout<<"Next Element: ";
        return frontNode->data;
    }
};

int main() {
    QueueLL q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
}