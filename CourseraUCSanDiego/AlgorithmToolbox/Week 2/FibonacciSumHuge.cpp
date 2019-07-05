#include <iostream>
#include <vector>

using namespace std;

/*
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
*/

long long FindPisanoPeriod(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i(0); i < m * m; ++i) {
        a = b, b = c;
        c = (a + b) % m;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long FibonacciSumHuge(long long former_n) {
    long long m_pisano = FindPisanoPeriod(10);
    long long n = former_n % m_pisano;
    if (n == 0 || n == 1) return n;
    vector<long long> result(n);
    long long answer = 0;
    long long sum = 2;
    result[0] = 1, result[1] = 1;
    if (n == 2) return result[0] + result[1];
    for(long long int i(2); i < n; ++i) {
        answer = result[i] = result[i - 1] + result[i - 2];
        sum += answer;
    }
    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << FibonacciSumHuge(n);
}
