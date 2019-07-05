#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long MaximumPairwiseProduct(const vector<int>& arr);

int main() {
    int n;
    cin >> n;
    vector<int> vector1(n);
    for (int i = 0; i < n; ++i) {
        cin >> vector1[i];
    }
    long long answer = MaximumPairwiseProduct(vector1);
    cout << answer;
}

long long MaximumPairwiseProduct(const vector<int>& arr) {
    int n = arr.size();
    int max_index1 = 0, max_index2 = 0;
    for (int i(1); i < n; ++i) {
        if (arr[i] > arr[max_index1]) {
            max_index1 = i;
        }
    }
    if (max_index1 == 0) {
        max_index2 = 1;
    }
    else {
        max_index2 = 0;
    }
    for (int i(1); i < n; ++i) {
        if (i != max_index1 && arr[i] > arr[max_index2]) {
            max_index2 = i;
        }
    }
    return ((long long)(arr[max_index1])) * arr[max_index2];
}