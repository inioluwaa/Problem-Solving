#include <iostream>

int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}

int GCDFast(int a, int b) {
    int a_prime;
    if (b == 0) return a;
    a_prime = a % b;
    return GCDFast(b, a_prime);
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << GCDFast(a, b) << std::endl;
    return 0;
}
