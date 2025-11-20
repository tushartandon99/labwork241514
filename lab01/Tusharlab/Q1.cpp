//Recursive generation of Fibonacci series up to N terms.

#include <iostream>
using namespace std;

void fib(int n)
{
    int a = 0, b = 1;
    cout << a << " ";

    if (n > 1)
        cout << b << " ";

    for (int i = 2; i < n; i++){
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
}

int main()
{
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    fib(n);
}
