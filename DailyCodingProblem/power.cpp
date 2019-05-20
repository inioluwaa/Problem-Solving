/*
This problem was asked by Google.

Implement integer exponentiation.
That is, implement the pow(x, y) function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.*/

#include <iostream>
#include <vector>

using namespace std;
int power(int x, int y);
int power2(int x, int y);

int main() {
    cout << power2(5, 1);
}

// Using Recursion.
int power(int x, int y) {
    if (y == 1) return x;
    int sum = 0;
    int p = power(x, y - 1);
    for (int i = 0; i < x; ++i) {
        sum += p;
    }
    return sum;
}

// Using Iteration
int power2(int x, int y) {
    if (y == 0) return 1;
    int sum = x;
    int increment = 0;
    for (int i(0); i < y; ++i) {
        for (int j(1); j < x; ++j) {
            sum += increment;
        }
        increment = sum;
    }
    return sum;
}