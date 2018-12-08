// Problem 546A - CodeForces - Soldiers and Bananas

#include <iostream>
using namespace std;

int main() {
    int k, n, w;
    int total = 0;
    cin >> k >> n >> w;

    for (int i {1}; i <= w; i++) {
        total += i * k;
    }
    if (total > n) {
        cout << abs(n - total) << endl;
    }
    else {
        cout << 0 << endl;
    }
}
