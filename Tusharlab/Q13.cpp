#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;
public:
    void enqueue(int x) {
        s1.push(x);
        cout << "Enqueued " << x << endl;
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << "Dequeued " << s2.top() << endl;
        s2.pop();
    }

    void peek() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << "Front element: " << s2.top() << endl;
    }

    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        stack<int> temp1 = s1;
        stack<int> temp2 = s2;

        while (!temp1.empty()) {
            temp2.push(temp1.top());
            temp1.pop();
        }

        cout << "Queue elements: ";
        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(2);
    q.display();
    q.dequeue();
    q.peek();
    q.display();
}