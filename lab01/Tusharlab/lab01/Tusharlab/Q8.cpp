#include <iostream>
using namespace std;


int main() {
    int base, size, rows, cols, i, j;

    cout << "Enter base address: ";
    cin >> base;

    cout << "Enter size of each element (in bytes): ";
    cin >> size;

    cout << "Enter total rows: ";
    cin >> rows;

    cout << "Enter total columns: ";
    cin >> cols;

    cout << "Enter element index (i j): ";
    cin >> i >> j;
    if(i>rows||j>cols){
        cout<<"invalid index";
        return 0;
    }

    // Row-major address
    int rowMajor = base + (i * cols + j) * size;

    // Column-major address
    int colMajor = base + (j * rows + i) * size;

    cout << "\nRow-Major Address = " << rowMajor;
    cout << "\nColumn-Major Address = " << colMajor;

    return 0;
}
