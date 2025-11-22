#include <iostream>
using namespace std;

class Queue {
private:
    int frontIndex, rearIndex, size, capacity;
    int* arr;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[cap];
        frontIndex = 0;
        size = 0;
        rearIndex = cap - 1;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = x;
        cout<<x<<" added in queue\n";
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout<<arr[frontIndex]<<" removed from queue\n";
        frontIndex = (frontIndex + 1) % capacity;
        
        size--;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        cout<<"Next Element: "; 
        return arr[frontIndex];
    }
};

int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
}