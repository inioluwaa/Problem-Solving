#include <iostream>
#include <vector>
using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int FibonacciLastDigit(int n) {
    if (n <= 1) return n;
    if (n == 2) return 1;
    int answer = 0;
    vector<int> result(n);
    result[0] = 1, result[1] = 1;
    for (int i(2); i < n; ++i) {
        answer = result[i] = (result[i - 1] + result[i - 2]) % 10;
    }
    return answer;
}

int main() {
    int n;
    std::cin >> n;
    int c = FibonacciLastDigit(n);
    std::cout << c << '\n';
}
