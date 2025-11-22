#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int v){
        data = v;
        next = nullptr;
    }
};

class SinglyLinkedList{
    Node *head;
public:
    SinglyLinkedList() { 
        head = nullptr; 
    }
    void insertAtBeginning(int x){
        Node *n = new Node(x);
        n->next = head;
        head = n;
        cout << x<< " Inserted at beginning" << endl;
    }

    void insertAtEnd(int x)
    {
        Node *n = new Node(x);
        if (!head){
            head = n;
            cout <<x<<" Inserted at end" << endl;
            return;
        }
        Node *t = head;
        while (t->next){
            t = t->next;
        }
        t->next = n;
        cout << x << " Inserted at end" << endl;
    }

    void insertAfterPosition(int pos, int x){
        if (pos < 0){
            cout << "Invalid position" << endl;
            return;
        }
        Node *t = head;
        int i = 0;
        while (t && i < pos){
            t = t->next;
            i++;
        }
        if (!t){
            cout << "Position out of range" << endl;
            return;
        }
        Node *n = new Node(x);
        n->next = t->next;
        t->next = n;
        cout << x << " Inserted at position " << pos << endl;
    }
    void display(){
        if (!head){
            cout << "List is empty" << endl;
            return;
        }
        cout << "List: ";
        Node *t = head;
        while (t){
            cout << t->data << " ";
            t = t->next;
        }
    }
};

int main()
{
    SinglyLinkedList list;
    int x;
    int pos;
    cout << "Enter value: ";
    cin >> x;
    list.insertAtBeginning(x);
    cout << "Enter value: ";
    cin >> x;
    list.insertAtBeginning(x);
    list.display();
    cout << "Enter value: ";
    cin >> x;
    list.insertAtEnd(x);
    cout << "Enter position (0-based): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> x;
    list.insertAfterPosition(pos, x);
    list.display();
}