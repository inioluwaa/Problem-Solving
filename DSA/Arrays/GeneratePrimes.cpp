#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
vector<int> GeneratePrimes(int);
vector<int> GeneratePrimes2(int);
int main() {
    int n = 100;
    vector<int> u = GeneratePrimes2(n);

    for (auto i : u)
        cout << i << " ";
}

// Solution 1.
// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
    vector<int> primes;
    deque<bool> is_prime(n + 1, true);
    // vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p <= n; ++p) {
        if(is_prime[p]) {
            // primes.push_back(p);
            primes.emplace_back(p);
            for (int j = p; j <= n; j += p) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

// Solution 2
// Given n, return all primes up to and including n.
vector<int> GeneratePrimes2(int n) {
    // const int size = floor(n / 2 - 1);
    const int size = floor(0.5 * (n - 3)) + 1;
    vector<int> primes;
    primes.emplace_back(2);
    deque<bool> is_prime(size, true);

    for (int i = 0; i < size; ++i) {
        if (is_prime[i]) {
            int p = (i * 2) + 3;
            primes.emplace_back(p);
            for (int j = ((static_cast<long>(i) * static_cast<long>(i)) * 2) + 6 * i + 3;
                 j < size; j += p) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}
