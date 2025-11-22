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

class Stack {
private:
    Node* topNode;
public:
    Stack() {
        topNode = nullptr;
    }
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return topNode->data;
    }
    bool isEmpty() {
        return topNode == nullptr;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top after one pop: " << s.top() << endl;
    while (!s.isEmpty()) {
        cout << "Popping: " << s.top() << endl;
        s.pop();
    }
}