#include <iostream>
using namespace std;
 

struct Stack {
    int *arr;
    int top;
    int size;

 Stack(int x) {
    size = x;
    top = -1;
}
void push(int value) {
    if (top == size - 1) {
        cout << "Stack Overflow\n";
    } else {
        top++;
        arr[top] = value;
        cout << value << " pushed into stack\n";
    }
}
int pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return -1;
    } else {
        int value = arr[top];
        top--;
        cout << value << " popped from stack\n";
        return value;
    }
}
int peek() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return -1;
    } else {
        return arr[top];
    }
}
void display() {
    if (top == -1) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack elements: ";
        for (int i =0; i <=top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
};

int main() {
    
    int n;
    cout << "Enter stack size: ";
    cin >> n;
    Stack st(n);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(3);
    st.pop();
    st.peek();
    st.display();
    return 0;
}