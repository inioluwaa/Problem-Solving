#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
enum {RED, WHITE, BLUE} Color;

void DutchFlagPartition(vector<Color> *, int);

int main() {
    vector<Color> u = {BLUE, WHITE, RED, WHITE, WHITE, BLUE, RED, BLUE, RED};
    DutchFlagPartition(&u, 3);
    for (Color i : u) {
        cout << i << " ";
    }
}

void DutchFlagPartition(vector<Color> *A_ptr, int pivot_index) {
    vector<Color> &A = *A_ptr;
    Color pivot = A[pivot_index];
    // First pass: group elements smaller than pivot.
    int smallest = 0;
    for (int i(0); i < A.size(); ++i) {
        if (A[i] < pivot) {
            swap(A[i], A[smallest++]);
        }
    }

    // Second pass: group elements larger than pivot.
    int largest = A.size() - 1;
    for (int i(A.size() - 1); i >= 0 && A[i] >= pivot; --i) {
        if (A[i] > pivot) {
            swap(A[i], A[largest--]);
        }
    }
}