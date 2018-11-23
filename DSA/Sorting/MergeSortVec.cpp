#include <iostream>
#include <vector>

using namespace std;

void MergeTwoSortedArrays(vector<int> &, vector<int> &);
void PrintArray(vector<int> &);

int main() {
    vector<int> A {5, 6, 7, 8};
    vector<int> B {1, 2, 3, 4};

    MergeTwoSortedArrays(A, B);

    PrintArray(A);
}

void MergeTwoSortedArrays(vector<int> &A, vector<int> &B) {
    int a = A.size() - 1, b = B.size() - 1, write_idx = A.size() + B.size() - 1;
    while (a >= 0 && b >= 0) {
        A[write_idx--] = A[a] > B[b] ? A[a--] : B[b--];
    }

    while (b >= 0) {
        A[write_idx--] = B[b--];
    }
}

void PrintArray(vector<int> &arr) {
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}