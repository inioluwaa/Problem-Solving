#include <iostream>
#include <vector>

using namespace std;
/*long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}*/

long long FindPisanoPeriod(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i(0); i < m * m; ++i) {
        a = b, b = c;
        c = (a + b) % m;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long FibonacciHuge(long long n, long long m) {
    long long m_pisano = FindPisanoPeriod(m);
    long long new_n = n % m_pisano;
    if (new_n == 0 || new_n == 1) return new_n;
    vector<int> result(new_n);
    int answer = 0;
    result[0] = 1, result[1] = 1;
    for(int i(2); i < new_n; ++i) {
        answer = result[i] = (result[i - 1] + result[i - 2]) % m;
    }
    if (new_n == 2) return result[1];
    return answer;
}
int main() {
    long long n, m;
    std::cin >> n >> m;
    cout << FibonacciHuge(n, m) << '\n';
}
