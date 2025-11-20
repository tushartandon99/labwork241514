//Program to insert, delete, and traverse elements in a one-dimensional array.

#include <iostream>
using namespace std;

int main() {
    int arr[100], n, choice, pos, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Traverse\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: // INSERT
            cout << "Enter position to insert (0 to " << n << "): ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;

            if (pos < 0 || pos > n) {
                cout << "Invalid position!\n";
                break;
            }

            // shift elements to right
            for (int i = n; i > pos; i--)
                arr[i] = arr[i - 1];

            arr[pos] = value;
            n++;
            cout << "Element inserted.\n";
            break;

        case 2: // DELETE
            cout << "Enter position to delete (0 to " << n - 1 << "): ";
            cin >> pos;

            if (pos < 0 || pos >= n) {
                cout << "Invalid position!\n";
                break;
            }

            // shift elements to left
            for (int i = pos; i < n - 1; i++)
                arr[i] = arr[i + 1];

            n--;
            cout << "Element deleted.\n";
            break;

        case 3: // TRAVERSE
            cout << "Array elements: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
