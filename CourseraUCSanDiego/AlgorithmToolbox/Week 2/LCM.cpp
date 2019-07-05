#include <iostream>

/*
long long lcm_naive(int a, int b) {
    for (long l = 1; l <= (long long) a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long) a * b;
}
*/

int GCDFast(int a, int b) {
    int a_prime;
    if (b == 0) return a;
    a_prime = a % b;
    return GCDFast(b, a_prime);
}

long long LCMFast(int a, int b) {
    long long answer;
    long long Mul = (long long) a * b;
    answer = Mul / GCDFast(a, b);
    return answer;
}
int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << LCMFast(a, b) << std::endl;
    return 0;
}
