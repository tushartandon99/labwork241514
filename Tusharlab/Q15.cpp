#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) { data = v; next = nullptr; }
};

class SinglyLinkedList {
    Node* head;
public:
    void createNode(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
    SinglyLinkedList() { head = nullptr; }
    void deleteByValue(int x) {
        if (!head) { cout << "List is empty" << endl; return; }
        while (head && head->data == x) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            cout << "Deleted value " << x << " from list" << endl;
            return;
        }
        Node* t = head;
        while (t->next && t->next->data != x) t = t->next;
        if (!t->next) { cout << "Value not found" << endl; return; }
        Node* tmp = t->next;
        t->next = tmp->next;
        delete tmp;
        cout << "Deleted value " << x << " from list" << endl;
    }

    void deleteByPosition(int pos) {
        if (!head) { cout << "List is empty" << endl; return; }
        if (pos < 0) { cout << "Invalid position" << endl; return; }
        if (pos == 0) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            cout << "Deleted node at position 0" << endl;
            return;
        }
        Node* t = head;
        int i = 0;
        while (t->next && i < pos - 1) { t = t->next; i++; }
        if (!t->next) { cout << "Position out of range" << endl; return; }
        Node* tmp = t->next;
        t->next = tmp->next;
        delete tmp;
        cout << "Deleted node at position " << pos << endl;
    }

    void display() {
        if (!head) { cout << "List is empty" << endl; return; }
        cout << "List: ";
        Node* t = head;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int x = 0;
    while(x<6){
        list.createNode(x);
        x++;
    }
    list.display();
    int y, pos;
    cout << "Enter value to delete: "; cin >> x; list.deleteByValue(x);
    cout << "Enter position (0-based) to delete: "; cin >> pos; list.deleteByPosition(pos);
    list.display();
}