#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int OutOfOrder(const vector<int> &);

int main() {
    vector<int> u = {5, 4, 3, 2, 1};
    vector<int> v = {2, 4, 1, 3, 5};
    int count = OutOfOrder(u);
    cout << count;
}

// O(n) -- to-do later.
int OutOfOrder2(const vector<int> &A){
    int count  = 0, minumum = numeric_limits<int>::max();
    for (int i(0); i < A.size(); ++i) {
        if ()
    }
}

// O(n^2)
int OutOfOrder(const vector<int> &A) {
    int count = 0;
    for (int i(0); i < A.size() - 1; ++i) {
        for (int j(i + 1); j < A.size(); ++j) {
            if (A[i] > A[j]) {
                ++count;
            }
        }
    }
    return count;
}