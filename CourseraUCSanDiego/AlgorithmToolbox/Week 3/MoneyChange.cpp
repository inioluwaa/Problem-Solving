#include <iostream>
#include <vector>

using namespace std;

int get_change(int m) {
    if (m == 0) return 0;
    vector<int> coins = {1, 5, 10};

    int n = 0, mod;

    for (int i(coins.size() - 1); i >= 0; --i) {
        mod = m % coins[i];
        n += (m - mod) / coins[i];
        m = mod;
    }
    return n;
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
