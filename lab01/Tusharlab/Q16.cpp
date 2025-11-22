#include <iostream>
using namespace std;

#define MAX 100

int tree[MAX];   // array for tree
int n = 0;       // number of nodes

// Insert node at given index
void insertNode(int index, int value) {
    if (index >= MAX) {
        cout << "Index out of range!\n";
        return;
    }
    tree[index] = value;
    cout << value << " inserted at index " << index << endl;
}

// Build binary tree from user input
void createTree() {
    cout << "Enter number of nodes: ";
    cin >> n;

   cout << "Enter values level-wise (use -1 for empty node):\n";
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    cout << "Binary tree created.\n";
}

// Display tree (array format)
void displayTree() {
    if (n == 0) {
        cout << "Tree is empty\n";
        return;
    }

    cout << "Binary Tree (Array Representation):\n";
    for (int i = 0; i < n; i++) {
        cout << "Node[" << i << "] = " << tree[i] << endl;
    }
}

int main() {
    int choice, index, value;

    while (true) {
        cout << "\n--- BINARY TREE (ARRAY) MENU ---\n";
        cout << "1. Create Tree\n";
        cout << "2. Insert Node at Index\n";
        cout << "3. Display Tree\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                createTree();
                break;

            case 2:
                cout << "Enter index to insert: ";
                cin >> index;
                cout << "Enter value: ";
                cin >> value;
                insertNode(index, value);
                if (index >= n) n = index + 1;  // update size
                break;

            case 3:
                displayTree();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
