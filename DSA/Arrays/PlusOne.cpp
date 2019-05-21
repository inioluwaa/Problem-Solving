// Increment an arbitrary-precision integer.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> PlusOne(vector<int>);

int main() {
    vector<int> A {9, 9};
    vector<int> B  = PlusOne(A);
    for (auto i : B) {
        cout << i << " ";
    }
}

// 1, 2, 9 --> 1, 3, 0
vector<int> PlusOne(vector<int> A) {
    ++A.back();
    for (int i = A.size() - 1; i > 0 && A[i] == 10; --i) {
        A[i] = 0, ++A[i - 1];
    }
    if (A[0] == 10) {
        A[0] = 0;
        A.insert(A.begin(), 1);
    }
    // Remove leading zeros.
    A = {find_if_not(begin(A), end(A), [](int a) { return a == 0;}),
         end(A)};
    return A;
}