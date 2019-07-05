#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int total = 0, increment = 0;
    while (total + increment < n) {
        increment += 1;
        total += increment;
        summands.push_back(increment);
    }

    summands[increment - 1] += n - total;
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
