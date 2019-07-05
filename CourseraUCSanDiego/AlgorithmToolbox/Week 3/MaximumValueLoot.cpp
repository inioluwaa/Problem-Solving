#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

using namespace std;

int get_maximum_index(vector<int> weights, vector<int> values) {
    double max = 0, value_per_weight;
    int max_index = -1;
    for (int i(0); i < weights.size(); ++i) {
        value_per_weight = (double) values[i] / weights[i];
        if(weights[i] != 0 && value_per_weight > max) {
            max = value_per_weight;
            max_index = i;
        }
    }
    return max_index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    int size = weights.size(), available_weight;
    for (int i(0); i < size; ++i) {
        if (capacity == 0) return value;
        int index = get_maximum_index(weights, values);
        available_weight = min(weights[index], capacity);
        value = value + (available_weight * (double)values[index] / weights[index]);
        weights[index] -= available_weight, capacity -= available_weight;
    }
    return value;
}

int main() {
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    cout.precision(10);
    cout << optimal_value << std::endl;
    return 0;
}
